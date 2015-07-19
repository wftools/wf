<?php

/**
 * @file
 * Contains callbacks for service resource manipulation.
 */

/**
 * Implements hook_services_resources().
 */
function wf_job_services_resources() {
  $resources = array(
    'job' => array(
      'retrieve' => array(
        'help' => t('This method returns a job.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'wf_job',
          'name' => 'wf_job.services',
        ),
        'callback' => 'wf_job_services_retrieve',
        'access arguments' => array('administer jobs'),
        'args' => array(
          array(
            'name' => 'jid',
            'type' => 'int',
            'description' => t('The id of the job to get.'),
            'source' => array('path' => '0'),
            'optional' => FALSE,
          ),
        ),
      ),
      'create' => array(
        'help' => t('This method creates a job.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'wf_job',
          'name' => 'wf_job.services',
        ),
        'callback' => 'wf_job_services_create',
        'access callback' => 'wf_job_services_access',
        'access arguments' => array('create'),
        'access arguments append' => TRUE,
        'args' => array(
          array(
            'name' => 'data',
            'type' => 'struct',
            'description' => t('An object representing the job.'),
            'source' => 'data',
            'optional' => FALSE,
          ),
        ),
      ),
      'update' => array(
        'help' => t('This method updates a job.'),
        'file' => array('type' => 'inc', 'module' => 'wf_job', 'name' => 'wf_job.services'),
        'callback' => 'wf_job_services_update',
        'access callback' => 'wf_job_services_access',
        'access arguments' => array('update'),
        'access arguments append' => TRUE,
        'args' => array(
          array(
            'name' => 'jid',
            'type' => 'int',
            'description' => t('The id of the job to update.'),
            'source' => array('path' => '0'),
            'optional' => FALSE,
          ),
          array(
            'name' => 'data',
            'type' => 'struct',
            'description' => t('An object representing the job.'),
            'source' => 'data',
            'optional' => FALSE,
          ),
        ),
      ),
      'delete' => array(
        'help' => t('This method deletes a job.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'wf_job',
          'name' => 'wf_job.services',
        ),
        'callback' => 'wf_job_services_delete',
        'access callback' => 'wf_job_services_access',
        'access arguments' => array('delete'),
        'access arguments append' => TRUE,
        'args' => array(
          array(
            'name' => 'jid',
            'type' => 'int',
            'description' => t('The id of the job to delete.'),
            'source' => array('path' => '0'),
            'optional' => FALSE,
          ),
        ),
      ),
      'index' => array(
        'help' => t('This method returns a listing of jobs.'),
        'file' => array(
          'type' => 'inc',
          'module' => 'wf_job',
          'name' => 'wf_job.services',
        ),
        'callback' => 'wf_job_services_index',
        'access arguments' => array('administer jobs'),
        'args' => array(
          array(
            'name' => 'page',
            'optional' => TRUE,
            'type' => 'int',
            'description' => t('The zero-based index of the page to get, defaults to 0.'),
            'default value' => 0,
            'source' => array('param' => 'page'),
          ),
          array(
            'name' => 'fields',
            'optional' => TRUE,
            'type' => 'string',
            'description' => t('The fields to return.'),
            'default value' => '*',
            'source' => array('param' => 'fields'),
          ),
          array(
            'name' => 'parameters',
            'optional' => TRUE,
            'type' => 'array',
            'description' => t('Fields an values to filter the list by.'),
            'default value' => array(),
            'source' => array('param' => 'parameters'),
          ),
          array(
            'name' => 'pagesize',
            'optional' => TRUE,
            'type' => 'int',
            'description' => t('Number of records to get per page.'),
            'default value' => 20,
            'source' => array('param' => 'pagesize'),
          ),
        ),
      ),
      'relationships' => array(
        'environment' => array(
          'file' => array('type' => 'inc', 'module' => 'wf_job', 'name' => 'wf_job.services'),
          'help' => t('This method returns the job\'s current environment.'),
          'access callback' => 'wf_job_services_access',
          'access arguments' => array('environment'),
          'access arguments append' => TRUE,
          'callback' => 'wf_job_services_environment',
          'args' => array(
            array(
              'name' => 'jid',
              'type' => 'int',
              'description' => t('The id of the job for which to get an environment.'),
              'source' => array('path' => '0'),
              'optional' => FALSE,
            ),
            array(
              'name' => 'which',
              'type' => 'string',
              'description' => t('Which environment - current or next.'),
              'source' => array('path' => '2'),
              'optional' => FALSE,
              'default value' => 'current',
            ),
          ),
        ),
      ),
    ),
  );

  return $resources;
}

/**
 * Returns a specified job.
 *
 * @param int $jid
 *   Unique identifier for the specified job.
 *
 * @return object
 *   The job object.
 */
function wf_job_services_retrieve($jid) {
  $job = wf_job_load($jid);

  if (!$job) {
    return services_error(t('Job @jid not found.', array('@jid' => $jid)), 404);
  }

  return $job;
}

/**
 * Adds a new job to a node and returns the jid.
 *
 * @param object $job
 *   An object as would be returned from wf_job_load().
 *
 * @return array
 *   Unique identifier for the job (jid) or errors if there was a problem.
 */
function wf_job_services_create($job) {
  $job = entity_create('wf_job', $job);
  unset($job->jid);

  try {
    wf_job_save($job);
  }
  catch (Exception $e) {
    return services_error(t('Failed to create job.'), 500);
  }

  return array(
    'jid' => $job->jid,
    'uri' => services_resource_uri(array('job', $job->jid)),
  );
}

/**
 * Updates a job and returns the jid.
 *
 * @param int $jid
 *   Unique identifier for this wf_job.
 *
 * @param object $job
 *   An object as would be returned from wf_job_load().
 *
 * @return int
 *   Unique identifier for the job (jid) or FALSE if there was a problem.
 */
function wf_job_services_update($jid, $job) {
  $job = entity_create('wf_job', $job);
  $job->jid = $jid;
  try {
    wf_job_save($job);
  }
  catch (Exception $e) {
    return services_error(t('Failed to update job @jid.', array('@jid' => $jid)), 500);
  }

  return $jid;
}

/**
 * Delete a job.
 *
 * @param int $jid
 *   Unique identifier of the job to delete.
 *
 * @return bool
 *   True.
 */
function wf_job_services_delete($jid) {
  $job = wf_job_load($jid);

  if (!$job) {
    return services_error(t('Job @jid not found.', array('@jid' => $jid)), 404);
  }

  wf_job_delete($jid);

  return TRUE;
}

/**
 * Return an array of optionally paged jids based on a set of criteria.
 *
 * An example request might look like:
 *
 * http://domain/endpoint/job?fields=jid,label&parameters[type]=mytype
 *
 * This would return an array of objects with only jid and label defined, where
 * type = 'mytype'.
 *
 * @param int $page
 *   Page number of results to return (in pages of 20).
 *
 * @param array $fields
 *   The fields you want returned.
 *
 * @param array $parameters
 *   An array containing fields and values used to build a sql WHERE clause
 *   indicating items to retrieve.
 *
 * @param int $page_size
 *   Integer number of items to be returned.
 *
 * @return array
 *   An array of job objects.
 */
function wf_job_services_index($page, $fields, $parameters, $page_size) {
  $job_select = db_select('wf_job', 't')
    ->orderBy('jid', 'DESC');

  services_resource_build_index_query($job_select, $page, $fields, $parameters, $page_size, 'job');

  $results = services_resource_execute_index_query($job_select);

  return services_resource_build_index_list($results, 'job', 'jid');
}


/**
 * Returns the current or next environment for a specified job.
 *
 * @param int $jid
 *   Unique identifier for the specified job.
 *
 * @param string $which
 *   'current' or 'next' environment
 *
 * @return object
 *   The WfEnv object.
 */
function wf_job_services_environment($jid, $which) {
  if (!in_array($which, array('current', 'next'))) {
    return services_error(t('Environment type @type not known.', array('@type' => $which)), 404);
  }

  $job = wf_job_load($jid);

  if (!$job) {
    return services_error(t('Job @jid not found.', array('@jid' => $jid)), 404);
  }

  $env = wf_environment_load($job->eid);
  if (!$env) {
    return services_error(t('Environment for Job @jid not found.', array('@jid' => $jid)), 404);
  }

  if ($which != 'next') {
    return $env;
  }
  elseif (empty($env->next_env_id)) {
    return NULL;
  }

  $next = wf_environment_load($env->next_env_id);
  if (!$next) {
    return services_error(t('Next environment for Job @jid not found.', array('@jid' => $jid)), 404);
  }

  return $next;
}

/**
 * Records the outcome of a deployment.
 *
 * @param int $jid
 *   Unique identifier for the specified job.
 *
 * @param array $data
 *   An array with 2 keys: 'succeeded' & 'message'
 *
 * @return bool
 *   True.
 */
function wf_job_services_deployment($jid, $data) {
  $job = wf_job_load($jid);

  if (!$job) {
    return services_error(t('Job @jid not found.', array('@jid' => $jid)), 404);
  }

  return wf_job_deployment($job, (bool) $data['succeeded'], $data['message']);
}

/**
 * Access callback for the job resource.
 *
 * @param string $op
 *   The operation that's going to be performed.
 *
 * @param array $args
 *   The arguments that will be passed to the callback.
 *
 * @return bool
 *   Whether access is given or not.
 */
function wf_job_services_access($op, $args) {
  $job = empty($args[0]) ? NULL : $args[0];

  return wf_job_access($op, $job);
}
