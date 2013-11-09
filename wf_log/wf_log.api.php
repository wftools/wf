<?php

/**
 * @file
 * Hooks provided by wf_log module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Declare possible Log entries.
 *
 * @return array
 *   An associative array where the key is the log name and the value is
 *   again an associative array. Possible keys are:
 *   - 'title': The title/name of the log entry.
 *   - 'description': A short text describing the entry Log.
 */
function hook_wf_log_info() {
  $logs = array();

  $logs['instance_created'] = array(
    'title' => t('Instance created'),
    'description' => t('A new instance was created.'),
  );

  return $logs;
}

/**
 * @} End of "addtogroup hooks".
 */
