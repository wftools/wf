<?php
/**
 * @file
 * Hooks provided by wf_deploy_services_client module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Alter the diff data before the content is processed.
 *
 * @param array $data
 *   An structured array containing the diff information.
 *
 * @param object $job
 *   The related wf_job object.
 */
function hook_wf_deploy_services_client_content_diff_data_alter(&$diff, $job) {
}

/**
 * @} End of "addtogroup hooks".
 */