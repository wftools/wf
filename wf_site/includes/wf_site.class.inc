<?php

/**
 * @file
 * Workflow Site class.
 */

class WfSite extends Entity {

  public $is_new = FALSE;

  public $bundle = 'site';

  public $sid = 0;

  public $vid = 0;

  public $uuid;

  public $vuuid;

  public $site_name;

  public $active = TRUE;

  public $created;

  public $changed;

  public $uid;

  /**
   * Creates a new entity.
   *
   * @see entity_create()
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, 'wf_site');
  }

  /**
   * Build up the view content.
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {

    $content = array();

    $content['sid'] = array(
      '#theme' => 'field',
      '#title' => t('SID'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_site',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $this->sid)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->sid),
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
      '#entity_type' => 'wf_site',
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
      '#entity_type' => 'wf_site',
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
      '#entity_type' => 'wf_site',
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
      '#entity_type' => 'wf_site',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $this->bundle)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->bundle),
    );

    $content['site_name'] = array(
      '#theme' => 'field',
      '#title' => t('Name'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'none',
      '#entity_type' => 'wf_site',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $this->site_name)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->site_name),
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
      '#entity_type' => 'wf_site',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $active_str)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $active_str),
    );

    $blocked_str = $this->blocked ? t('Yes') : t('No');
    $content['blocked'] = array(
      '#theme' => 'field',
      '#title' => t('Blocked'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'none',
      '#entity_type' => 'wf_site',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $blocked_str)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $blocked_str),
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
      '#entity_type' => 'wf_site',
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
      '#entity_type' => 'wf_site',
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
      '#entity_type' => 'wf_site',
      '#bundle' => $this->bundle,
      '#items' => array($changed),
      '#formatter' => 'text_default',
      0 => array('#markup' => $changed),
    );

    return entity_get_controller($this->entityType)->buildContent($this, $view_mode, $langcode, $content);
  }

  /**
   * Generates the URI for the entity.
   */
  public function defaultUri() {
    return array('path' => 'site/' . $this->identifier());
  }

  /**
   * Generates the title for the entity.
   */
  public function label() {
    $label = t('Invalid');
    if (isset($this->site_name)) {
      return $this->site_name;
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
