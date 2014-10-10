<?php
/**
 * @file
 *   Theme hook implementations for wf_job module
 */

/**
 * Returns HTML for a list of available job types for job creation.
 *
 * @param $variables
 *   An associative array containing:
 *   - content: An array of job types.
 *
 * @ingroup themeable
 */
function theme_wf_job_add_list($variables) {
  $content = $variables['content'];
  $blocks = array();
  $i = 0;

  if ($content) {
    foreach ($content as $item) {
      $title = l(t('<span class="icon"></span>@label', array('@label' => $item->label)),
                'job/add/' . $item->bundle, array('html' => TRUE));
      $detail = '<div class="detail">' . check_plain($item->detail) . '</div>';
      $job_types[str_replace(' ', '', $item->label) . '_' . $i] = '<li class="wf-job-add-list-item">' . $title . $detail .'</li>';
      $i++;
    }
    ksort($blocks);
    $output = '<ul class="job-type-list admin-list">' . implode("\n", $job_types) . '</ul>';
  }
  else {
    $output = '<p>' . t('You have not created any job types yet.') . '</p>';
  }
  return $output;
}

 /**
  * Theme hook for wf_job_drush_aliases
  */
function theme_wf_job_drush_aliases($variables) {
  $aliases = $variables['aliases'];

  $php = '';
  foreach ($aliases as $name => $alias) {
    $php .= "\$aliases['$name'] = " . theme('php_array', array('array' => $alias)) . ";\n\n";
  }

  return $php;
}
