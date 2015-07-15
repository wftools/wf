---------------------
CONTENTS OF THIS FILE
---------------------
 * Introduction
 * Usage

------------
INTRODUCTION
------------
This module provides a simple way to expose entity properties in the field UI's
"Manage fields" and "Manage display".

-----
USAGE
-----
To expose your own entity properties, do the following steps:

1- First step:
  Add the extra fields controller class (EntityPropertyExtraFieldsController)
  to the entity info that contains the properties that you want to expose.
  You can do this just adding a new key in your hook_entity_info(), or you can 
  implement a hook_entity_info_alter().
  
  'extra fields controller class' => 'EntityPropertyExtraFieldsController'
  
  Ref. https://www.drupal.org/node/2220557

2- Second step:
  Add a new option on the entity property declaration that you want to expose, 
  can be on hook_entity_property_info() or hook_entity_property_info_alter().
  
  examples:
  // Exposes in "Manage fields" UI form. 
  'extra_fields' => array('form'),
  
  // Exposes in "Manage display" UI form.
  'extra_fields' => array('display'),
  
  // Exposes in both, "Manage fields" and "Manage display" UI forms.
  'extra_fields' => array('form', 'display'),
  
  Like:
    $properties['vid'] = array(
      'label' => t('Revision ID'),
      'type' => 'integer',
      'description' => t('The unique revision identifier.'),
      'schema field' => 'vid',
      'extra_fields' => array('form', 'display'),
    );
