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

  public $uid;

  public $default_revision = TRUE;

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
   * Checks if the job is in the default environment.
   *
   * @return bool
   *   Returns TRUE if the job is in the default environment.
   */
  public function isInDefaultEnv() {
    $default_env = wf_environment_get_default($this);
    return $this->eid == $default_env;
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

    return parent::save();
  }

  /**
   * Set the status of the job by name.
   *
   * @param string $status_name
   *   The name of the status to set for the job.
   *
   * @return bool
   *   Returns TRUE if the status name is valid, otherwise FALSE.
   */
  public function setStatusName($status_name) {
    $status = wf_job_load_status_by_name($status_name);
    if (!empty($status)) {
      $this->jsid = $status->jsid;
      return TRUE;
    }
    return FALSE;
  }
}
