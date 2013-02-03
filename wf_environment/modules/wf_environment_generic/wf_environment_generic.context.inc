<?php
/**
 * @file
 * wf_environment_generic.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function wf_environment_generic_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'wf_environment';
  $context->description = 'Layout for environment pages.';
  $context->tag = 'Layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'environment/*' => 'environment/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-environment_jobs-block' => array(
          'module' => 'views',
          'delta' => 'environment_jobs-block',
          'region' => 'content',
          'weight' => '9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  t('Layout for environment pages.');
  $export['wf_environment'] = $context;

  return $export;
}
