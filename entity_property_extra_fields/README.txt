CONTENTS OF THIS FILE
---------------------
 * Introduction
 * Usage

INTRODUCTION
------------
This module provides a simple way to expose entity properties in the field UI's
"Manage fields" and "Manage display".

To more details, check API documentation of hook_field_extra_fields().

USAGE
-----
Instead of implementing the hook_field_extra_fields() and define its structure
for each entity and property, just add/modify hook_entity_property_info() or 
hook_entity_property_info_alter() adding a new option, that the module provides
to the properties that you want to expose in form fields UI's:

// Exposes in "Manage fields" UI form. 
'extra_fields' => array('form')

OR

// Exposes in "Manage display" UI form.
'extra_fields' => array('display')

OR

// Exposes in both, "Manage fields" and "Manage display" UI forms.
'extra_fields' => array('form', 'display')
