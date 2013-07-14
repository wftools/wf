<?php
/**
 * @file
 * wf_job_generic.features.inc
 */

/**
 * Implements hook_views_api().
 */
function wf_job_generic_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_reply_type().
 */
function wf_job_generic_default_reply_type() {
  $items = array();
  $items['job_comments'] = entity_import('reply_type', '{
    "bundle" : "job_comments",
    "name" : "Job Comments",
    "access" : "2",
    "display" : "2",
    "description" : "Comments about a job.",
    "form" : "1",
    "allow_reply" : "1",
    "locked" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_wf_job_bundle().
 */
function wf_job_generic_default_wf_job_bundle() {
  $items = array();
  $items['job'] = entity_import('wf_job_bundle', '{ "bundle" : "job", "label" : "Generic Job" }');
  return $items;
}
