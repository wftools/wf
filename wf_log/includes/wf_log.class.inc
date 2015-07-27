<?php

/**
 * @file
 * WF Log class.
 */

class WfLog extends Entity {
  /**
   * Entity Bundle's name.
   *
   * @var string
   */
  public $bundle = 'log';

  /**
   * Timestamp regarding created time of log entry.
   *
   * @var int
   */
  public $created;

  /**
   * Entity ID on which the log will be related.
   *
   * @var int
   */
  public $entity;

  /**
   * Entity Type on which the log will be related.
   *
   * @var string
   */
  public $entity_type;

  /**
   * Log ID.
   *
   * @var int
   */
  public $lid;

  /**
   * Log's message body.
   *
   * @var string
   */
  public $message_body;

  /**
   * Log's message summary.
   *
   * @var string
   */
  public $message_summary;

  /**
   * Machine name of type of message.
   *
   * @var string
   */
  public $message_type;

  /**
   * User ID.
   *
   * @var int
   */
  public $uid;

  /**
   * Unique ID hash.
   *
   * @var string
   */
  public $uuid;

  /**
   * Creates a new entity.
   *
   * @see entity_create()
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, 'wf_log');
  }

  /**
   * Build up the view content.
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {
    $content = array();
    $content['lid'] = array(
      '#theme' => 'field',
      '#title' => t('Log ID'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => $langcode,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'int',
      '#label_display' => 'above',
      '#entity_type' => 'wf_log',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $this->lid)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->lid),
    );

    $content['entity_type'] = array(
      '#theme' => 'field',
      '#title' => t('Entity type'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => $langcode,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'int',
      '#label_display' => 'above',
      '#entity_type' => 'wf_log',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $this->entity_type)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->entity_type),
    );

    $content['entity'] = array(
      '#theme' => 'field',
      '#title' => t('Entity ID'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => $langcode,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_log',
      '#bundle' => $this->entity,
      '#items' => array(array('value' => $this->entity)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->entity),
    );

    $content['message_summary'] = array(
      '#theme' => 'field',
      '#title' => t('Message summary'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => $langcode,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_log',
      '#bundle' => $this->message_summary,
      '#items' => array(array('value' => $this->message_summary)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->message_summary),
    );

    $content['message_body'] = array(
      '#theme' => 'field',
      '#title' => t('Message body'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => $langcode,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_log',
      '#bundle' => $this->message_body,
      '#items' => array(array('value' => $this->message_body)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->message_body),
    );

    $content['message_type'] = array(
      '#theme' => 'field',
      '#title' => t('Message type'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => $langcode,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_log',
      '#bundle' => $this->message_type,
      '#items' => array(array('value' => $this->message_type)),
      '#formatter' => 'text_default',
      0 => array('#markup' => $this->message_type),
    );

    $user_name = entity_label('user', user_load($this->uid));
    $content['uid'] = array(
      '#theme' => 'field',
      '#title' => t('Owner'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => $langcode,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'int',
      '#label_display' => 'above',
      '#entity_type' => 'wf_log',
      '#bundle' => $this->bundle,
      '#items' => array(array('value' => $user_name)),
      '#formatter' => 'text_default',
      0 => array('#markup' => l($user_name, 'user/' . $this->uid)),
    );

    $created_date = format_date($this->created);
    $content['created'] = array(
      '#theme' => 'field',
      '#title' => t('Created'),
      '#access' => TRUE,
      '#view_mode' => $view_mode,
      '#language' => $langcode,
      '#field_name' => 'field_fake_description',
      '#field_type' => 'text',
      '#label_display' => 'above',
      '#entity_type' => 'wf_log',
      '#bundle' => $this->bundle,
      '#items' => array($created_date),
      '#formatter' => 'text_default',
      0 => array('#markup' => $created_date),
    );

    return entity_get_controller($this->entityType)->buildContent($this, $view_mode, $langcode, $content);
  }

  /**
   * Generates the URI for the entity.
   */
  public function defaultUri() {
    return array('path' => 'wf-log/' . $this->identifier());
  }

  /**
   * Generates the title for the entity.
   */
  public function label() {
    return $this->message_summary;
  }
}
