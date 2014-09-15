<?php
/**
 * @file
 * wf_job.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function wf_job_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'job_list';
  $view->description = 'Lists all jobs.';
  $view->tag = 'default';
  $view->base_table = 'wf_job';
  $view->human_name = 'Job list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Job list';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage jobs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'jid' => 'jid',
    'title' => 'title',
    'realname' => 'realname',
    'realname_1' => 'realname_1',
    'jsid' => 'jsid',
    'delete_wf_job' => 'delete_wf_job',
    'edit_wf_job' => 'delete_wf_job',
    'login_wf_job' => 'delete_wf_job',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'jid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'jsid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_wf_job' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'edit_wf_job' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'login_wf_job' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Workflow Job: Assignee */
  $handler->display->display_options['relationships']['assigned']['id'] = 'assigned';
  $handler->display->display_options['relationships']['assigned']['table'] = 'wf_job';
  $handler->display->display_options['relationships']['assigned']['field'] = 'assigned';
  $handler->display->display_options['relationships']['assigned']['label'] = 'Assignee';
  /* Relationship: Workflow Job: Owner */
  $handler->display->display_options['relationships']['owner']['id'] = 'owner';
  $handler->display->display_options['relationships']['owner']['table'] = 'wf_job';
  $handler->display->display_options['relationships']['owner']['field'] = 'owner';
  $handler->display->display_options['relationships']['owner']['label'] = 'Owner';
  /* Field: Workflow Job: ID */
  $handler->display->display_options['fields']['jid']['id'] = 'jid';
  $handler->display->display_options['fields']['jid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jid']['field'] = 'jid';
  $handler->display->display_options['fields']['jid']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'wf_job';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'assigned';
  $handler->display->display_options['fields']['realname']['label'] = 'Assignee';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname_1']['id'] = 'realname_1';
  $handler->display->display_options['fields']['realname_1']['table'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['field'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['relationship'] = 'owner';
  $handler->display->display_options['fields']['realname_1']['label'] = 'Owner';
  /* Field: Workflow Job: Status */
  $handler->display->display_options['fields']['jsid']['id'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jsid']['field'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Delete Link */
  $handler->display->display_options['fields']['delete_wf_job']['id'] = 'delete_wf_job';
  $handler->display->display_options['fields']['delete_wf_job']['table'] = 'wf_job';
  $handler->display->display_options['fields']['delete_wf_job']['field'] = 'delete_wf_job';
  $handler->display->display_options['fields']['delete_wf_job']['label'] = 'Operations';
  /* Field: Workflow Job: Edit Link */
  $handler->display->display_options['fields']['edit_wf_job']['id'] = 'edit_wf_job';
  $handler->display->display_options['fields']['edit_wf_job']['table'] = 'wf_job';
  $handler->display->display_options['fields']['edit_wf_job']['field'] = 'edit_wf_job';
  /* Field: Workflow Job: Login Link */
  $handler->display->display_options['fields']['login_wf_job']['id'] = 'login_wf_job';
  $handler->display->display_options['fields']['login_wf_job']['table'] = 'wf_job';
  $handler->display->display_options['fields']['login_wf_job']['field'] = 'login_wf_job';
  /* Sort criterion: Workflow Job: ID */
  $handler->display->display_options['sorts']['jid']['id'] = 'jid';
  $handler->display->display_options['sorts']['jid']['table'] = 'wf_job';
  $handler->display->display_options['sorts']['jid']['field'] = 'jid';
  $handler->display->display_options['sorts']['jid']['order'] = 'DESC';
  /* Filter criterion: Workflow Job: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'wf_job';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: Workflow Job: Status */
  $handler->display->display_options['filters']['jsid']['id'] = 'jsid';
  $handler->display->display_options['filters']['jsid']['table'] = 'wf_job';
  $handler->display->display_options['filters']['jsid']['field'] = 'jsid';
  $handler->display->display_options['filters']['jsid']['group'] = 1;
  $handler->display->display_options['filters']['jsid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['jsid']['expose']['operator_id'] = 'jsid_op';
  $handler->display->display_options['filters']['jsid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['jsid']['expose']['operator'] = 'jsid_op';
  $handler->display->display_options['filters']['jsid']['expose']['identifier'] = 'jsid';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/jobs';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Jobs';
  $handler->display->display_options['menu']['description'] = 'List jobs.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['job_list'] = $view;

  $view = new view;
  $view->name = 'job_users';
  $view->description = 'List users which can be assigned to jobs.';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Job users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Job users';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['empty'] = '[name]';
  $handler->display->display_options['fields']['realname']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['realname']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Realname: Real name */
  $handler->display->display_options['sorts']['realname']['id'] = 'realname';
  $handler->display->display_options['sorts']['realname']['table'] = 'realname';
  $handler->display->display_options['sorts']['realname']['field'] = 'realname';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Permission */
  $handler->display->display_options['filters']['permission']['id'] = 'permission';
  $handler->display->display_options['filters']['permission']['table'] = 'role_permission';
  $handler->display->display_options['filters']['permission']['field'] = 'permission';
  $handler->display->display_options['filters']['permission']['value'] = array(
    'manage jobs' => 'manage jobs',
    'view own job job' => 'view own job job',
    'view any job job' => 'view any job job',
    'rewiew job before integratio' => 'rewiew job before integration',
    'rewiew job before prod' => 'rewiew job before prod',
    'rewiew job before stage' => 'rewiew job before stage',
    'propose job for integration' => 'propose job for integration',
    'propose job for prod' => 'propose job for prod',
    'propose job for stage' => 'propose job for stage',
  );
  $handler->display->display_options['filters']['permission']['exposed'] = TRUE;
  $handler->display->display_options['filters']['permission']['expose']['operator_id'] = 'permission_op';
  $handler->display->display_options['filters']['permission']['expose']['label'] = 'Permission';
  $handler->display->display_options['filters']['permission']['expose']['operator'] = 'permission_op';
  $handler->display->display_options['filters']['permission']['expose']['identifier'] = 'permission';
  $handler->display->display_options['filters']['permission']['reduce_duplicates'] = TRUE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['job_users'] = $view;

  return $export;
}
