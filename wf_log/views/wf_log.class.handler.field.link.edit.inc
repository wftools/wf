<?php
/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */

/**
 * Class which handles displaying of edit links.
 */
class WfLogHandlerFieldLinkEdit extends WfLogHandlerFieldLink {
  /**
   * Method to make a new render to related field.
   * @see WfLogHandlerFieldLink::render()
   */
  function render($values) {
    $type = 'wf_log';
    $dummy_wf_log = (object) array('type' => $type);
    if (!wf_log_access('edit', $dummy_wf_log)) {
      return;
    }
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $wf_log_id = $values->{$this->aliases['lid']};

    return l($text, 'wf-log/' . $wf_log_id . '/edit');
  }

}
