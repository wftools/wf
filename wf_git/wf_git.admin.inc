<?php
/**
 * @file
 *  Workflow git admin pages
 */

/**
 * Settings form for workflow git module.
 */ 
function wf_git_settings_form($form, &$form_state) {
  $git_repos = entity_load('git_repository');
  $repos = array();

  foreach ($git_repos as $repo) {
    $server = $repo->server();
    $repos[$server->label()][$repo->rid] = $repo->label();
  }

  $form['wf_git_diff'] = array(
    '#type' => 'fieldset',
    '#title' => t('Git diff settings'),
    'wf_git_diff_repository' => array(
      '#type' => 'select',
      '#title' => t('Gitolite repository'),
      '#options' => $repos,
      '#default_value' => variable_get('wf_git_diff_repository', NULL),
      '#description' => t('Select the git repository you would like to use for diffs.')
    ),
    'wf_git_diff_path' => array(
      '#type' => 'textfield',
      '#title' => 'Diff path',
      '#default_value' => variable_get('wf_git_diff_path', 'branches/master...@branch'),
      '#description' => t('The token @branch will be replaced with the branch being diffed.'),
    ),
    'wf_git_diff_secure' => array(
      '#type' => 'checkbox',
      '#title' => 'Use HTTPS',
      '#default_value' => variable_get('wf_git_diff_secure', FALSE),
      '#description' => t('Check if HTTPS must be used when browsing the git repository.'),
    ),
  );

  return system_settings_form($form);
}
