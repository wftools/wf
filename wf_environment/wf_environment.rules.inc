<?php
/**
 * @file
 *  Rules module hook implementations.
 */

/**
 * Implements hook_rules_action_info().
 */
function wf_environment_rules_action_info() {
  $actions = array();

  $defaults = array(
    'group' => t('SSH'),
    'access arguments' => array('administer environments'),
    'named parameter' => TRUE,
  );

  $actions['wf_environment_add_user_ssh_private_key'] = $defaults + array(
    'label' => t('Add an SSH Private Key to a Workflow Environment'),
    'base' => 'wf_environment_add_user_ssh_private_key',
    'parameter' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('User'),
        'save' => FALSE,
      ),
      'environment' => array(
        'type' => 'wf_environment',
        'label' => t('Workflow Environment'),
        'save' => FALSE,
      ),
      'owner' => array(
        'type' => 'text',
        'label' => t('The username of the user who should own the key on the environment server'),
        'save' => FALSE,
      ),
      'keypair' => array(
        'type' => 'ssh_key_pair',
        'label' => t('SSH Key Pair'),
        'save' => FALSE,
      ),
    ),
  );

  return $actions;
}

/**
 * Base function for wf_environment_add_user_ssh_private_key rules event.
 */
function wf_environment_add_user_ssh_private_key($variables) {
  $keypair = $variables['keypair'];
  $user = $variables['user'];
  $env = $variables['environment'];
  $owner = $variables['owner'];
  $drush_alias = '@' . ltrim($env->drush_alias, '@');

  try {
    $shell = new Shell();
    $user = $shell->run("drush site-alias $drush_alias", array('--component=remote-user' => NULL));
    $host = $shell->run("drush site-alias $drush_alias", array('--component=remote-host' => NULL));
    $target = $shell->run("drush site-alias $drush_alias", array('--component=wf-ssh-target' => NULL));

    if (FALSE === $host) {
      throw new RuntimeException(t('Could not get user/host from drush alias for @env', array('@env' => $env->env)));
    }

    if (!empty($target)) {
      $shell = new Shell(array(
        'env' => array('SSH_TARGET' => trim($target)),
      ));
    }

    $host = trim($host);
    $env_url = $user ? trim($user) . "@$host" : $host;
    $filename = basename($keypair['private_key']);
    $new_file = "/tmp/$filename";

    // Copy the private key to the server
    if (FALSE === $shell->run('scp', array(), array($keypair['private_key'], "$env_url:$new_file"))) {
      throw new RuntimeException(t("Could not copy the new private key to @env: @error", array('@env' => $env->env, '@error' => $shell->getError())));
    }

    // Install the file on the remote server
    $commands = array(
      "chmod 644 $new_file",
      "sudo -u $owner -H install-ssh-file.sh $new_file",
      "rm $new_file",
    );
    foreach ($commands as $command) {
      $command = $shell->prepareCommand($command);
      if (FALSE === $shell->run('ssh', array(), array($env_url, $command))) {
        throw new RuntimeException($shell->getError());
      }
    }

    drupal_set_message(t('Private key transmitted to @env', array('@env' => $env->env)));
  }
  catch (RuntimeException $e) {
    drupal_set_message(t('Could not copy and install new key to @env', array('@env' => $env->env)), 'error');
    watchdog_exception('wf_environment', $e);
  }
}

