<?php
/**
 * @file
 * wf_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function wf_user_user_default_roles() {
  $roles = array();

  // Exported role: admin.
  $roles['admin'] = array(
    'name' => 'admin',
    'weight' => 2,
  );

  // Exported role: deployer.
  $roles['deployer'] = array(
    'name' => 'deployer',
    'weight' => 6,
  );

  // Exported role: developer.
  $roles['developer'] = array(
    'name' => 'developer',
    'weight' => 5,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  // Exported role: reviewer.
  $roles['reviewer'] = array(
    'name' => 'reviewer',
    'weight' => 4,
  );

  return $roles;
}
