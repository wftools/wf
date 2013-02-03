<?php
/**
 * @file
 * wf_job_generic.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function wf_job_generic_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'jobs';
  $view->description = 'Workflow Jobs';
  $view->tag = 'default';
  $view->base_table = 'wf_job';
  $view->human_name = 'Jobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Jobs Assigned to me';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access jobs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'jid' => 'jid',
    'reference' => 'reference',
    'title' => 'title',
    'jsid' => 'jsid',
    'realname_1' => 'realname_1',
    'modified' => 'modified',
  );
  $handler->display->display_options['style_options']['default'] = 'modified';
  $handler->display->display_options['style_options']['info'] = array(
    'jid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'reference' => array(
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
    'jsid' => array(
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
    'modified' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Workflow Job: Assignee */
  $handler->display->display_options['relationships']['assigned']['id'] = 'assigned';
  $handler->display->display_options['relationships']['assigned']['table'] = 'wf_job';
  $handler->display->display_options['relationships']['assigned']['field'] = 'assigned';
  $handler->display->display_options['relationships']['assigned']['label'] = 'Assigned User';
  /* Relationship: Workflow Job: Owner */
  $handler->display->display_options['relationships']['owner']['id'] = 'owner';
  $handler->display->display_options['relationships']['owner']['table'] = 'wf_job';
  $handler->display->display_options['relationships']['owner']['field'] = 'owner';
  $handler->display->display_options['relationships']['owner']['label'] = 'Owner User';
  /* Relationship: Workflow Job: Environment */
  $handler->display->display_options['relationships']['eid']['id'] = 'eid';
  $handler->display->display_options['relationships']['eid']['table'] = 'wf_job';
  $handler->display->display_options['relationships']['eid']['field'] = 'eid';
  $handler->display->display_options['relationships']['eid']['label'] = 'Job Environment';
  /* Field: Workflow Job: ID */
  $handler->display->display_options['fields']['jid']['id'] = 'jid';
  $handler->display->display_options['fields']['jid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jid']['field'] = 'jid';
  $handler->display->display_options['fields']['jid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['jid']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['jid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['jid']['separator'] = '';
  /* Field: Workflow Job: External Reference */
  $handler->display->display_options['fields']['reference']['id'] = 'reference';
  $handler->display->display_options['fields']['reference']['table'] = 'wf_job';
  $handler->display->display_options['fields']['reference']['field'] = 'reference';
  $handler->display->display_options['fields']['reference']['label'] = 'Reference';
  $handler->display->display_options['fields']['reference']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'wf_job';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Status */
  $handler->display->display_options['fields']['jsid']['id'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jsid']['field'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['element_label_colon'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'assigned';
  $handler->display->display_options['fields']['realname']['label'] = 'Assigned';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname_1']['id'] = 'realname_1';
  $handler->display->display_options['fields']['realname_1']['table'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['field'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['relationship'] = 'owner';
  $handler->display->display_options['fields']['realname_1']['label'] = 'Owner';
  $handler->display->display_options['fields']['realname_1']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Modified */
  $handler->display->display_options['fields']['modified']['id'] = 'modified';
  $handler->display->display_options['fields']['modified']['table'] = 'wf_job';
  $handler->display->display_options['fields']['modified']['field'] = 'modified';
  $handler->display->display_options['fields']['modified']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['modified']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['modified']['date_format'] = 'short';
  /* Sort criterion: Workflow Job: Modified */
  $handler->display->display_options['sorts']['modified']['id'] = 'modified';
  $handler->display->display_options['sorts']['modified']['table'] = 'wf_job';
  $handler->display->display_options['sorts']['modified']['field'] = 'modified';
  $handler->display->display_options['sorts']['modified']['order'] = 'DESC';
  /* Contextual filter: Workflow Job: Assignee */
  $handler->display->display_options['arguments']['assigned']['id'] = 'assigned';
  $handler->display->display_options['arguments']['assigned']['table'] = 'wf_job';
  $handler->display->display_options['arguments']['assigned']['field'] = 'assigned';
  $handler->display->display_options['arguments']['assigned']['default_action'] = 'default';
  $handler->display->display_options['arguments']['assigned']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['assigned']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['assigned']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['assigned']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Workflow Job: Status */
  $handler->display->display_options['filters']['jsid']['id'] = 'jsid';
  $handler->display->display_options['filters']['jsid']['table'] = 'wf_job';
  $handler->display->display_options['filters']['jsid']['field'] = 'jsid';
  $handler->display->display_options['filters']['jsid']['operator'] = 'not in';
  $handler->display->display_options['filters']['jsid']['value'] = array(
    5 => '5',
  );

  /* Display: My Jobs (block) */
  $handler = $view->new_display('block', 'My Jobs (block)', 'my_jobs_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Jobs';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Workflow Job: ID */
  $handler->display->display_options['fields']['jid']['id'] = 'jid';
  $handler->display->display_options['fields']['jid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jid']['field'] = 'jid';
  $handler->display->display_options['fields']['jid']['label'] = '';
  $handler->display->display_options['fields']['jid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['jid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['jid']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['jid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['jid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['jid']['separator'] = '';
  /* Field: Workflow Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'wf_job';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Status */
  $handler->display->display_options['fields']['jsid']['id'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jsid']['field'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['label'] = '';
  $handler->display->display_options['fields']['jsid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['jsid']['alter']['text'] = '[jid]: [title] ([jsid])';
  $handler->display->display_options['fields']['jsid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['jsid']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['jsid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Workflow Job: Modified */
  $handler->display->display_options['sorts']['modified']['id'] = 'modified';
  $handler->display->display_options['sorts']['modified']['table'] = 'wf_job';
  $handler->display->display_options['sorts']['modified']['field'] = 'modified';
  $handler->display->display_options['sorts']['modified']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Workflow Job: Owner */
  $handler->display->display_options['arguments']['owner']['id'] = 'owner';
  $handler->display->display_options['arguments']['owner']['table'] = 'wf_job';
  $handler->display->display_options['arguments']['owner']['field'] = 'owner';
  $handler->display->display_options['arguments']['owner']['default_action'] = 'default';
  $handler->display->display_options['arguments']['owner']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['owner']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['owner']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['owner']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'My Jobs';

  /* Display: My Jobs */
  $handler = $view->new_display('page', 'My Jobs', 'my_jobs_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Jobs';
  $handler->display->display_options['display_description'] = 'List of jobs owned by the current user.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Workflow Job: ID */
  $handler->display->display_options['fields']['jid']['id'] = 'jid';
  $handler->display->display_options['fields']['jid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jid']['field'] = 'jid';
  $handler->display->display_options['fields']['jid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['jid']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['jid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['jid']['separator'] = '';
  /* Field: Workflow Job: External Reference */
  $handler->display->display_options['fields']['reference']['id'] = 'reference';
  $handler->display->display_options['fields']['reference']['table'] = 'wf_job';
  $handler->display->display_options['fields']['reference']['field'] = 'reference';
  $handler->display->display_options['fields']['reference']['label'] = 'Reference';
  $handler->display->display_options['fields']['reference']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'wf_job';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Status */
  $handler->display->display_options['fields']['jsid']['id'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jsid']['field'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['element_label_colon'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'assigned';
  $handler->display->display_options['fields']['realname']['label'] = 'Assigned';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Modified */
  $handler->display->display_options['fields']['modified']['id'] = 'modified';
  $handler->display->display_options['fields']['modified']['table'] = 'wf_job';
  $handler->display->display_options['fields']['modified']['field'] = 'modified';
  $handler->display->display_options['fields']['modified']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['modified']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['modified']['date_format'] = 'short';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Workflow Job: Owner */
  $handler->display->display_options['arguments']['owner']['id'] = 'owner';
  $handler->display->display_options['arguments']['owner']['table'] = 'wf_job';
  $handler->display->display_options['arguments']['owner']['field'] = 'owner';
  $handler->display->display_options['arguments']['owner']['default_action'] = 'default';
  $handler->display->display_options['arguments']['owner']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['owner']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['owner']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['owner']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'jobs/my';

  /* Display: Assigned jobs */
  $handler = $view->new_display('page', 'Assigned jobs', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Jobs Assigned to me';
  $handler->display->display_options['display_description'] = 'List of jobs assigned to the current user.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Workflow Job: ID */
  $handler->display->display_options['fields']['jid']['id'] = 'jid';
  $handler->display->display_options['fields']['jid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jid']['field'] = 'jid';
  $handler->display->display_options['fields']['jid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['jid']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['jid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['jid']['separator'] = '';
  /* Field: Workflow Job: External Reference */
  $handler->display->display_options['fields']['reference']['id'] = 'reference';
  $handler->display->display_options['fields']['reference']['table'] = 'wf_job';
  $handler->display->display_options['fields']['reference']['field'] = 'reference';
  $handler->display->display_options['fields']['reference']['label'] = 'Reference';
  $handler->display->display_options['fields']['reference']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'wf_job';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Status */
  $handler->display->display_options['fields']['jsid']['id'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jsid']['field'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['element_label_colon'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname_1']['id'] = 'realname_1';
  $handler->display->display_options['fields']['realname_1']['table'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['field'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['relationship'] = 'owner';
  $handler->display->display_options['fields']['realname_1']['label'] = 'Owner';
  $handler->display->display_options['fields']['realname_1']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Modified */
  $handler->display->display_options['fields']['modified']['id'] = 'modified';
  $handler->display->display_options['fields']['modified']['table'] = 'wf_job';
  $handler->display->display_options['fields']['modified']['field'] = 'modified';
  $handler->display->display_options['fields']['modified']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['modified']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['modified']['date_format'] = 'short';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Workflow Job: Assignee */
  $handler->display->display_options['arguments']['assigned']['id'] = 'assigned';
  $handler->display->display_options['arguments']['assigned']['table'] = 'wf_job';
  $handler->display->display_options['arguments']['assigned']['field'] = 'assigned';
  $handler->display->display_options['arguments']['assigned']['default_action'] = 'default';
  $handler->display->display_options['arguments']['assigned']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['assigned']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['assigned']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['assigned']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'jobs/assigned';

  /* Display: Assigned Jobs (block) */
  $handler = $view->new_display('block', 'Assigned Jobs (block)', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Jobs Assigned to me';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Workflow Job: ID */
  $handler->display->display_options['fields']['jid']['id'] = 'jid';
  $handler->display->display_options['fields']['jid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jid']['field'] = 'jid';
  $handler->display->display_options['fields']['jid']['label'] = '';
  $handler->display->display_options['fields']['jid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['jid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['jid']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['jid']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['jid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['jid']['separator'] = '';
  /* Field: Workflow Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'wf_job';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Workflow Job: Status */
  $handler->display->display_options['fields']['jsid']['id'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jsid']['field'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['label'] = '';
  $handler->display->display_options['fields']['jsid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['jsid']['alter']['text'] = '[jid]: [title] ([jsid])';
  $handler->display->display_options['fields']['jsid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['jsid']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['jsid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Workflow Job: Modified */
  $handler->display->display_options['sorts']['modified']['id'] = 'modified';
  $handler->display->display_options['sorts']['modified']['table'] = 'wf_job';
  $handler->display->display_options['sorts']['modified']['field'] = 'modified';
  $handler->display->display_options['sorts']['modified']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Workflow Job: Assignee */
  $handler->display->display_options['arguments']['assigned']['id'] = 'assigned';
  $handler->display->display_options['arguments']['assigned']['table'] = 'wf_job';
  $handler->display->display_options['arguments']['assigned']['field'] = 'assigned';
  $handler->display->display_options['arguments']['assigned']['default_action'] = 'default';
  $handler->display->display_options['arguments']['assigned']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['assigned']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['assigned']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['assigned']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Assigned Jobs';
  $export['jobs'] = $view;

  return $export;
}
