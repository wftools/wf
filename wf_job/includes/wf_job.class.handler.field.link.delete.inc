<?php
/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 */

/**
 * Class which handles displaying of delete links.
 */
class WfJobHandlerFieldLinkDelete extends WfJobHandlerFieldLink {

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $job_id = $values->{$this->aliases['jid']};
    return $this->wf_job_render_link($job_id, t('Delete'), 'delete');
  }
}
