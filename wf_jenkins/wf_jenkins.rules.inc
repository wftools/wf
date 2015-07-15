<?php

/**
 * @file
 * WF Jenkins rules functions.
 */

/**
 * Implements hook_rules_action_info().
 */
function wf_jenkins_rules_action_info() {
  $actions = array();

  $actions['wf_jenkins_set_build'] = array(
    'group' => t('WF Jenkins'),
    'label' => t('Record a Jenkins build against WF job'),
    'parameter' => array(
      'jid' => array(
        'type' => 'integer',
        'label' => t('WF Job ID'),
      ),
      'job' => array(
        'type' => 'text',
        'label' => t('Jenkins job name'),
      ),
      'qid' => array(
        'type' => 'integer',
        'label' => t('Jenkins Build Queue ID'),
      ),
    ),
  );

  $actions['wf_jenkins_unset_build'] = array(
    'group' => t('WF Jenkins'),
    'label' => t('Remove Jenkins build information from WF job'),
    'parameter' => array(
      'jid' => array(
        'type' => 'integer',
        'label' => t('WF Job ID'),
      ),
    ),
  );

  return $actions;
}
