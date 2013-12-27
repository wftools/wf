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
    $job_id = $values->{$this->aliases['jid']};
    return $this->wf_job_render_link($job_id, t('View'));
  }

  /**
   * Generate the base job view URI.
   *
   * @param int $job_id
   *  The job id to generate the URI for.
   *
   * @return string
   *  The generated URI.
   */
  protected function wf_job_render_link($job_id, $default_text, $action = '') {
    $job = entity_load_single('wf_job', $job_id);
    if (!$job) {
      return '';
    }

    if (!wf_job_access($action, $job)) {
      return '';
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : $default_text;
    $job_id = (int) $job_id;

    $path = "job/{$job_id}";
    if ($action) {
      $path .= "/{$action}";
    }

    return l($text, $path);
  }
}
