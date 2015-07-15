<?php

/**
 * @file
 * Workflow environment admin functions.
 */

/**
 * Generates the wf environment bundle edit form.
 */
function wf_environment_bundle_form($form, &$form_state, $env_bundle, $op = 'edit') {

  if ($op == 'clone') {
    $env_bundle->label .= ' (cloned)';
    $env_bundle->bundle .= '_clone';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => !empty($env_bundle->label) ? $env_bundle->label : '',
  );

  $form['bundle'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($env_bundle->bundle) ? $env_bundle->bundle : '',
    '#disabled' => empty($env_bundle->is_new),
    '#machine_name' => array(
      'exists' => 'wf_environment_bundle_exists',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this environment type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save environment type'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function wf_environment_bundle_form_submit(&$form, &$form_state) {
  $environment_bundle = entity_ui_form_submit_build_entity($form, $form_state);
  $environment_bundle->save();
  cache_clear_all('wf_environment_load_bundles', 'cache');
  $form_state['redirect'] = 'admin/structure/env-types';
}

/**
 * Admin environments call back.
 */
function wf_environment_admin_list() {
  $rows = array();

  $header = array(
    'title' => array(
      'data' => 'Title',
      'type' => 'property',
      'specifier' => 'env',
      'sort' => 'asc',
    ),
    'operations' => array('data' => t('Operations')),
  );

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'wf_environment')
    ->tableSort($header)
    ->pager(50);

  $result = $query->execute();
  if (!empty($result)) {
    $envs = wf_environment_load_multiple(array_keys($result['wf_environment']));
  }
  else {
    $envs = array();
  }

  foreach ($envs as $env) {
    $rows[$env->id] = array(
      'title' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $env->env,
          '#href' => 'environment/' . $env->id,
        ),
      ),
    );

    $destination = drupal_get_destination();

    // Build a list of all the accessible operations for the current bean.
    $operations = array();
    $operations['edit'] = array(
      'title' => t('edit'),
      'href' => 'environment/' . $env->id . '/edit',
      'query' => $destination,
    );
    $operations['delete'] = array(
      'title' => t('delete'),
      'href' => 'environment/' . $env->id . '/delete',
      'query' => $destination,
    );
    $rows[$env->id]['operations'] = array(
      'data' => array(
        '#theme' => 'links',
        '#links' => $operations,
        '#attributes' => array('class' => array('links', 'inline')),
      ),
    );
  }

  $output = theme('table', array('header' => $header, 'rows' => $rows));
  $output .= theme('pager');

  return $output;
}

/**
 * Admin settings form.
 */
function wf_environment_admin_settings() {
  $form = array();

  $environments = wf_environment_load_multiple(FALSE, array('active' => TRUE));
  if (!count($environments)) {
    $link = l(t('Please create at least one environment.'), 'environment/add');
    return $form['no_environments'] = array(
      '#markup' => t('No environments exist. !link', array('!link' => $link)),
    );
  }

  $options = array();
  foreach ($environments as $environment) {
    $options[$environment->id] = $environment->env;
  }

  $form['wf_environment_default'] = array(
    '#type' => 'select',
    '#title' => t('Default environment'),
    '#default_value' => wf_environment_get_default(),
    '#options' => $options,
    '#description' => t('Select the default environment for new jobs.'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
