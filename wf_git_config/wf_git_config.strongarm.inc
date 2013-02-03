<?php
/**
 * @file
 * wf_git_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function wf_git_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wf_git_diff_path';
  $strongarm->value = '?branch=@branch';
  $export['wf_git_diff_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wf_git_diff_repository';
  $strongarm->value = '1';
  $export['wf_git_diff_repository'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'wf_git_diff_secure';
  $strongarm->value = 0;
  $export['wf_git_diff_secure'] = $strongarm;

  return $export;
}
