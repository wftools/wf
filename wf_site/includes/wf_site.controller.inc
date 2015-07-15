<?php

/**
 * @file
 * Workflow site controller class.
 */

class WfSiteController extends WfEntityAPIController {

  /**
   * {@inheritdoc}
   */
  public function create(array $values = array()) {
    $values += array(
      'active' => TRUE,
      'is_new' => TRUE,
      'default_revision' => TRUE,
    );

    return parent::create($values);
  }
}
