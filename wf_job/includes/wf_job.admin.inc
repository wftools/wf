<?php

/**
 * @file
 * Workflow job admin functions.
 */

/**
 * Generates the wf job bundle edit form.
 */
function wf_job_bundle_form($form, &$form_state, $job_bundle, $op = 'edit') {

  if ($op == 'clone') {
    $job_bundle->label .= ' (cloned)';
    $job_bundle->bundle .= '_clone';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => !empty($job_bundle->label) ? $job_bundle->label : '',
  );

  $form['bundle'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($job_bundle->bundle) ? $job_bundle->bundle : '',
    '#disabled' => empty($job_bundle->is_new),
    '#machine_name' => array(
      'exists' => 'wf_job_bundle_exists',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this job type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save job type'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function wf_job_bundle_form_submit(&$form, &$form_state) {
  $job_bundle = entity_ui_form_submit_build_entity($form, $form_state);
  $job_bundle->save();
  $form_state['redirect'] = 'admin/structure/job-types';
}

/**
 * Start a job form.
 */
function wf_job_action_start_form($form, &$form_state, $job) {
  drupal_set_title(t('Start') . ': ' . entity_label('wf_job', $job));

  $user_entity = entity_load_single('user', $GLOBALS['user']->uid);

  $form['log'] = array(
    '#type' => 'value',
    '#value' => t('Job started by @user', array('@user' => $user_entity->realname)),
  );

  $form['actions'] = array(
    '#weight' => 99,
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Start job'),
  );

  return $form;
}

/**
 * Form submit handler for wf_job_action_start_form.
 */
function wf_job_action_start_form_submit($form, &$form_state) {
  $job = reset($form_state['build_info']['args']);

  $job->revision = TRUE;
  $job->log = filter_xss($form_state['values']['log']['value']);
  $job->rules_event = 'started';
  $job->setStatusName('Started');
  wf_job_save($job);

  $form_state['redirect'] = $job->uri();
}

/**
 * Propose a job form.
 */
function wf_job_action_propose_form($form, &$form_state, $job) {
  drupal_set_title(wf_job_action_title($job, 'propose'));

  $job_uri = $job->uri();
  $form['job'] = array(
    '#type' => 'item',
    '#title' => t('Job being proposed'),
    '#markup' => l($job->label(), reset($job_uri)),
  );

  $env = wf_environment_load($job->eid);
  $next_env = wf_environment_load($env->next_env_id);
  $next_env_uri = $next_env->uri();
  $form['env'] = array(
    '#type' => 'item',
    '#title' => t('Target environment'),
    '#markup' => l($next_env->label(), reset($next_env_uri)),
  );

  global $user;
  $reviewers = wf_job_users('review others jobs');
  if (!user_access('review own jobs') && isset($reviewers[$user->uid])) {
    unset($reviewers[$user->uid]);
  }

  $form['reviewer'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => t('Reviewer'),
    '#options' => $reviewers,
    '#description' => t('Choose the person who will review this job.'),
  );

  $form['log'] = array(
    '#title' => t('Comment'),
    '#type' => 'text_format',
    '#required' => TRUE,
    '#description' => t('Please make a comment.'),
  );

  $form['actions'] = array(
    '#weight' => 99,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Propose for @env', array('@env' => $next_env->label())),
  );

  return $form;
}

/**
 * Form validate handler for wf_job_action_propose_form.
 */
function wf_job_action_propose_form_validate($form, &$form_state) {
  global $user;
  if (!user_access('review own jobs') && $form_state['values']['reviewer'] == $user->uid) {
    form_set_error('reviewer', t('You are not allowed to review your own jobs'));
  }
}

/**
 * Form submit handler for wf_job_action_propose_form.
 */
function wf_job_action_propose_form_submit($form, &$form_state) {
  $job = reset($form_state['build_info']['args']);
  $env = wf_environment_load($job->eid);
  $next_env = wf_environment_load($env->next_env_id);

  $job->revision = TRUE;
  $job->log = filter_xss($form_state['values']['log']['value']);
  $job->assigned = $form_state['values']['reviewer'];
  $job->rules_event = 'proposed';
  $job->setStatusName('In Review');
  wf_job_save($job);

  $form_state['redirect'] = $job->uri();
}

/**
 * Review a job form.
 */
function wf_job_action_review_form($form, &$form_state, $job) {
  $env = wf_environment_load($job->eid);
  $next_env = wf_environment_load($env->next_env_id);

  drupal_set_title(t('Review job proposed for @env', array('@env' => $next_env->label())));

  $form['job'] = array(
    '#type' => 'item',
    '#title' => t('Job being proposed'),
    '#markup' => l($job->label(), reset($job->uri())),
  );

  $form['env'] = array(
    '#type' => 'item',
    '#title' => t('Target environment'),
    '#markup' => l($next_env->label(), reset($next_env->uri())),
  );

  $form['log'] = array(
    '#title' => t('Comment'),
    '#type' => 'text_format',
    '#required' => TRUE,
    '#description' => t('Please make a comment.'),
  );

  $form['actions'] = array(
    '#weight' => 99,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Approve for @env', array('@env' => $next_env->label())),
  );

  $form['actions']['reject'] = array(
    '#type' => 'submit',
    '#value' => t('Reject Job'),
    '#weight' => 6,
  );

  return $form;
}

/**
 * Form submit handler for wf_job_action_review_form.
 */
function wf_job_action_review_form_submit($form, &$form_state) {
  $job = reset($form_state['build_info']['args']);
  if (strpos($form_state['values']['op'], t('Approve for')) === 0) {
    $new_status = 'Approved';
    $event = 'approved';
  }
  else {
    $new_status = 'Started';
    $event = 'rejected';
  }

  $env = wf_environment_load($job->eid);
  $next_env = wf_environment_load($env->next_env_id);

  $job->revision = TRUE;
  $job->log = filter_xss($form_state['values']['log']['value']);
  $job->assigned = $job->owner;
  $job->rules_event = $event;
  $job->setStatusName($new_status);
  wf_job_save($job);

  $form_state['redirect'] = $job->uri();
}

/**
 * Admin settings form.
 */
function wf_job_admin_settings() {
  $form = array();

  $form['wf_job_jsid_new'] = array(
    '#type' => 'select',
    '#title' => t('Job Status New'),
    '#description' => t('The new status of the job.'),
    '#default_value' => variable_get('wf_job_jsid_new'),
    '#options' => wf_job_status_list(),
    '#required' => FALSE,
  );

  $form['wf_job_jsid_completed'] = array(
    '#type' => 'select',
    '#title' => t('Job Status Completed'),
    '#description' => t('The completed status of the job.'),
    '#default_value' => variable_get('wf_job_jsid_completed'),
    '#options' => wf_job_status_list(),
    '#required' => FALSE,
  );

  $form['wf_job_slug_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('Slug Pattern'),
    '#description' => t('The slug pattern of the job. Must contain @jid.'),
    '#default_value' => variable_get('wf_job_slug_pattern'),
    '#required' => FALSE,
  );

  $form['wf_job_visit_plugin'] = array(
    '#type' => 'select',
    '#title' => t('Job Visit Plugin'),
    '#description' => t('The visit plugin of the job.'),
    '#default_value' => variable_get('wf_job_visit_plugin'),
    '#options' => wf_job_get_plugins_list('url_visit'),
    '#required' => FALSE,
  );

  $form['wf_job_login_plugin'] = array(
    '#type' => 'select',
    '#title' => t('Job Login Plugin'),
    '#description' => t('The login plugin of the job.'),
    '#default_value' => variable_get('wf_job_login_plugin'),
    '#options' => wf_job_get_plugins_list('url_login'),
    '#required' => FALSE,
  );

  $form['#validate'][] = 'wf_job_admin_settings_validate';

  return system_settings_form($form);
}

/**
 * Handler the admin settings form validate.
 */
function wf_job_admin_settings_validate($form, &$form_state) {
  $values = $form_state['values'];

  if (isset($values['wf_job_jsid_new']) && isset($values['wf_job_jsid_completed'])) {
    if ($values['wf_job_jsid_new'] === $values['wf_job_jsid_completed']) {
      form_set_error('wf_job_jsid_completed', t('The status completed can\'t use the same value as new.'));
    }
  }

  if (strpos($values['wf_job_slug_pattern'], '@jid') === FALSE) {
    form_set_error('wf_job_slug_pattern', t('The Slug Pattern field must contain @jid pattern.'));
  }
}
