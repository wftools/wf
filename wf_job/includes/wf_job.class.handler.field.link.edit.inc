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
  public function render($values) {
    $job_id = $values->{$this->aliases['jid']};
    return $this->wf_job_render_link($job_id, t('Edit'), 'edit');
  }
}
