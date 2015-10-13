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
  $title = t('Edit job #@jid', array('@jid' => $job->jid));
  drupal_alter('wf_job_edit_title', $title, $job);
  drupal_set_title($title);
  return drupal_get_form('wf_job_edit_form', $job);
}

/**
 * Job edit form.
 */
function wf_job_edit_form($form, $form_state, $job) {
  global $user;

  ctools_include('plugins');
  $handler = &drupal_static(__FUNCTION__);
  if (!$handler) {
    $plugin = variable_get('wf_job_acl_plugin', 'standard');
    $class_name = ctools_plugin_load_class('wf_job', 'acl', $plugin, 'handler');
    $handler = new $class_name();
  }

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
    '#disabled' => !wf_job_access('change_status', $job, $user),
  );

  $form['owner'] = array(
    '#type' => 'select',
    '#title' => t('Owner'),
    '#options' => $handler->getOwners($job),
    '#default_value' => $default_owner,
    '#required' => TRUE,
    '#disabled' => !wf_job_access('change_owner', $job, $user),
  );

  $form['assigned'] = array(
    '#type' => 'select',
    '#title' => t('Assigned to'),
    '#options' => $handler->getAssignees($job),
    '#default_value' => $default_assigned,
    '#required' => TRUE,
    '#disabled' => !wf_job_access('assign', $job, $user),
  );

  $envs = wf_environment_list_names();
  $form['eid'] = array(
    '#type' => 'select',
    '#title' => t('Current Environment'),
    '#options' => $envs,
    '#default_value' => $job->eid,
    '#required' => TRUE,
    '#disabled' => !wf_job_access('change_environment', $job, $user),
  );

  field_attach_form('wf_job', $job, $form, $form_state);

  wf_job_attach_log_field_form($form);

  // Fix a few things if this is a new job.
  if (!empty($job->is_new)) {
    foreach (array('assigned', 'eid') as $field) {
      $form[$field]['#type'] = 'value';
      $form[$field]['#value'] = $form[$field]['#default_value'];
    }
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
  if ($form_state['values']['is_new'] && isset($form_state['values']['owner'])) {
    $form_state['values']['assigned'] = $form_state['values']['owner'];
  }

  $references = wf_job_split_references($form_state['values']['reference']);
  if (!empty($references)) {
    wf_job_edit_form_validate_input_duplicate_references($form_state, $references);
    wf_job_edit_form_validate_references_already_exist($form_state, $references);

    // After validation, clean references field values.
    $form_state['values']['reference'] = implode(', ', $references);
  }
}

/**
 * Form validation to check if the form input values has duplicate references.
 */
function wf_job_edit_form_validate_input_duplicate_references($form_state, $references) {
  // Check if has duplicate references.
  $has_duplicates = count(array_unique($references)) < count($references);
  if ($has_duplicates) {
    $duplicate_references = array();

    // Count values.
    $count_values = array_count_values($references);
    foreach ($count_values as $reference => $amount) {
      if ($amount > 1) {
        // List duplicate references.
        $duplicate_references[] = $reference;
      }
    }

    form_set_error('reference', t('You are trying to save duplicate references: @duplicate', array('@duplicate' => implode(', ', $duplicate_references))));
  }
}

/**
 * Form validation to check that given references already exist.
 */
function wf_job_edit_form_validate_references_already_exist($form_state, $references) {
  $jid = $form_state['values']['jid'];
  $existing_references = wf_job_get_jobs_by_references($references);
  $link_list = '';

  foreach ($existing_references as $job_id => $duplicated_references) {
    if ((int) $job_id != (int) $jid) {
      foreach ($duplicated_references as $reference_name) {
        $link_list .= l($reference_name, 'job/' . $job_id) . ', ';
      }
    }
  }

  if (!empty($link_list)) {
    form_set_error('reference', t('Job with reference(s) !link_list already exists.', array('!link_list' => rtrim($link_list, ', '))));
  }
}

/**
 * Job edit form submit callback.
 */
function wf_job_edit_form_submit($form, &$form_state) {
  $job = new WfJob($form_state['values']);
  wf_job_attach_form_log_value_to_entity($job, $form_state, 'wf_job_saved');
  wf_job_save($job);
  $form_state['redirect'] = $job->uri();

  if ($form_state['values']['op'] == t('Create and Start')) {
    $job->revision = TRUE;
    $job->rules_event = 'started';
    wf_job_attach_form_log_value_to_entity($job, $form_state, 'wf_job_started');
    wf_job_save($job);
  }
}

/**
 * Displays a job.
 */
function wf_job_view($job) {
  drupal_set_title($job->title);
  $out = entity_view('wf_job', array($job));
  if (!is_array($out)) {
    return t('Unable to render job.');
  }

  return reset($out['wf_job']);
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

/**
 * Renders a form page containing the Drush integrations.
 */
function wf_job_export_drush_aliases_page($user) {
  $output['drush_aliases'] = array(
    array(
      '#theme' => 'link',
      '#text' => t('Download Drush aliases'),
      '#path' => 'user/jobs/get-drush-aliases',
      '#options' => array(
        'attributes' => array(),
        'html' => FALSE,
      ),
      '#suffix' => t("<p>Download Drush aliases for all of your Jobs's sandboxes and place this file at ~/.drush/  (~/ means your home path)</p>"),
    ),
  );
  return $output;
}

/**
 * Page for exporting drush aliases file.
 */
function wf_job_output_drush_aliases_file() {
  $aliases = wf_job_drush_aliases();
  if (!$aliases) {
    global $user;
    drupal_set_message(t('No jobs available'), 'warning');
    drupal_goto("user/$user->uid/jobs/drush-aliases");
  }
  $php = "<?php\n" . theme('wf_job_drush_aliases', array('aliases' => $aliases));
  $file = new stdClass();
  $file->filename = 'wf.aliases.drushrc.php';
  $file->filemime = 'application/x-php';
  $file->filesize = strlen($php);
  $headers = file_get_content_headers($file);
  // Workaround for: https://www.drupal.org/node/1773032
  $headers['Content-Disposition'] = 'attachment; filename="' . $file->filename . '"';
  drupal_send_headers($headers);
  print $php;
  drupal_exit();
}
