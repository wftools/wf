<?php

/**
 * @file
 * Workflow job status admin functions.
 */

/**
 * Generates the wf job status edit form.
 */
function wf_job_status_form($form, &$form_state, $job_status, $op = 'edit') {

  if ($op == 'clone') {
    $job_status->status .= ' (cloned)';
    $machine_name = str_replace(' ', '_', $job_status->system_status);
    $job_status->machine_name .= $machine_name . '_clone';
  }

  $form['status'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => !empty($job_status->status) ? $job_status->status : '',
  );

  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($job_status->machine_name) ? $job_status->machine_name : '',
    '#disabled' => empty($job_status->is_new),
    '#machine_name' => array(
      'exists' => 'wf_job_status_exists',
      'source' => array('status'),
    ),
    '#description' => t('A unique machine-readable name for this job status. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $system_statuses = wf_job_system_status_list();
  array_unshift($system_statuses, '');
  $form['system_status'] = array(
    '#type' => 'select',
    '#title' => t('System Status'),
    '#required' => TRUE,
    '#options' => array_combine($system_statuses, $system_statuses),
    '#default_value' => isset($job_status->system_status) ? $job_status->system_status : '',
    '#description' => t('The current system status.'),
   );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save job status'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function wf_job_status_form_submit(&$form, &$form_state) {
  $job_status = entity_ui_form_submit_build_entity($form, $form_state);
  $job_status->save();

  $form_state['redirect'] = 'admin/structure/job-statuses';
}
