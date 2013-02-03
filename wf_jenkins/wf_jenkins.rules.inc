<?php
/**
 * Implements hook_rules_event_info().
 */
function wf_jenkins_rules_event_info() {
  $defaults = array(
    'group' => t('Jenkins'),
    'module' => 'wf_jenkins',
    'access callback' => 'wf_jenkins_rules_integration_access',
  );

  $default_variables = array(
    'job' => array('type' => 'wf_job', 'label' => t('The job affected')),
    'environment' => array('type' => 'wf_environment', 'label' => t('The job\'s current environment')),
    'owner' => array('type' => 'user', 'label' => t('The owner of the job')),
    'assigned' => array('type' => 'user', 'label' => t('The user assigned the job')),
  );

  return array(
    'wf_jenkins_updated_code' => $defaults + array(
      'label' => t('After a job\'s code has been updated.'),
      'variables' => $default_variables,
    ),
    'wf_jenkins_start_update_code' => $defaults + array(
      'label' => t('When a code update is started for a job.'),
      'variables' => $default_variables,
    ),
  );
}

/**
 * Access callback for wf_jenkins rules integration.
 */
function wf_jenkins_rules_integration_access($type, $name) {
  return user_access('administer jenkins requests');
}
