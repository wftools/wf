<?php

/**
 * @file
 * Workflow log controller class.
 */

class WfLogController extends EntityAPIController {

  public function create(array $values = array()) {
    $values += array(
      'uid' => $GLOBALS['user']->uid,
      'created' => REQUEST_TIME,
    );

    return parent::create($values);
  }

}

