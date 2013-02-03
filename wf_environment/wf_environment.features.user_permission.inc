<?php
/**
 * @file
 * wf_environment.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function wf_environment_user_default_permissions() {
  $permissions = array();

  // Exported permission: access environments.
  $permissions['access environments'] = array(
    'name' => 'access environments',
    'roles' => array(
      0 => 'admin',
      1 => 'deployer',
      2 => 'editor',
    ),
    'module' => 'wf_environment',
  );

  // Exported permission: administer environments.
  $permissions['administer environments'] = array(
    'name' => 'administer environments',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'wf_environment',
  );

  // Exported permission: manage environments.
  $permissions['manage environments'] = array(
    'name' => 'manage environments',
    'roles' => array(
      0 => 'admin',
      1 => 'deployer',
    ),
    'module' => 'wf_environment',
  );

  return $permissions;
}
