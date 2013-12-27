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
  function render($values) {
    $job_id = $values->{$this->aliases['jid']};
    return $this->wf_job_render_link($job_id, t('Login'), 'login');
  }
}
