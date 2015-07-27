<?php

/**
 * @file
 * WF log controller class.
 */

class WfLogController extends WfEntityAPIController {

  /**
   * {@inheritdoc}
   */
  public function create(array $values = array()) {
    $values += array(
      'uid' => $GLOBALS['user']->uid,
      'created' => REQUEST_TIME,
    );

    return parent::create($values);
  }
}
