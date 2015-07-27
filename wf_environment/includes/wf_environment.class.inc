<?php

/**
 * @file
 * WF Environment class.
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

    $content = parent::buildContent($view_mode, $langcode, array());

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

    return $content;
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
