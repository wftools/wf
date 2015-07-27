<?php

/**
 * @file
 * WF Entity API controller class.
 */

class WfEntityAPIController extends EntityAPIController {

  /**
   * Builds a structured array representing the entity's content.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $page = TRUE) {
    $content = parent::buildContent($entity, $view_mode, $langcode);

    foreach ($content as $field => &$info) {
      $is_field = is_array($info) && '#' !== $field[0];
      // Iterates over every fields and properties.
      if (!$is_field) {
        continue;
      }

      // Gets properties only.
      // Also, don't do this for entity references,
      // let their own controller handle this.
      $is_property = isset($info['#theme']) && 'entity_property' == $info['#theme'];
      $is_entityreference = isset($info['#field_type']) && 'entityreference' == $info['#field_type'];
      if (!$is_property || $is_entityreference) {
        continue;
      }

      // This forces all properties to be displayed with text formatting
      // and inline label.
      $info['#label_display'] = 'inline';
      $info['#theme'] = 'field';
      $info['#title'] = $info['#label'];
      $info['#field_name'] = $info['#property_name'];
      $info['#bundle'] = $entity->bundle;
      $info['#view_mode'] = $view_mode;
      $info['#field_type'] = 'text';
      $info['#formatter'] = 'text_default';

      $properties_info = entity_get_property_info($info['#entity_type']);
      $property_type = $properties_info['properties'][$field]['type'];

      // Gets the actual value for that property.
      $wrapped_entity = $info['#entity_wrapped']->value();

      // Removes empty properties.
      if (!isset($wrapped_entity->{$field}) || '' == $wrapped_entity->{$field}) {
        unset($content[$field]);
        continue;
      }
      $value = $wrapped_entity->{$field};

      // Formats based on the property type.
      switch ($property_type) {
        case 'boolean':
          $formatted_value = $value ? t('Yes') : t('No');
          break;

        case 'date':
          if (0 == $value) {
            unset($content[$field]);
            continue;
          }
          $formatted_value = format_date($value);
          break;

        case 'user':
          $user = user_load($value);
          $formatted_value = format_username($user);
          break;

        default:
          $formatted_value = filter_xss($value);
      }

      $info['#items'] = array(array('value' => $formatted_value));
      $info[0] = array('#markup' => $formatted_value);
    }
    return $content;
  }
}
