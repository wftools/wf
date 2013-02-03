<?php
/**
 * @file
 *   Theme hook implementations for wf_environment module
 */

/**
 * Returns HTML for a list of available environment types for job creation.
 *
 * @param $variables
 *   An associative array containing:
 *   - content: An array of environment types.
 *
 * @ingroup themeable
 */
function theme_wf_evironment_add_list($variables) {
  $content = $variables['content'];
  $environments = array();
  $i = 0;

  foreach ($content as $item) {
    $title = l(t('<span class="icon"></span>@label', array('@label' => $item->label)), 'environment/add/' . $item->bundle, array('html' => TRUE));
    $environment_types[str_replace(' ', '', $item->label) . '_' . $i] = '<li>' . $title . '</li>';
    $i++;
  }
  ksort($environments);
  $output = '<ul class="env-type-list admin-list">' . implode("\n", $environment_types) . '</ul>';

  return $output;
}

