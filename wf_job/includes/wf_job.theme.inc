<?php
/**
 * @file
 * Theme hook implementations for wf_job module
 */

/**
 * Returns HTML for a list of available job types for job creation.
 *
 * @param array $variables
 *   An associative array containing:
 *   - content: An array of job types.
 *
 * @ingroup themeable
 */
function theme_wf_job_add_list($variables) {
  $bundles = $variables['bundles'];
  $items = array();

  foreach ($bundles as $bundle) {
    $items[] = l($bundle->label, $bundle->uri['path'], $bundle->uri['options']) . '<br />'
      . '<div class="detail">' . check_plain($bundle->detail) . '</div>';
  }

  $list = array(
    '#theme' => 'item_list',
    '#items' => $items,
    '#type' => 'li',
  );

  return drupal_render($list);
}

 /**
  * Theme hook for wf_job_drush_aliases.
  */
function theme_wf_job_drush_aliases($variables) {
  $aliases = $variables['aliases'];

  $php = '';
  foreach ($aliases as $name => $alias) {
    $php .= "\$aliases['$name'] = " . theme('php_array', array('array' => $alias)) . ";\n\n";
  }

  return $php;
}
