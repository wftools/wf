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
 * @param array $diff
 *   An structured array containing the diff information.
 *
 * @param object $job
 *   The related wf_job object.
 */
function hook_wf_deploy_services_client_content_diff_data_alter(&$diff, $job) {
}

/**
 * Alter the WF deploy services client config.
 *
 * @param array $config
 *   The client config to be altered.
 * @param WfJob $job
 *   The job the client relates to.
 */
function hook_wf_deploy_services_client_remote_config_alter(&$config, $job) {
  $handler = wf_job_get_visit_plugin_handler();
  $url = parse_url($config['url']);
  $url['scheme'] = 'https';
  $config['url'] = $handler->buildUrl($url);
}
/**
 * @} End of "addtogroup hooks".
 */
