<?php
/**
 * @file
 * wf_job_generic.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function wf_job_generic_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'reply-job_comments-field_comment_body'
  $field_instances['reply-job_comments-field_comment_body'] = array(
    'bundle' => 'job_comments',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Body of the comment.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_comment_body',
    'label' => 'Comment',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'reply-job_comments-field_comment_title'
  $field_instances['reply-job_comments-field_comment_title'] = array(
    'bundle' => 'job_comments',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_comment_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'wf_job-job-field_comment'
  $field_instances['wf_job-job-field_comment'] = array(
    'bundle' => 'job',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'reply',
        'settings' => array(),
        'type' => 'reply_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'wf_job',
    'field_name' => 'field_comment',
    'label' => 'Comment',
    'required' => 0,
    'settings' => array(
      'access' => -1,
      'allow_reply' => -1,
      'display' => -1,
      'form' => -1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'reply',
      'settings' => array(),
      'type' => 'reply',
      'weight' => -38,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body of the comment.');
  t('Comment');
  t('Title');

  return $field_instances;
}
