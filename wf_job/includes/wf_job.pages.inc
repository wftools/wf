<?php

/**
 * @file
 * Workflow job management page functions.
 */

/**
 * List job types that can be created.
 */
function wf_job_page_add() {
  $bundles = wf_job_load_bundles();

  switch (count($bundles)) {
    case 0:
      return '<p>' . t('You have not created any job types yet.') . '</p>';

    case 1:
      $bundle = array_shift($bundles);
      drupal_goto("job/add/{$bundle->bundle}");
      break;

    default:
      return theme('wf_job_add_list', array('content' => $bundles));
  }
}

/**
 * Job add menu callback.
 */
function wf_job_add($bundle) {
  $info = array('bundle' => $bundle);

  $job = entity_create('wf_job', $info);

  return drupal_get_form('wf_job_edit_form', $job);
}

/**
 * Job edit menu callback.
 */
function wf_job_edit($job = NULL) {
  return drupal_get_form('wf_job_edit_form', $job);
}

/**
 * Job edit form.
 */
function wf_job_edit_form($form, $form_state, $job) {
  // Set some sane default values.
  $is_new = FALSE;
  $status_type = 'select';
  $default_status = $job->jsid;
  $default_owner = $job->owner;
  $default_assigned = $job->assigned;
  $revision = TRUE;
  if (!empty($job->is_new)) {
    $is_new = TRUE;
    $status_type = 'value';
    $default_status = variable_get('wf_job_default_status', 1);
    $default_owner = $GLOBALS['user']->uid;
    $default_assigned = $GLOBALS['user']->uid;
    $revision = FALSE;
  }

  $form = array();

  $form['default_revision'] = array(
    '#type' => 'value',
    '#value' => $job->default_revision,
  );

  $form['bundle'] = array(
    '#type' => 'value',
    '#value' => $job->bundle,
  );

  $form['jid'] = array(
    '#type' => 'value',
    '#value' => $job->jid,
  );

  $form['is_new'] = array(
    '#type' => 'value',
    '#value' => $is_new,
  );

  $form['revision'] = array(
    '#type' => 'value',
    '#value' => $revision,
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Job Name'),
    '#default_value' => $job->title,
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  $form['reference'] = array(
    '#type' => 'textfield',
    '#title' => t('External Reference'),
    '#default_value' => $job->reference,
    '#required' => FALSE,
    '#maxlength' => 50,
  );

  $form['details'] = array(
    '#type' => 'textarea',
    '#title' => t('Details'),
    '#default_value' => $job->details,
    '#required' => TRUE,
  );

  $form['jsid'] = array(
    '#type' => $status_type,
    '#title' => t('Current Status'),
    '#options' => wf_job_status_list(),
    '#default_value' => $default_status,
    '#required' => TRUE,
    '#disabled' => !wf_job_action_allowed($job, 'change_status'),
  );

  $users = wf_job_users();
  $form['owner'] = array(
    '#type' => 'select',
    '#title' => t('Owner'),
    '#options' => $users,
    '#default_value' => $default_owner,
    '#required' => TRUE,
    '#disabled' => !wf_job_action_allowed($job, 'change_owner'),
  );

  $form['assigned'] = array(
    '#type' => 'select',
    '#title' => t('Assigned to'),
    '#options' => $users,
    '#default_value' => $default_assigned,
    '#required' => TRUE,
    '#disabled' => !wf_job_action_allowed($job, 'assign'),
  );

  $envs = wf_environment_list_names();
  $form['eid'] = array(
    '#type' => 'select',
    '#title' => t('Current Environment'),
    '#options' => $envs,
    '#default_value' => $job->eid,
    '#required' => TRUE,
    '#disabled' => !wf_job_action_allowed($job, 'change_environment'),
  );

  field_attach_form('wf_job', $job, $form, $form_state);

  $form['log'] = array(
    '#type' => 'textarea',
    '#title' => t('Log Message'),
    '#default_value' => '',
    '#required' => TRUE,
  );

  // Fix a few things if this is a new job.
  if (!empty($job->is_new)) {
    foreach (array('assigned', 'eid') as $field) {
      $form[$field]['#type'] = 'value';
      $form[$field]['#value'] = $form[$field]['#default_value'];
    }
    $form['log']['#type'] = 'value';
    $form['log']['#value'] =  t('Job created by @user.', array('@user' => $GLOBALS['user']->name));
  }

  $form['actions'] = array('#weight' => 99);

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 5,
  );

  if (!empty($job->is_new)) {
    $form['actions']['create_and_start'] = array(
      '#type' => 'submit',
      '#value' => t('Create and Start'),
    );
  }

  if (!empty($job->jid) && user_access('delete jobs')) {
    $job_uri = entity_uri('wf_job', $job);
    $form['actions']['delete'] = array(
      '#type' => 'link',
      '#title' => t('Delete'),
      '#href' => $job_uri['path'] . '/delete',
      '#weight' => 15,
    );
  }

  return $form;
}

/**
 * Default implementation for accessing a job sandbox.
 */
function wf_job_sandbox_login($job = NULL) {
  $uri = wf_job_sandbox_uri($job);
  drupal_goto($uri['path'], $uri['options']);
}

/**
 * Job edit form validation callback.
 */
function wf_job_edit_form_validate($form, &$form_state) {
  // Hack to set the assigned value to the owner.
  if ($form_state['values']['is_new']) {
    $form_state['values']['assigned'] = $form_state['values']['owner'];
  }

  $ref = $form_state['values']['reference'];
  $existing = wf_job_id_by_reference($ref);
  if (!empty($ref) && !empty($existing['wf_job'])
    && !isset($existing['wf_job'][$form_state['values']['jid']])) {

    $uri = reset(entity_load('wf_job', array_keys($existing['wf_job'])))->uri();
    $link = url($uri['path'], $uri);
    form_set_error('reference', t('Job with reference <a href="!link">@ref</a> already exists.', array('!link' => $link, '@ref' => $ref)));
  }
}

/**
 * Job edit form submit callback.
 */
function wf_job_edit_form_submit($form, &$form_state) {
  $job = new WfJob($form_state['values']);
  wf_job_save($job);
  $form_state['redirect'] = $job->uri();

  if ($form_state['values']['op'] == t('Create and Start')) {
    $job->revision = TRUE;
    $job->log = t('Job started by @user', array('@user' => $GLOBALS['user']->realname));
    $job->rules_event = 'wf_job_started';
    $job->setStatusName('Started');
    wf_job_save($job);
    rules_invoke_event('wf_job_started', $job, $job->eid, $job->eid, $job->owner, $job->assigned);
  }
}

/**
 * Displays a job.
 */
function wf_job_view($job) {
  $out = entity_view('wf_job', array($job));
  if (!is_array($out)) {
    return t('Unable to render job.');
  }

  return reset($out['wf_job']);
}

/**
 * Drush aliases export form.
 */
function wf_job_export_drush_aliases_form($form, $form_state) {
  $form = array(
    'introduction' => array(
      '#type' => 'item',
      '#description' => t('Download wf.aliases.drushrc.php file for all existing jobs'),
    ),
    'download' => array(
      '#type' => 'submit',
      '#value' => t('Download File'),
    ),
  );
  return $form;
}

/**
 * Submit handler for wf_job_export_drush_aliases_form().
 */
function wf_job_export_drush_aliases_form_submit($form, &$form_state) {
  $aliases = wf_job_drush_aliases();
  $php = "<?php\n" . theme('wf_job_drush_aliases', array('aliases' => $aliases));

  $file = new stdClass();
  $file->filename = 'wf.aliases.drushrc.php';
  $file->filemime = 'application/x-php';
  $file->filesize = strlen($php);

  $headers = file_get_content_headers($file);
  drupal_send_headers($headers);

  echo $php;
  exit;
}

/**
 * Form for deleting jobs.
 */
function wf_job_delete_form($form, $form_state, $job) {
  $job_uri = entity_uri('wf_job', $job);
  $title = entity_label('wf_job', $job);
  return confirm_form(
    $form,
    t("Are you sure you want to delete <strong>@title</strong>?", array('@title' => $title)),
    $job_uri['path'] . '/view',
    t("Deleting this job will trigger the deletion of all associated resources and cannot be undone."),
    t("Delete")
  );
}

/**
 * Submit handler wf_job_delete_form.
 */
function wf_job_delete_form_submit($form, &$form_state) {
  $job = reset($form_state['build_info']['args']);
  $title = entity_label('wf_job', $job);
  entity_delete('wf_job', $job->jid);
  drupal_set_message(t("Job '@title' was successfully deleted.", array('@title' => $title)));
  $form_state['redirect'] = url('admin/content/jobs');
}

