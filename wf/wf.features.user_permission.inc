<?php
/**
 * @file
 * wf.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function wf_user_default_permissions() {
  $permissions = array();

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'admin',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: access rules debug.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'rules',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'features',
  );

  // Exported permission: administer replies.
  $permissions['administer replies'] = array(
    'name' => 'administer replies',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'reply',
  );

  // Exported permission: administer reply bundles.
  $permissions['administer reply bundles'] = array(
    'name' => 'administer reply bundles',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'reply',
  );

  // Exported permission: administer rules.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'rules',
  );

  // Exported permission: administer services.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'services',
  );

  // Exported permission: bypass rules access.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'rules',
  );

  // Exported permission: get a system variable.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'services',
  );

  // Exported permission: get any binary files.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'services',
  );

  // Exported permission: get own binary files.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'services',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'features',
  );

  // Exported permission: perform unlimited index queries.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'services',
  );

  // Exported permission: save file information.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'services',
  );

  // Exported permission: set a system variable.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      0 => 'admin',
    ),
    'module' => 'services',
  );

  // Exported permission: use admin toolbar.
  $permissions['use admin toolbar'] = array(
    'name' => 'use admin toolbar',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'admin',
  );

  return $permissions;
}
