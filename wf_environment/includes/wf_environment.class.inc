<?php

/**
 * @file
 * Workflow Environment class.
 */

class WfEnvironment extends Entity {

  public $is_new = FALSE;

  public $bundle = 'environment';

  public $id = 0;

  public $vid = 0;

  public $uuid;

  public $vuuid;

  public $env;

  public $drush_alias;

  public $next_env_id;

  public $notes;

  public $active = TRUE;

  public $created;

  public $changed;

  public $log;

  public $uid;

  /**
   * Creates a new entity.
   *
   * @see entity_create()
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, 'wf_environment');
  }


  /**
   * Build up the view content.
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {

    $content = array();

    $content['id'] = array(
      '#theme' => 'field',
      '#title' => t('ID'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $this->id)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->id),
    );

    $content['vid'] = array(
      '#theme' => 'field',
      '#title' => t('Revision ID'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $this->vid)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->vid),
    );

    $content['uuid'] = array(
      '#theme' => 'field',
      '#title' => t('UUID'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $this->uuid)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->uuid),
    );

    $content['vuuid'] = array(
      '#theme' => 'field',
      '#title' => t('Revision UUID'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $this->vuuid)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->vuuid),
    );

    $content['bundle'] = array(
      '#theme' => 'field',
      '#title' => t('Type'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $this->bundle)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->bundle),
    );

    $content['env'] = array(
      '#theme' => 'field',
      '#title' => t('Name'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'none',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $this->env)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->env),
    );

    $next_env = t('Final');
    if ($this->next_env_id) {
      $next_env_obj = wf_environment_load($this->next_env_id);
      if (is_object($next_env_obj)) {
        $next_env_label = $next_env_obj->label();
        $next_env_uri = $next_env_obj->uri();
        $next_env = l($next_env_label, $next_env_uri['path']);
      }
    }
    $content['next_env_id'] = array(
      '#theme' => 'field',
      '#title' => t('Next Environment'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'none',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $next_env)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $next_env),
    );

    $active_str = $this->active ? t('Yes') : t('No');
    $content['active'] = array(
      '#theme' => 'field',
      '#title' => t('Active'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'none',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $active_str)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $active_str),
    );

    $content['notes'] = array(
      '#theme' => 'field',
      '#title' => t('Notes'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'none',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#prefix' => '<div class="env-notes">',
      '#suffix' => '</div>',
      '#items' => array(array('value' => $this->notes)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->notes),
    );

    $user_name = entity_label('user', user_load($this->uid));
    $content['uid'] = array(
      '#theme' => 'field',
      '#title' => t('User'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $user_name)),
      '#formatter' => 'text_default',
      0 => array('#markup' => l($user_name, 'user/' . $this->uid)),
    );

    $created = format_date($this->created);
    $content['created'] = array(
      '#theme' => 'field',
      '#title' => t('Created'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#items' => array($created),
      '#formatter' => 'text_default',
      0 => array('#markup' => $created),
    );

    $changed = format_date($this->changed);
    $content['changed'] = array(
      '#theme' => 'field',
      '#title' => t('Last Modified'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_environment',
      '#bundle' => $this->bundle,
      '#items' => array($changed),
      '#formatter' => 'text_default',
      0 => array('#markup' => $changed),
    );

/*

    $env->content['notes'] = array(
      '#type' => 'markup',
      '#markup' => check_markup($env->notes),
      '#prefix' => '<div class="env-notes">',
      '#suffix' => '</div>',
    );

    if ($env->active) {
      $status = t('Enabled');
    }
    else {
      $status = t('Disabled');
    }
    $env->content['active'] = array(
      '#type' => 'markup',
      '#markup' => t('Status: !status', array('!status' => $status)),
      '#prefix' => '<div class="env-active">',
      '#suffix' => '</div>',
    );

    field_attach_prepare_view('wf_environment', array($env->id => $env), $view_mode);
    entity_prepare_view('wf_environment', array($env->id => $env));
    $env->content += field_attach_view('wf_environment', $env, $view_mode);

    $env->content['changed'] = array(
      '#type' => 'markup',
      '#markup' => t('Last Updated: !date', array('!date' => format_date($env->changed))),
      '#prefix' => '<div class="env-changed">',
      '#suffix' => '</div>',
    );

    return $env->content;
  }
*/
    return entity_get_controller($this->entityType)->buildContent($this, $view_mode, $langcode, $content);
    return parent::buildContent($view_mode, $langcode, $content);
  }

  /**
   * Generates the URI for the entity.
   */
  public function defaultUri() {
    return array('path' => 'environment/' . $this->identifier());
  }

  /**
   * Generates the title for the entity.
   */
  public function label() {
    $label = t('Invalid');
    if (isset($this->env)) {
      return $this->env;
    }
    return $label;
  }

  /**
   * Saves the entity.
   */
  public function save() {
    global $user;
    $this->uid = $user->uid;

    $this->modified = REQUEST_TIME;
    if (!empty($this->is_new)) {
      $this->created = REQUEST_TIME;
    }
    else {
      $this->revision = TRUE;
    }

    parent::save();
  }
}
