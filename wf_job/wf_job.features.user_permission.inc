<?php
/**
 * @file
 * wf_job.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function wf_job_user_default_permissions() {
  $permissions = array();

  // Exported permission: access jobs.
  $permissions['access jobs'] = array(
    'name' => 'access jobs',
    'roles' => array(
      'admin' => 'admin',
      'editor' => 'editor',
    ),
    'module' => 'wf_job',
  );

  // Exported permission: administer jobs.
  $permissions['administer jobs'] = array(
    'name' => 'administer jobs',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'wf_job',
  );

  // Exported permission: delete jobs.
  $permissions['delete jobs'] = array(
    'name' => 'delete jobs',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'wf_job',
  );

  // Exported permission: deploy jobs.
  $permissions['deploy jobs'] = array(
    'name' => 'deploy jobs',
    'roles' => array(
      'deployer' => 'deployer',
    ),
    'module' => 'wf_job',
  );

  // Exported permission: manage jobs.
  $permissions['manage jobs'] = array(
    'name' => 'manage jobs',
    'roles' => array(
      'admin' => 'admin',
      'editor' => 'editor',
    ),
    'module' => 'wf_job',
  );

  // Exported permission: review others jobs.
  $permissions['review others jobs'] = array(
    'name' => 'review others jobs',
    'roles' => array(
      'admin' => 'admin',
      'reviewer' => 'reviewer',
    ),
    'module' => 'wf_job',
  );

  // Exported permission: review own jobs.
  $permissions['review own jobs'] = array(
    'name' => 'review own jobs',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'wf_job',
  );

  return $permissions;
}
