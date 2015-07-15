<?php

/**
 * @file
 * WF Job API functions.
 */

/**
 * Alter a list of bundles to be displayed on the list page.
 *
 * @param array $bundles
 *   List of bundles to modify.
 */
function hook_wf_job_add_list_alter(array $bundles) {
  foreach ($bundles as $name => &$bundle) {
    if ('hidden' == $name) {
      unset($bundles[$name]);
      break;
    }
  }
}

/**
 * Alter the title for a wf job edit form page.
 *
 * @param string $title
 *   The default page title.
 * @param WFJob $job
 *   The WF Job to be edited.
 */
function hook_wf_job_edit_title_alter(&$title, $job) {

  if (!$job->jid) {
    return;
  }

  $params = array(
    '@jid' => $job->jid,
    '@label' => entity_label('wf_job', $job),
  );

  $title = t('Edit job #@jid: @label', $params);
}
