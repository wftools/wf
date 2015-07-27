<?php

/**
 * @file
 * WF Log management page functions.
 */

/**
 * Log add menu callback.
 */
function wf_log_add($bundle) {
  $info = array('bundle' => $bundle);
  $log = entity_create('wf_log', $info);

  return drupal_get_form('wf_log_admin_form', $log);
}

/**
 * Form for deleting Logs.
 */
function wf_log_delete_form($form, $form_state, $log) {
  $log_uri = entity_uri('wf_log', $log);
  $title = entity_label('wf_log', $log);
  return confirm_form(
    $form,
    t("Are you sure you want to delete <strong>@title</strong>?", array('@title' => $title)),
    $log_uri['path'] . '/view',
    t("Deleting this log will trigger the deletion of all associated resources and cannot be undone."),
    t("Delete")
  );
}

/**
 * Submit handler wf_log_delete_form.
 */
function wf_log_delete_form_submit($form, &$form_state) {
  $log = reset($form_state['build_info']['args']);
  $title = entity_label('wf_log', $log);
  entity_delete('wf_log', $log->lid);
  drupal_set_message(t("Log '@title' was successfully deleted.", array('@title' => $title)));
  $form_state['redirect'] = url(WF_LOG_LIST_URL);
}

/**
 * Form for editing Logs.
 */
function wf_log_admin_form($form, $form_state, $log) {
  $form = array();

  $form['lid'] = array(
    '#type' => 'value',
    '#value' => $log->lid,
  );

  $form['created'] = array(
    '#type' => 'value',
    '#value' => !(isset($log->created)) ? REQUEST_TIME : $log->created,
  );

  $form['bundle'] = array(
    '#type' => 'value',
    '#value' => $log->bundle,
  );

  $form['entity_type'] = array(
    '#type' => 'select',
    '#title' => t('Entity type'),
    '#options' => wf_log_entity_types_list(),
    '#default_value' => $log->entity_type,
    '#description' => t('Select the related entity type to this Log entry.'),
    '#required' => TRUE,
  );

  $form['entity'] = array(
    '#type' => 'textfield',
    '#title' => t('Entity ID'),
    '#default_value' => $log->entity,
    '#description' => t('Insert the entity ID related to this log entry.'),
    '#required' => TRUE,
  );

  $form['message_type'] = array(
    '#type' => 'select',
    '#title' => t('Message type'),
    '#options' => wf_log_actions_list(),
    '#default_value' => $log->message_type,
    '#description' => t('Select the related message type of this Log entry.'),
    '#required' => TRUE,
  );

  $form['uid'] = array(
    '#type' => 'textfield',
    '#title' => t('Owner'),
    '#default_value' => !is_null($log->uid) ? wf_log_get_user_name_by_id($log->uid) : '',
    '#description' => t('Select the owner of this entry Log.'),
    '#autocomplete_path' => 'user/autocomplete',
    '#required' => TRUE,
  );

  $form['message_summary'] = array(
    '#title' => t('Message summary'),
    '#type' => 'textfield',
    '#description' => t('Enter a brief text describing this Log. Maximum 200 characters.'),
    '#default_value' => $log->message_summary,
    '#maxlength' => 200,
    '#required' => TRUE,
  );

  $form['message_body'] = array(
    '#title' => t('Message Body'),
    '#type' => 'textarea',
    '#description' => t('Enter a detailed text describing this Log.'),
    '#default_value' => $log->message_body,
    '#required' => TRUE,
  );

  // Attach custom fields to the form.
  field_attach_form('wf_log', $log, $form, $form_state);

  // Save Button.
  $form['actions'] = array('#weight' => 99);
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  // Delete Button.
  if (!empty($log->lid) && user_access('delete wf log entities')) {
    $log_uri = entity_uri('wf_log', $log);
    $form['actions']['delete'] = array(
      '#type' => 'link',
      '#title' => t('Delete'),
      '#href' => $log_uri['path'] . '/delete',
    );
  }

  return $form;
}

/**
 * Log admin form validate callback.
 */
function wf_log_admin_form_validate($form, &$form_state) {
  // Validates if the given user exists.
  $user_name = $form_state['values']['uid'];
  $user = wf_log_get_user_id_by_name($user_name);
  if (!$user) {
    // User doesn't exist.
    $error_message = t('The selected user does not exist.');
    form_set_error('uid', $error_message);
  }

  // Validates if the given entity belongs to the entity type.
  $entity_type = $form_state['values']['entity_type'];
  $entity_id = $form_state['values']['entity'];
  $entity = entity_load_single($entity_type, $entity_id);
  if (!$entity) {
    $error_message = t('Unable to find entity.');
    form_set_error('entity', $error_message);
  }
}

/**
 * Log admin form submit callback.
 */
function wf_log_admin_form_submit($form, &$form_state) {
  $user_name = $form_state['values']['uid'];
  $form_state['values']['uid'] = wf_log_get_user_id_by_name($user_name);
  $log = new WfLog($form_state['values']);
  wf_log_save($log);
  $form_state['redirect'] = $log->uri();
}

/**
 * Fetches a list of actions.
 *
 * @see wf_log_admin_form()
 *
 * @return array
 *   List of actions.
 */
function wf_log_actions_list() {
  $logs_info = wf_log_get_logs_info();

  $select_actions = array();
  foreach ($logs_info as $log_key => $log) {
    $select_actions[$log_key] = $log['title'];
  }

  return $select_actions;
}

/**
 * Fetches a list of entity types.
 *
 * @see wf_log_admin_form()
 *
 * @return array
 *   List of entity types.
 */
function wf_log_entity_types_list() {
  $entity_types = array();
  $entities = entity_get_info();
  foreach ($entities as $entity_type => $entity) {
    if (!empty($entity['bundle of']) || !empty($entity['exportable']) || $entity_type == 'wf_log') {
      continue;
    }
    $entity_types[$entity_type] = $entity['label'];
  }

  asort($entity_types);
  return $entity_types;
}

/**
 * Returns the user ID, giving the user name.
 *
 * @param string $user_name
 *   The given user.
 */
function wf_log_get_user_id_by_name($user_name) {
  $user_id = &drupal_static(__FUNCTION__);

  if (!isset($user_id)) {
    $user = user_load_by_name($user_name);
    $user_id = isset($user->uid) ? $user->uid : NULL;
  }

  return $user_id;
}

/**
 * Returns the user name, giving the user ID.
 *
 * @param string $uid
 *   The given user ID.
 */
function wf_log_get_user_name_by_id($uid) {
  $user = user_load($uid);

  return isset($user->name) ? $user->name : FALSE;
}

/**
 * Generates the wf Log bundle edit form.
 */
function wf_log_bundle_form($form, &$form_state, $log_bundle, $op = 'edit') {
  if ($op == 'clone') {
    $log_bundle->label .= ' (cloned)';
    $log_bundle->bundle .= '_clone';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => !empty($log_bundle->label) ? $log_bundle->label : '',
  );

  $form['bundle'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($log_bundle->bundle) ? $log_bundle->bundle : '',
    '#disabled' => empty($log_bundle->is_new),
    '#machine_name' => array(
      'exists' => 'wf_log_bundle_exists',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this log type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['actions'] = array(
    '#type' => 'actions',
    '#weight' => 99,
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Log type'),
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function wf_log_bundle_form_submit(&$form, &$form_state) {
  $log_bundle = entity_ui_form_submit_build_entity($form, $form_state);
  $log_bundle->save();
  $form_state['redirect'] = 'admin/structure/wf-log-types';
}

/**
 * List Log types that can be created.
 */
function wf_log_page_add() {
  $bundles = wf_log_load_bundles();

  switch (count($bundles)) {
    case 0:
      $create_link = '';
      if (user_access('administer wf log entities')) {
        $create_link = l(t('Create new log type'), 'admin/structure/wf-log-types/add');
      }
      return '<p>' . t('You have not created any Log types yet. ') . $create_link . '</p>';

    case 1:
      $bundle = array_shift($bundles);
      drupal_goto("wf-log/add/{$bundle->bundle}");
      break;

    default:
      return theme('wf_log_add_list', array('content' => $bundles));
  }
}
