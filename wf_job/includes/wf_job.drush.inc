<?php
/**
 * @file
 *  Workflow Job Drush Commands
 */

/**
 * Implements hook_drush_command().
 */
function wf_job_drush_command() {
  $items = array();

  $items['job-drush-aliases'] = array(
    'description' => 'Render aliases.drushrc.php file contents',
    'examples' => array(
      'drush job-drush-aliases' => dt('Generate the contents of a complete drush alias file for all jobs'),
      'drush job-drush-aliases --no-php-open' => dt('Do not include the opening <?php tag'),
    ),
    'options' => array(
      'no-php-open' => dt('Do not include the php open tag'),
    ),
  );

  // Services wrapper commands
  $items['job-retrieve'] = array(
    'description' => t('Returns a JSON encoded job.'),
    'examples' => array(
      'drush job-retrieve <jid>' => dt("Retrieves job <jid> as a JSON encoded object"),
    ),
    'aliases' => array('jobr'),
  );

  $items['job-create'] = array(
    'description' => t('Creates a new job from a JSON argument.'),
    'examples' => array(
      'drush job-create \'{title:"Job Title"}\'' => dt("Creates a new job with values from the JSON object"),
    ),
    'aliases' => array('jobc'),
  );

  $items['job-update'] = array(
    'description' => t('Updates a job from a JSON argument.'),
    'examples' => array(
      'drush job-update <jid> \'{title:"Job Title"}\'' => dt("Updates job <jid> with values from the JSON object"),
    ),
    'aliases' => array('jobu'),
  );

  $items['job-delete'] = array(
    'description' => t('Deleted a job by it\'s jid'),
    'examples' => array(
      'drush job-delete <jid>' => dt('Deletes the job specified by <jid>'),
    ),
    'aliases' => array('jobd'),
  );

  $items['job-index'] = array(
    'description' => t('List all jobs'),
    'options' => array(
      'page' => dt('The zero-based index of the page to get, defaults to 0.'),
      'fields' => dt('The fields to return.'),
      'parameters' => dt('JSON encoded fields and values to filter the list by.'),
      'pagesize' => dt('Number of records to get per page.'),
    ),
    'aliases' => array('jobi'),
  );

  $items['job-environment'] = array(
    'description' => t('Retrieve a job\s environment'),
    'options' => array(
      'next' => dt('Return the next environment, not the current (default).'),
    ),
    'examples' => array(
      'drush job-environment <jid>' => dt("Returns the job's current environment"),
      'drush job-environment <jid> --next' => dt("Returns the job's next environment"),
    ),
    'aliases' => array('job-env', 'jobe'),
  );

  $items['job-deployment'] = array(
    'description' =>  dt('Record the outcome of a deployment.'),
    'options' => array(
      'succeeded' => dt('Whether the job suceeded (1) or failed (0).'),
      'message' => dt('A message about the deployment'),
    ),
    'examples' => array(
      "drush job-deployment <jid> --succeeded=1 --message='Successfully deployed'" => dt('Mark the job as successfully deployed.'),
    ),
    'aliases' => array('jobdep'),
  );

  return $items;
}

/**
 * Implementation of job-drush-aliases drush command. Renders aliases.drush.rc file.
 */
function drush_wf_job_job_drush_aliases() {
  $aliases = wf_job_drush_aliases();
  $php = '';
  if (!drush_get_option('no-php-open', FALSE)) {
    $php = "<?php\n";
  }
  $php .= theme('wf_job_drush_aliases', array('aliases' => $aliases));

  drush_print($php);
  drush_print_pipe($php);
}

/**
 * Services wrappers
 */
function wf_job_drush_services_invoke($command) {
  module_load_include('inc', 'wf_job', 'wf_job.services');
  module_load_include('inc', 'services', 'services.runtime');

  $func = "wf_job_services_$command";
  $args = func_get_args();
  array_shift($args);

  try {
    $result = call_user_func_array($func, $args);
    drush_print(drupal_json_encode($result));
  }
  catch (ServicesException $e) {
    watchdog_exception('wf_job', $e);
  }
}

/**
 * Callback for job-retrieve command.
 */
function drush_wf_job_job_retrieve($jid) {
  wf_job_drush_services_invoke('retrieve', $jid);
}

/**
 * Callback for job-create command.
 */
function drush_wf_job_job_create($job_json) {
  $job = drupal_json_decode($job_json);
  wf_job_drush_services_invoke('create', $job);
}

/**
 * Callback for job-update command.
 */
function drush_wf_job_job_update($jid, $job_json) {
  $job = drupal_json_decode($job_json);
  wf_job_drush_services_invoke('update', $jid, $job);
}

/**
 * Callback for job-delete command.
 */
function drush_wf_job_job_delete($jid) {
  wf_job_drush_services_invoke('delete', $jid);
}

/**
 * Callback for job-index command.
 */
function drush_wf_job_job_index() {
  $page = drush_get_option('page', 0);
  $fields = drush_get_option('fields', '*');
  $parameters = drupal_json_decode(drush_get_option('parameters', '[]'));
  $pagesize = drush_get_option('pagesize', 20);
  wf_job_drush_services_invoke('index', $page, $fields, $parameters, $pagesize);
}

/**
 * Callback for job-env command.
 */
function drush_wf_job_job_environment($jid) {
  $which = drush_get_option('next', FALSE) ? 'next' : 'current';
  wf_job_drush_services_invoke('environment', $jid, $which);
}

/**
 * Callback for job-deployment command.
 */
function drush_wf_job_job_deployment($jid) {
  $succeeded = (bool) drush_get_option('succeeded', TRUE);
  $message = drush_get_option('message', $succeeded ? t('Succeeded') : t('Failed'));
  $data = array('succeeded' => $succeeded, 'message' => $message);
  wf_job_drush_services_invoke('deployment', $jid, $data);
}
