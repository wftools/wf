<?php

/**
 * Implements hook_drush_command().
 */
function wf_drush_command() {
  $items = array();

  $items['wf-sql-db-create'] = array(
    'callback' => 'wf_sql_db_create',
    'description' => 'Creates a new database. Currently only supports MySQL.',
    'aliases' => array('sql-db-create', 'sql-create'),
    'options' => array(
      'db-host' => 'Hostname for the database server.',
      'db-root-user' => 'Database user with administrative privileges.',
      'db-root-pass' => 'The password for the root user.',
      'db-name' => 'The name of the new database to be created.',
      'db-user' => 'The username for the user to be created.',
      'db-pass' => 'The password for the new database user.',
      'db-allow-hosts' => 'A comma separated list of hosts the user may connect from.',
    ),
  );

  return $items;
}

/**
 * Create database command callback.
 */
function wf_sql_db_create() {
  $host = drush_get_option('db-host', 'localhost');

  $root_pass = drush_get_option('db-root-pass');
  if (!$root_pass) {
    return drush_set_error(dt('You must specify a password for the root user.'));
  }

  $db_name = drush_get_option('db-name');
  if (!$db_name) {
    return drush_set_error(dt('You must specify the name of the database to create.'));
  }

  $db_user = drush_get_option('db-user');
  if (!$db_user) {
    return drush_set_error(dt('You must specify the username for the new database user.'));
  }

  $db_pass = drush_get_option('db-pass');
  if (!$db_pass) {
    return drush_set_error(dt('You must specify a password for the new database user.'));
  }

  $allow_hosts = explode(',', drush_get_option('db-allow-hosts', 'localhost'));

  $pdo = new PDO(
    "mysql:host={$host};",
    drush_get_option('db-root-user', 'root'),
    $root_pass
  );

  $escaped_db_name = trim($pdo->quote($db_name), "'");
  if (FALSE === $pdo->exec('CREATE DATABASE ' . $escaped_db_name)) {
    return drush_set_error(dt('Unable to create database "@db".', array('@db' => $db_name)));
  }

  $db_host = '';
  $user_stmt = $pdo->prepare('CREATE USER :db_user@:db_host IDENTIFIED BY :db_pass');
  $user_stmt->bindValue(':db_user', $db_user, PDO::PARAM_STR);
  $user_stmt->bindValue(':db_pass', $db_pass, PDO::PARAM_STR);
  $user_stmt->bindParam(':db_host', $db_host, PDO::PARAM_STR);

  $grant_stmt = $pdo->prepare("GRANT ALL PRIVILEGES ON {$escaped_db_name}.* TO :db_user@:db_host");
  $grant_stmt->bindValue(':db_user', $db_user, PDO::PARAM_STR);
  $grant_stmt->bindParam(':db_host', $db_host, PDO::PARAM_STR);
  foreach ($allow_hosts as $db_host) {
    if (FALSE === $user_stmt->execute()) {
      return drush_set_error(dt('Failed to create user @db_user@db_host with password "@db_pass"', array('@db_user' => $db_user, '@db_pass' => $db_pass, '@db_host' => $db_host)));
    }

    if (FALSE === $grant_stmt->execute()) {
      return drush_set_error(dt('Failed to grant access to @db_user@@db_host for database "@db_name"', array('@db_user' => $db_user, '@db_host' => $db_host, '@db_name' => $db_name)));
    }
  }

  $db_url = "mysql://{$db_user}:{$db_pass}@{$db_host}/{$db_name}";
  drush_print(dt('Created database @db_url', array('@db_url' => $db_url)));
  drush_print_pipe($db_url);
}
