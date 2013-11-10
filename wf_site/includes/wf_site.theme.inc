<?php
/**
 * @file
 * Theme hook implementations for wf_site module
 */

/**
 * Returns HTML for a list of available site types for site creation.
 *
 * @param array $variables
 *   An associative array containing:
 *   - content: An array of site types.
 *
 * @ingroup themeable
 */
function theme_wf_site_add_list($variables) {
  $content = $variables['content'];
  $sites = array();
  $i = 0;

  foreach ($content as $item) {
    $title = l(t('<span class="icon"></span>@label', array('@label' => $item->label)), 'site/add/' . $item->bundle, array('html' => TRUE));
    $site_types[str_replace(' ', '', $item->label) . '_' . $i] = '<li>' . $title . '</li>';
    $i++;
  }
  ksort($sites);
  $output = '<ul class="site-type-list admin-list">' . implode("\n", $site_types) . '</ul>';

  return $output;
}
