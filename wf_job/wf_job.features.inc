<?php
/**
 * @file
 * wf_job.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wf_job_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function wf_job_views_api() {
  return array("api" => "3.0");
}
