<?php
/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */

/**
 * Class which handles displaying of links.
 */
class WfLogHandlerFieldLink extends views_handler_field {

  /**
   * Implements method __construct().
   * @see views_handler_field::construct()
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['lid'] = 'lid';
  }

  /**
   * Information about options for all kinds of purposes will be held here.
   * @see views_handler_field::option_definition()
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  /**
   * Build the options form.
   * @see views_handler_field::options_form()
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
   * Adds the field to a query.
   * @see views_handler_field::query()
   */
  public function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Method to make a new render to related field.
   * @see views_handler_field::render()
   */
  public function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $wf_log_id = $values->{$this->aliases['lid']};
    return l($text, 'wf-log/' . $wf_log_id);
  }
}
