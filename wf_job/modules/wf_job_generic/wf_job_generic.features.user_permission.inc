<?php
/**
 * @file
 * wf_job_generic.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function wf_job_generic_user_default_permissions() {
  $permissions = array();

  // Exported permission: delete job_comments reply.
  $permissions['delete job_comments reply'] = array(
    'name' => 'delete job_comments reply',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'reply',
  );

  // Exported permission: delete own job_comments reply.
  $permissions['delete own job_comments reply'] = array(
    'name' => 'delete own job_comments reply',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'reply',
  );

  // Exported permission: edit job_comments reply.
  $permissions['edit job_comments reply'] = array(
    'name' => 'edit job_comments reply',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'reply',
  );

  // Exported permission: edit own job_comments reply.
  $permissions['edit own job_comments reply'] = array(
    'name' => 'edit own job_comments reply',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'reply',
  );

  // Exported permission: post job_comments reply.
  $permissions['post job_comments reply'] = array(
    'name' => 'post job_comments reply',
    'roles' => array(
      0 => 'admin',
      1 => 'editor',
    ),
    'module' => 'reply',
  );

  // Exported permission: view job_comments reply.
  $permissions['view job_comments reply'] = array(
    'name' => 'view job_comments reply',
    'roles' => array(
      0 => 'admin',
      1 => 'editor',
    ),
    'module' => 'reply',
  );

  return $permissions;
}
