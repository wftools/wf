<?php
/**
 * @file
 * wf_git_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function wf_git_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer worklow git.
  $permissions['administer worklow git'] = array(
    'name' => 'administer worklow git',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'wf_git',
  );

  return $permissions;
}
