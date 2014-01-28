<?php

/**
 * @file
 * Deploy services client output related functions.
 */

/**
 * Page callback to render diffs.
 */
function wf_deploy_services_client_render_entity_diff(WfJob $job) {
  try {
    $remote_config = wf_deploy_services_client_remote_config($job);
    $diffs = wf_deploy_services_client_get_diff($remote_config);
  }
  catch (Exception $e) {
    drupal_set_message(t('Unable to fetch diff.'), 'error');
    return t('Please try again later.');
  }

  $params = array('diffs' => $diffs);

  return theme('wf_deploy_services_client_plan_diff', $params);
}

/**
 * Theme function to render diffs.
 */
function theme_wf_deploy_services_client_plan_diff($variables) {

  $diffs = $variables['diffs'];
  $remote_url = $variables['remote_url'];

  drupal_add_css(drupal_get_path('module', 'diff') . '/css/diff.default.css');
  $header = array('&nbsp;', t('Old Revision'), '&nbsp;', t('Current Revision'));
  $output = '';
  foreach ($diffs as $diff) {
    // FIXME create a render array.
    $output .= '<h3>' . l($diff['info']['label'], $diff['info']['url']) . '</h3>';
    if (is_array($diff['diff'])) {
      foreach ($diff['diff'] as $field => $data) {
        $output .= '<h2>' . filter_xss($diff['info']['fields'][$field]['label']) . '</h4>';
        $output .= theme('table', array('header' => $header, 'rows' => $data));
      }
    }
    else {
      $output .= '<div class="diff-unavailable">' . t('Unable to display changes.') . '</div>';
    }
  }

  return $output;
}
