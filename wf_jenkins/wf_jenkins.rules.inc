<?php
/**
 * @file
 * Workflow jenkins rules.
 */

/**
 * Implements hook_rules_action_info().
 */
function wf_jenkins_rules_action_info() {
  return array(
    'wf_jenkins_update_code_submit' => array(
      'label' => t('Update code for given job using Jenkins.'),
      'group' => t('WF Jenkins'),
      'parameter' => array(
        'job' => array(
          'type' => 'wf_job',
          'label' => 'Job',
        ),
      ),
    ),
  );
}
