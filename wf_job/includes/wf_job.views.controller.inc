<?php

/**
 * Workflow Job Views Controller.
 */
class WfJobViewsController extends EntityDefaultViewsController {

  /**
   * Add extra fields to views_data().
   */
  public function views_data() {
    $data = parent::views_data();
    $data['wf_job']['link_wf_job'] = array(
      'field' => array(
        'title' => t('Link'),
        'help' => t('Provide a link to the job.'),
        'handler' => 'WfJobHandlerFieldLink',
      ),
    );
    $data['wf_job']['edit_wf_job'] = array(
      'field' => array(
        'title' => t('Edit Link'),
        'help' => t('Provide a link to the edit form for the job.'),
        'handler' => 'WfJobHandlerFieldLinkEdit',
      ),
    );
    $data['wf_job']['delete_wf_job'] = array(
      'field' => array(
        'title' => t('Delete Link'),
        'help' => t('Provide a link to delete the job.'),
        'handler' => 'WfJobHandlerFieldLinkDelete',
      ),
    );
    $data['wf_job']['login_wf_job'] = array(
      'field' => array(
        'title' => t('Login Link'),
        'help' => t('Provide a link to login into the job.'),
        'handler' => 'WfJobHandlerFieldLinkLogin',
      ),
    );
    return $data;
  }
}
