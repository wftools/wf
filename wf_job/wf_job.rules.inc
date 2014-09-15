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
    'owner' => array('type' => 'user', 'label' => t('The owner of the job')),
    'assigned' => array('type' => 'user', 'label' => t('The user assigned the job')),
  );

  return array(
    'wf_job_started_failed' => $defaults + array(
      'label' => t('When a job started failed'),
      'variables' => array(
        'job' => array('type' => 'wf_job', 'label' => t('The job affected')),
        'sites' => array('type' => 'wf_site', 'label' => t('The site affected')),
      ),
    ),
    'wf_job_started' => $defaults + array(
      'label' => t('After a job is started'),
      'variables' => $default_variables,
    ),
    'wf_job_returned_to_dev' => $defaults + array(
      'label' => t('After a job is returned to dev'),
      'variables' => $default_variables,
    ),
    'wf_job_reassigned' => $defaults + array(
      'label' => t('After a job is reassigned'),
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
      'variables' => $default_variables + array('sites' => array('type' => 'wf_site', 'label' => t('The site affected'))),
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
    'wf_job_sandbox_built' => $defaults + array(
      'label' => t('After a job sandbox is created'),
      'variables' => array('job' => array('type' => 'wf_job', 'label' => t('The job affected'))),
    ),
    'wf_job_sandbox_fail' => $defaults + array(
      'label' => t('After a job sandbox is fails to be created'),
      'variables' => array('job' => array('type' => 'wf_job', 'label' => t('The job affected'))),
    ),
    'wf_job_updated_code_fail' => $defaults + array(
      'label' => t("After a job's code has failed to update."),
      'variables' => array('job' => array('type' => 'wf_job', 'label' => t('The job affected'))),
    ),
  );
}

/**
 * Implements hook_rules_action_info().
 */
function wf_job_rules_action_info() {
  $actions = array();

  $actions['wf_job_update_status'] = array(
    'group' => t('Workflow Job'),
    'label' => t('Update job status'),
    'base' => 'wf_job_update_status',
    'parameter' => array(
      'job' => array(
        'type' => 'wf_job',
        'label' => t('Job'),
      ),
      'status' => array(
        'type' => 'text',
        'options list' => 'wf_job_machine_name_status_list',
        'label' => t('New status'),
      ),
    ),
  );

  $actions['wf_job_update_environment'] = array(
    'group' => t('Workflow Job'),
    'label' => t('Update job environment'),
    'base' => 'wf_job_update_environment',
    'parameter' => array(
      'job' => array(
        'type' => 'wf_job',
        'label' => t('Job'),
      ),
      'status' => array(
        'type' => 'integer',
        'options list' => 'wf_environment_list_names',
        'label' => t('New environment'),
      ),
    ),
  );

  return $actions;
}

/**
 * Access callback for wf_job rules integration.
 */
function wf_job_rules_integration_access($type, $name) {
  return user_access('administer jobs');
}
