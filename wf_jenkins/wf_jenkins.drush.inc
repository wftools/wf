<?php
/**
 * @file
 *  Drush command for Workflow Jenkins
 */

/**
 * Implements hook_drush_command().
 */
function wf_jenkins_drush_command() {
  $items = array();
  
  $items['jenkins-updated-code'] = array(
    'description' => dt('Informs Drupal that Jenkins has updated the code for a given job'),
    'examples' => array(
      'drush jenkins-updated-code <jid> --succeeded=1' => dt('Informs Drupal that Jenkins has successfully updated the code for the job with <jid>'),
      'drush jenkins-updated-code <jid> --succeeded=0' => dt('Informs Drupal that Jenkins has failed to update the code for the job with <jid>'),
    ),
    'options' => array(
      'succeeded' => dt('Do not include the php open tag'),
    ),
  );

  return $items;
}

/**
 * Callback for jenkins-update-code command.
 */
function drush_wf_jenkins_jenkins_updated_code($jid) {
  $succeeded = (bool) drush_get_option('succeeded', TRUE);
  $job = wf_job_load($jid);
  wf_jenkins_updated_code($job, $succeeded);
}
