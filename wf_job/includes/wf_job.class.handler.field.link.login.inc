<?php
/**
 * @file
 * Contains a Views field handler to take care of displaying login links
 * as fields
 */

/**
 * Class which handles displaying of delete links.
 */
class WfJobHandlerFieldLinkLogin extends WfJobHandlerFieldLink {

  /**
   * {@inheritdoc}
   */
  protected $handler_action_type = 'login';

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('login');
    $wf_job_id = $values->{$this->aliases['jid']};
    return l($text, 'job/' . $wf_job_id . '/login');
  }
}
