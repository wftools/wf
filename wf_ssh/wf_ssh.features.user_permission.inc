<?php
/**
 * @file
 * wf_ssh.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function wf_ssh_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer SSH public keys.
  $permissions['administer SSH public keys'] = array(
    'name' => 'administer SSH public keys',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'sshkey',
  );

  // Exported permission: administer ssh.
  $permissions['administer ssh'] = array(
    'name' => 'administer ssh',
    'roles' => array(
      'admin' => 'admin',
      'editor' => 'editor',
    ),
    'module' => 'sshid',
  );

  // Exported permission: manage any SSH public keys.
  $permissions['manage any SSH public keys'] = array(
    'name' => 'manage any SSH public keys',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'sshkey',
  );

  // Exported permission: manage own SSH public keys.
  $permissions['manage own SSH public keys'] = array(
    'name' => 'manage own SSH public keys',
    'roles' => array(
      'admin' => 'admin',
      'editor' => 'editor',
    ),
    'module' => 'sshkey',
  );

  // Exported permission: upload private ssh key.
  $permissions['upload private ssh key'] = array(
    'name' => 'upload private ssh key',
    'roles' => array(
      'admin' => 'admin',
      'editor' => 'editor',
    ),
    'module' => 'sshid',
  );

  // Exported permission: use ssh.
  $permissions['use ssh'] = array(
    'name' => 'use ssh',
    'roles' => array(
      'admin' => 'admin',
      'editor' => 'editor',
    ),
    'module' => 'sshid',
  );

  // Exported permission: view any SSH public keys.
  $permissions['view any SSH public keys'] = array(
    'name' => 'view any SSH public keys',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'sshkey',
  );

  // Exported permission: view own SSH public keys.
  $permissions['view own SSH public keys'] = array(
    'name' => 'view own SSH public keys',
    'roles' => array(
      'admin' => 'admin',
      'editor' => 'editor',
    ),
    'module' => 'sshkey',
  );

  return $permissions;
}
