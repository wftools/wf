<?php

/**
 * @file
 * Workflow Job class.
 */
class WfJob extends Entity {

  public $is_new = FALSE;

  public $bundle = 'job';

  public $jid = 0;

  public $uuid;

  public $title;

  public $reference;

  public $details;

  public $jsid;

  public $owner;

  public $assigned;

  public $eid;

  public $modified;

  public $log;

  public $uid;

  /**
   * Creates a new entity.
   *
   * @see entity_create()
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, 'wf_job');
  }

  
  /**
   * Generates the URI for the entity.
   */
  public function defaultUri() {
    return array('path' => 'job/' . $this->identifier());
  }

  /**
   * Generates the title for the entity.
   */
  public function label() {
    $label = t('Invalid');
    if (isset($this->title)) {
      return $this->title;
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

  public function setStatusName($status_name) {
    $statuses = array_flip(wf_job_status_list());
    if (isset($statuses[$status_name])) {
      $this->jsid = $statuses[$status_name];
      return TRUE;
    }
    return FALSE;
  }
}
