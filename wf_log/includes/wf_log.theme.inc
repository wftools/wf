<?php
/**
 * @file
 * Theme hook implementations for wf_log module
 */

/**
 * Returns HTML for a list of available log types for log creation.
 *
 * @param array $variables
 *   An associative array containing:
 *   - content: An array of log types.
 *
 * @ingroup themeable
 */
function theme_wf_log_add_list($variables) {
  $content = $variables['content'];
  $blocks = array();
  $i = 0;

  if (!isset($content)) {
    return '<p>' . t('You have not created any Log types yet.') . '</p>';
  }

  foreach ($content as $item) {
    $title = l(t('<span class="icon"></span>@label', array('@label' => $item->label)), 'wf-log/add/' . $item->bundle, array('html' => TRUE));
    $log_types[str_replace(' ', '', $item->label) . '_' . $i] = '<li>' . $title . '</li>';
    $i++;
  }
  ksort($blocks);
  $output = '<ul class="log-type-list admin-list">' . implode("\n", $log_types) . '</ul>';

  return $output;
}
