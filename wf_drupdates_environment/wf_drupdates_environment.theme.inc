<?php

/**
 * @file
 * Themes the wf_drupdates_environment module.
 */

/**
 * Theme function for widget: wf_drupdates_environment_widget.
 */
function theme_wf_drupdates_environment($variables) {
  $element = $variables['element'];
  $output = '';

  // Build the table header.
  $header = array(
    'environment' => t('Environment'),
    'project_release' => t('Project release'),
  );

  // Build the rows.
  $rows = array();
  foreach (element_children($element) as $key) {
    $rows[$key] = array(
      'environment' => $element[$key]['env_id']['#label'],
      'project_release' => array(
        'data' => drupal_render($element[$key]['drupdates_release_id']),
      ),
    );
  }

  $output = theme('table', array('header' => $header, 'rows' => $rows));

  return $output;
}

/**
 * Theme function for element.
 */
function theme_wf_drupdates_environment_element($vars) {
  return $vars['element']['#children'];
}

/**
 * Theme function for default field formatter.
 */
function theme_wf_drupdates_environment_field_formatter_default($var) {
  $output = '';

  foreach ($var['element'] as $item) {
    $project_release_descriptive_name = wf_drupdates_environment_get_descriptive_project_release_name($item['drupdates_release_id']);
    $environment = wf_environment_load($item['env_id']);

    if ($project_release_descriptive_name && !empty($environment->env)) {
      $output .= '<li>' . $environment->env . ' - ' . $project_release_descriptive_name . '</li>';
    }
  }

  if (!empty($output)) {
    $output = '<ul>' . $output . '</ul>';
  }

  return $output;
}
