<?php
/**
 * @file
 * wf_git_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wf_git_config_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_git_repository().
 */
function wf_git_config_default_git_repository() {
  $items = array();
  $items['1'] = entity_import('git_repository', '{
    "bundle" : "repository",
    "name" : "www",
    "title" : "Website",
    "server_name" : "gitolite",
    "log" : null,
    "rid" : "1",
    "module" : "wf_git_config"
  }');
  return $items;
}

/**
 * Implements hook_default_git_server().
 */
function wf_git_config_default_git_server() {
  $items = array();
  $items['1'] = entity_import('git_server', '{
    "name" : "gitolite",
    "title" : "Gitolite",
    "log" : null,
    "sid" : "1",
    "bundle" : "gitolite",
    "user" : "git",
    "host" : "localhost",
    "module" : "wf_git_config",
    "field_admin_users" : { "und" : [
        {
          "value" : "admin",
          "format" : null,
          "safe_value" : "admin"
        },
        { "value" : "jenkins", "format" : null, "safe_value" : "jenkins" }
      ]
    }
  }');
  return $items;
}
