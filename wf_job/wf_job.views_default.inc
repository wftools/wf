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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Workflow Job: Assignee */
  $handler->display->display_options['relationships']['assigned']['id'] = 'assigned';
  $handler->display->display_options['relationships']['assigned']['table'] = 'wf_job';
  $handler->display->display_options['relationships']['assigned']['field'] = 'assigned';
  $handler->display->display_options['relationships']['assigned']['label'] = 'Assignee';
  $handler->display->display_options['relationships']['assigned']['required'] = 0;
  /* Relationship: Workflow Job: Owner */
  $handler->display->display_options['relationships']['owner']['id'] = 'owner';
  $handler->display->display_options['relationships']['owner']['table'] = 'wf_job';
  $handler->display->display_options['relationships']['owner']['field'] = 'owner';
  $handler->display->display_options['relationships']['owner']['label'] = 'Owner';
  $handler->display->display_options['relationships']['owner']['required'] = 0;
  /* Field: Workflow Job: ID */
  $handler->display->display_options['fields']['jid']['id'] = 'jid';
  $handler->display->display_options['fields']['jid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jid']['field'] = 'jid';
  $handler->display->display_options['fields']['jid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['jid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['jid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['jid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['jid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['jid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['jid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['jid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['jid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['jid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['jid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['jid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['jid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['jid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['jid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['jid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['jid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['jid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['jid']['format_plural'] = 0;
  /* Field: Workflow Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'wf_job';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'assigned';
  $handler->display->display_options['fields']['realname']['label'] = 'Assignee';
  $handler->display->display_options['fields']['realname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['realname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['realname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['realname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['realname']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['realname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['realname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['realname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['realname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['realname']['link_to_user'] = 1;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname_1']['id'] = 'realname_1';
  $handler->display->display_options['fields']['realname_1']['table'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['field'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['relationship'] = 'owner';
  $handler->display->display_options['fields']['realname_1']['label'] = 'Owner';
  $handler->display->display_options['fields']['realname_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['realname_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['realname_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['realname_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['realname_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['realname_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['realname_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['realname_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['realname_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['realname_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['realname_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['realname_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['realname_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['realname_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['realname_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['realname_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['realname_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['realname_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['realname_1']['link_to_user'] = 1;
  /* Field: Workflow Job: Status */
  $handler->display->display_options['fields']['jsid']['id'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jsid']['field'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['jsid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['jsid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['jsid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['jsid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['jsid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['jsid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['jsid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['jsid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['jsid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['jsid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['jsid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['jsid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['jsid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['jsid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['jsid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['jsid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['jsid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['jsid']['machine_name'] = 0;
  /* Field: Workflow Job: Delete Link */
  $handler->display->display_options['fields']['delete_wf_job']['id'] = 'delete_wf_job';
  $handler->display->display_options['fields']['delete_wf_job']['table'] = 'wf_job';
  $handler->display->display_options['fields']['delete_wf_job']['field'] = 'delete_wf_job';
  $handler->display->display_options['fields']['delete_wf_job']['label'] = 'Operations';
  $handler->display->display_options['fields']['delete_wf_job']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['delete_wf_job']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_wf_job']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_wf_job']['hide_alter_empty'] = 1;
  /* Field: Workflow Job: Edit Link */
  $handler->display->display_options['fields']['edit_wf_job']['id'] = 'edit_wf_job';
  $handler->display->display_options['fields']['edit_wf_job']['table'] = 'wf_job';
  $handler->display->display_options['fields']['edit_wf_job']['field'] = 'edit_wf_job';
  $handler->display->display_options['fields']['edit_wf_job']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_wf_job']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_wf_job']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_wf_job']['hide_alter_empty'] = 1;
  /* Field: Workflow Job: Login Link */
  $handler->display->display_options['fields']['login_wf_job']['id'] = 'login_wf_job';
  $handler->display->display_options['fields']['login_wf_job']['table'] = 'wf_job';
  $handler->display->display_options['fields']['login_wf_job']['field'] = 'login_wf_job';
  $handler->display->display_options['fields']['login_wf_job']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['alter']['external'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['login_wf_job']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['login_wf_job']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['alter']['html'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['login_wf_job']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['login_wf_job']['hide_empty'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['empty_zero'] = 0;
  $handler->display->display_options['fields']['login_wf_job']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
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
  $handler->display->display_options['filters']['jsid']['expose']['reduce'] = 0;

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

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
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
  );
  $handler->display->display_options['filters']['permission']['exposed'] = TRUE;
  $handler->display->display_options['filters']['permission']['expose']['operator_id'] = 'permission_op';
  $handler->display->display_options['filters']['permission']['expose']['label'] = 'Permission';
  $handler->display->display_options['filters']['permission']['expose']['operator'] = 'permission_op';
  $handler->display->display_options['filters']['permission']['expose']['identifier'] = 'permission';
  $handler->display->display_options['filters']['permission']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['permission']['reduce_duplicates'] = TRUE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['job_users'] = $view;

  return $export;
}

