<?php
/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */

 /**
 * Class which handles displaying of links.
 */
class WfJobHandlerFieldLink extends views_handler_field {

  /**
   * Indicates the access check action type for this handler.
   * @var string
   */
  protected $handler_action_type = NULL;

  /**
   * {@inheritdoc}
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['jid'] = 'jid';
  }

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $wf_job_id = $values->{$this->aliases['jid']};
    return l($text, 'job/' . $wf_job_id);
  }

  /**
   * {@inheritdoc}
   */
  public function access() {
    $jid = $values->{$this->aliases['jid']};
    $result = entity_load('wf_job', array($jid));
    $job = reset($result);
    return wf_job_access($job, $this->handler_action_type);
  }
}
