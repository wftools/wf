<?php
/**
 * @file
 * wf_job.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function wf_job_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'wf_job';
  $context->description = 'Layout for items on job pages';
  $context->tag = 'Layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'job/*' => 'job/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'wf_job-wf_job_env_status' => array(
          'module' => 'wf_job',
          'delta' => 'wf_job_env_status',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'wf_job-wf_job_changes' => array(
          'module' => 'wf_job',
          'delta' => 'wf_job_changes',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  t('Layout for items on job pages');
  $export['wf_job'] = $context;

  return $export;
}
