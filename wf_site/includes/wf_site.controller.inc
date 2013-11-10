<?php

/**
 * @file
 * Workflow site controller class.
 */

class WfSiteController extends EntityAPIController {

  /**
   * @overridden
   */
  public function create(array $values = array()) {
    $values += array(
	    'active' => TRUE,
	    'blocked' => FALSE,
	    'is_new' => TRUE,
	    'default_revision' => TRUE,
	  );

    return parent::create($values);
  }
}
