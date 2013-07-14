<?php
/**
 * @file
 * wf_git.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function wf_git_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer git repositories.
  $permissions['administer git repositories'] = array(
    'name' => 'administer git repositories',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'git_repository',
  );

  // Exported permission: administer git servers.
  $permissions['administer git servers'] = array(
    'name' => 'administer git servers',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'git_server',
  );

  return $permissions;
}
