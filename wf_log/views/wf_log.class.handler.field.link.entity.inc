<?php
/**
 * @file
 * Contains a Views field handler to take care of displaying related entity ID.
 */

/**
 * Class which handles displaying of related entity ID.
 */
class WfLogHandlerFieldEntityID extends WfLogHandlerFieldLink {
  /**
   * Method to make a new render to related field.
   * @see WfLogHandlerFieldLink::render()
   */
  public function render($values) {
    $entity_log = wf_log_load($values->lid);
    $entity_id = $entity_log->entity;

    return $entity_id;
  }
}
