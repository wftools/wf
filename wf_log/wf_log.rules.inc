<?php
/**
 * @file
 * Rules implementation to wf_log module.
 */

/**
 * Implements hook_rules_action_info().
 */
function wf_log_rules_action_info() {
  return array(
    'create_wf_log_message' => array(
      'label' => t('Create wf log message'),
      'group' => t('Log'),
      'base' => 'wf_log_create_log_message',
      'parameter' => array(
        'entity' => array(
          'type' => 'entity',
          'label' => t('Entity'),
        ),
        'log_bundle' => array(
          'type' => 'token',
          'restriction' => 'input',
          'label' => t('Log Bundle'),
          'description' => t('Select the Log Bundle related.'),
          'options list' => 'wf_log_rules_parameter_bundle_list',
        ),
        'message_type' => array(
          'type' => 'token',
          'label' => t('Message type'),
          'restriction' => 'input',
          'description' => t('Select the type of the message related to log entry.'),
          'options list' => 'wf_log_rules_parameter_message_type_list',
        ),
        'message_body' => array(
          'type' => 'text',
          'restriction' => 'input',
          'label' => t('Message body'),
          'description' => t('Select the body of the message related to log entry.'),
        ),
      ),
    ),
  );
}

/**
 * Returns the log bundle list in rules action parameter format.
 *
 * @return array
 *   Array containing bundle machine name as key and value.
 */
function wf_log_rules_parameter_bundle_list() {
  $log_bundles = array_keys(wf_log_load_bundles());

  $bundle_list = array();
  foreach ($log_bundles as $bundle) {
    $bundle_list[$bundle] = $bundle;
  }

  return $bundle_list;
}

/**
 * Returns the message type list in rules action parameter format.
 *
 * @return array
 *   Array containing machine name as key and title as value.
 */
function wf_log_rules_parameter_message_type_list() {
  $logs_info = wf_log_get_logs_info();

  $message_list = array();
  foreach ($logs_info as $machine_name => $info) {
    $message_list[$machine_name] = $info['title'];
  }

  return $message_list;
}
