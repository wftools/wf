<?php
/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */

 /**
 * Class which handles displaying of edit links.
 */
class WfJobHandlerFieldLinkEdit extends WfJobHandlerFieldLink {

  /**
   * {@inheritdoc}
   */
  protected $handler_action_type = 'edit';

  /**
   * {@inheritdoc}
   */
  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $wf_job_id = $values->{$this->aliases['jid']};
    return l($text, 'job/' . $wf_job_id . '/edit');
  }
}
