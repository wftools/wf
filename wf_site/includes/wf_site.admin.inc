<?php

/**
 * @file
 * WF site admin functions.
 */

/**
 * Generates the wf site bundle edit form.
 */
function wf_site_bundle_form($form, &$form_state, $site_bundle, $op = 'edit') {

  if ($op == 'clone') {
    $site_bundle->label .= ' (cloned)';
    $site_bundle->bundle .= '_clone';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => !empty($site_bundle->label) ? $site_bundle->label : '',
  );

  $form['bundle'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($site_bundle->bundle) ? $site_bundle->bundle : '',
    '#disabled' => empty($site_bundle->is_new),
    '#machine_name' => array(
      'exists' => 'wf_site_bundle_exists',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this site type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save site type'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function wf_site_bundle_form_submit(&$form, &$form_state) {
  $site_bundle = entity_ui_form_submit_build_entity($form, $form_state);
  $site_bundle->save();
  cache_clear_all('wf_site_load_bundles', 'cache');
  $form_state['redirect'] = 'admin/structure/site-types';
}

/**
 * Admin sites call back.
 */
function wf_site_admin_list() {
  $rows = array();

  $header = array(
    'title' => array(
      'data' => 'Title',
      'type' => 'property',
      'specifier' => 'site_name',
      'sort' => 'asc',
    ),
    'operations' => array('data' => t('Operations')),
  );

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'wf_site')
    ->tableSort($header)
    ->pager(50);

  $result = $query->execute();

  if (!empty($result)) {
    $sites = wf_site_load_multiple(array_keys($result['wf_site']));
  }
  else {
    $sites = array();
  }

  foreach ($sites as $site) {
    $rows[$site->sid] = array(
      'title' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $site->site_name,
          '#href' => 'site/' . $site->sid,
        ),
      ),
    );

    $destination = drupal_get_destination();

    // Build a list of all the accessible operations for the current bean.
    $operations = array();
    $operations['edit'] = array(
      'title' => t('edit'),
      'href' => 'site/' . $site->sid . '/edit',
      'query' => $destination,
    );

    $operations['delete'] = array(
      'title' => t('delete'),
      'href' => 'site/' . $site->sid . '/delete',
      'query' => $destination,
    );

    $rows[$site->sid]['operations'] = array(
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
