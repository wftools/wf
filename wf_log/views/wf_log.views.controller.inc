<?php
/**
 * @file
 * WF log entity Views controller.
 */

/**
 * Workflow log Views Controller.
 */
class WfLogViewsController extends EntityDefaultViewsController {

  /**
   * Add extra fields to views_data().
   */
  public function views_data() {
    $data = parent::views_data();
    $data['wf_log']['link_wf_log'] = array(
      'field' => array(
        'title' => t('Link'),
        'help' => t('Provide a link to the log.'),
        'handler' => 'WfLogHandlerFieldLink',
      ),
    );
    $data['wf_log']['edit_wf_log'] = array(
      'field' => array(
        'title' => t('Edit Link'),
        'help' => t('Provide a link to the edit form for the log.'),
        'handler' => 'WfLogHandlerFieldLinkEdit',
      ),
    );
    $data['wf_log']['delete_wf_log'] = array(
      'field' => array(
        'title' => t('Delete Link'),
        'help' => t('Provide a link to delete the log.'),
        'handler' => 'WfLogHandlerFieldLinkDelete',
      ),
    );
    $data['wf_log']['entity_id'] = array(
      'field' => array(
        'title' => t('Entity ID'),
        'help' => t('Provides the ID of the entity in which the log belongs.'),
        'handler' => 'WfLogHandlerFieldEntityID',
      ),
    );

    return $data;
  }
}
