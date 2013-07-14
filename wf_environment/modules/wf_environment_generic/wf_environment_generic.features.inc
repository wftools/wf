<?php
/**
 * @file
 * wf_environment_generic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wf_environment_generic_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function wf_environment_generic_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_wf_environment_bundle().
 */
function wf_environment_generic_default_wf_environment_bundle() {
  $items = array();
  $items['generic'] = entity_import('wf_environment_bundle', '{ "bundle" : "generic", "label" : "Generic Environment" }');
  return $items;
}
