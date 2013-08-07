<?php
/**
 * @file
 * Workflow job rules.
 */

/**
 * Implements hook_rules_event_info().
 */
function wf_job_rules_event_info() {
  $defaults = array(
    'group' => t('Workflow Job'),
    'module' => 'wf_job',
    'access callback' => 'wf_job_rules_integration_access',
  );

  $default_variables = array(
    'job' => array('type' => 'wf_job', 'label' => t('The job affected')),
    'environment' => array('type' => 'wf_environment', 'label' => t('The job\'s current environment')),
    'next_environment' => array('type' => 'wf_environment', 'label' => t('The job\'s next environment or NULL')),
    'reply' => array('type' => 'reply', 'label' => t('A comment on change')),
    'owner' => array('type' => 'user', 'label' => t('The owner of the job')),
    'assigned' => array('type' => 'user', 'label' => t('The user assigned the job')),
  );

  return array(
    'wf_job_started' => $defaults + array(
      'label' => t('After a job is started'),
      'variables' => $default_variables,
    ),
    'wf_job_proposed' => $defaults + array(
      'label' => t('After a job is proposed for review'),
      'variables' => $default_variables,
    ),
    'wf_job_approved' => $defaults + array(
      'label' => t('After a job is approved'),
      'variables' => $default_variables,
    ),
    'wf_job_rejected' => $defaults + array(
      'label' => t('After a job is rejected'),
      'variables' => $default_variables,
    ),
    'wf_job_deployed' => $defaults + array(
      'label' => t('After a job is deployed to a new environment'),
      'variables' => $default_variables,
    ),
    'wf_job_deployment_failed' => $defaults + array(
      'label' => t('After a job\'s deployment to a new environment fails'),
      'variables' => $default_variables,
    ),
    'wf_job_completed' => $defaults + array(
      'label' => t('After a job is deployed to the final environment'),
      'variables' => $default_variables,
    ),
    'wf_job_update_code_submit' => $defaults + array(
      'label' => t('When a user clicks the Update code button.'),
      'variables' => array('job' => array('type' => 'wf_job', 'label' => t('The job affected'))),
    ),
    'wf_job_start_update_code' => $defaults + array(
      'label' => t('When a code update is started for a job.'),
      'variables' => array('job' => array('type' => 'wf_job', 'label' => t('The job affected'))),
    ),
    'wf_job_updated_code' => $defaults + array(
      'label' => t('After a job\'s code has been updated.'),
      'variables' => array('job' => array('type' => 'wf_job', 'label' => t('The job affected'))),
    ),
  );
}

/**
 * Access callback for wf_job rules integration.
 */
function wf_job_rules_integration_access($type, $name) {
  return user_access('administer jobs');
}
