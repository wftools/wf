<?php
/**
 * @file
 * wf.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function wf_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'workflow';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'wf';
  $endpoint->authentication = array();
  $endpoint->server_settings = array(
    'rest_server' => array(
      'formatters' => array(
        'json' => TRUE,
        'bencode' => FALSE,
        'jsonp' => FALSE,
        'php' => FALSE,
        'rss' => FALSE,
        'xml' => FALSE,
        'yaml' => FALSE,
      ),
      'parsers' => array(
        'application/json' => TRUE,
        'application/vnd.php.serialized' => FALSE,
        'application/x-www-form-urlencoded' => FALSE,
        'application/x-yaml' => FALSE,
        'multipart/form-data' => FALSE,
      ),
    ),
  );
  $endpoint->resources = array(
    'job' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => 1,
        ),
        'create' => array(
          'enabled' => 1,
        ),
        'update' => array(
          'enabled' => 1,
        ),
        'delete' => array(
          'enabled' => 1,
        ),
        'index' => array(
          'enabled' => 1,
        ),
      ),
      'relationships' => array(
        'environment' => array(
          'enabled' => 1,
        ),
      ),
      'targeted_actions' => array(
        'deployment' => array(
          'enabled' => 1,
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['workflow'] = $endpoint;

  return $export;
}
