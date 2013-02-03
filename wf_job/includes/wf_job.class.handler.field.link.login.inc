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

  function construct() {
    parent::construct();
  }

  function render($values) {
    $type = 'wf_job';
    $dummy_wf_job = (object) array('type' => $type);
    if (!wf_job_access('login', $dummy_wf_job)) {
      return;
    }
    $text = !empty($this->options['text']) ? $this->options['text'] : t('login');
    $wf_job_id = $values->{$this->aliases['jid']};
    return l($text, 'job/' . $wf_job_id . '/login');
  }

}
