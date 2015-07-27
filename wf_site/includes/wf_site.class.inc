<?php

/**
 * @file
 * WF Site class.
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

    $this->changed = REQUEST_TIME;
    if (!empty($this->is_new)) {
      $this->created = REQUEST_TIME;
    }
    else {
      $this->revision = TRUE;
    }

    parent::save();
  }
}
