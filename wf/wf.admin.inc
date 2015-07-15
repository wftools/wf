<?php
/**
 * @file
 * Workflow admin pages
 */

/**
 * Settings form for workflow module.
 */
function wf_settings_form($form, &$form_state) {
  $form = array();

  $form['wf_sandbox_basepath'] = array(
    '#type' => 'textfield',
    '#title' => t('Sandbox basepath'),
    '#description' => t('The sandbox basepath of the WF.'),
    '#default_value' => variable_get('wf_sandbox_basepath', '/srv/www'),
    '#required' => FALSE,
  );

  $form['wf_sandbox_remote_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Remote host'),
    '#description' => t('The remote host of the WF.'),
    '#default_value' => variable_get('wf_sandbox_remote_host', 'localhost'),
    '#required' => FALSE,
  );

  $form['#validate'] = array('wf_settings_form_validate');

  return system_settings_form($form);
}

/**
 * Handler the admin settings form validate.
 */
function wf_settings_form_validate($form, &$form_state) {
  $values =& $form_state['values'];

  if (!empty($values['wf_sandbox_remote_host']) && $values['wf_sandbox_remote_host'] === gethostbyname($values['wf_sandbox_remote_host'])) {
    form_set_error('wf_sandbox_remote_host', t("The Remote host address isn't corresponding to a given Internet host name."));
  }
}
