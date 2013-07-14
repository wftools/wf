<?php
/**
 * @file
 * wf_jenkins.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function wf_jenkins_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer jenkins requests.
  $permissions['administer jenkins requests'] = array(
    'name' => 'administer jenkins requests',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'jenkins',
  );

  // Exported permission: update job sandbox code.
  $permissions['update job sandbox code'] = array(
    'name' => 'update job sandbox code',
    'roles' => array(
      'developer' => 'developer',
    ),
    'module' => 'wf_jenkins',
  );

  return $permissions;
}
