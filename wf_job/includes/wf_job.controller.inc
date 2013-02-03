<?php

/**
 * @file
 * Workflow job controller class.
 */

class WfJobController extends TecController {

  /**
   * Builds a structured array representing the entity's content.
   *
   * The content built for the entity will vary depending on the $view_mode
   * parameter.
   *
   * @param $entity
   *   An entity object.
   * @param $view_mode
   *   View mode, e.g. 'full', 'teaser'...
   * @param $langcode
   *   (optional) A language code to use for rendering. Defaults to the global
   *   content language of the current request.
   * @return
   *   The renderable array.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $page = TRUE) {

    $entity->content = array();
    $entity->content += array(
      '#theme' => 'wf_job',
      '#job' => $entity,
      '#view_mode' => $view_mode,
      '#language' => $langcode,
    );

    $langcode = isset($langcode) ? $langcode : $GLOBALS['language_content']->language;

    // Add in fields.
    if (!empty($this->entityInfo['fieldable'])) {
      $entity->content += field_attach_view($this->entityType, $entity, $view_mode, $langcode);
    }

    if (module_exists('rules')) {
      // Invoke hook_ENTITY_view() to allow modules to add their additions.
      rules_invoke_all($this->entityType . '_view', $entity, $view_mode, $langcode);
    }

    // Invoke the more generic hook_entity_view() to allow the same.
    module_invoke_all('entity_view', $entity, $this->entityType, $view_mode, $langcode);

    // Remove the build array information from the entity and return it.
    $build = $entity->content;
    unset($entity->content);

    return $build;
  }

}

