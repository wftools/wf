<?php
/**
 * @file
 * wf_log.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function wf_log_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'log_list';
  $view->description = 'Lists all WF Logs.';
  $view->tag = 'default';
  $view->base_table = 'wf_log';
  $view->human_name = 'Log List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Logs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view workflow log entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'lid' => 'lid',
    'entity_type' => 'entity_type',
    'entity_id' => 'entity_type',
    'message_summary' => 'message_summary',
    'realname' => 'realname',
    'created' => 'created',
    'link_wf_log' => 'delete_wf_log',
    'edit_wf_log' => 'delete_wf_log',
    'delete_wf_log' => 'delete_wf_log',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'lid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message_summary' => array(
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
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'link_wf_log' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_wf_log' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_wf_log' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['content'] = 'No log was created yet';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Workflow Log: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'wf_log';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Workflow Log: Log ID */
  $handler->display->display_options['fields']['lid']['id'] = 'lid';
  $handler->display->display_options['fields']['lid']['table'] = 'wf_log';
  $handler->display->display_options['fields']['lid']['field'] = 'lid';
  /* Field: Workflow Log: Entity type */
  $handler->display->display_options['fields']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['table'] = 'wf_log';
  $handler->display->display_options['fields']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['label'] = 'Entity';
  /* Field: Workflow Log: Entity ID */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'wf_log';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  /* Field: Workflow Log: Message summary */
  $handler->display->display_options['fields']['message_summary']['id'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['table'] = 'wf_log';
  $handler->display->display_options['fields']['message_summary']['field'] = 'message_summary';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'Owner';
  /* Field: Workflow Log: Timestamp */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'wf_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Workflow Log: Link */
  $handler->display->display_options['fields']['link_wf_log']['id'] = 'link_wf_log';
  $handler->display->display_options['fields']['link_wf_log']['table'] = 'wf_log';
  $handler->display->display_options['fields']['link_wf_log']['field'] = 'link_wf_log';
  /* Field: Workflow Log: Edit Link */
  $handler->display->display_options['fields']['edit_wf_log']['id'] = 'edit_wf_log';
  $handler->display->display_options['fields']['edit_wf_log']['table'] = 'wf_log';
  $handler->display->display_options['fields']['edit_wf_log']['field'] = 'edit_wf_log';
  /* Field: Workflow Log: Delete Link */
  $handler->display->display_options['fields']['delete_wf_log']['id'] = 'delete_wf_log';
  $handler->display->display_options['fields']['delete_wf_log']['table'] = 'wf_log';
  $handler->display->display_options['fields']['delete_wf_log']['field'] = 'delete_wf_log';
  $handler->display->display_options['fields']['delete_wf_log']['label'] = 'Operations';
  /* Sort criterion: Workflow Log: Log ID */
  $handler->display->display_options['sorts']['lid']['id'] = 'lid';
  $handler->display->display_options['sorts']['lid']['table'] = 'wf_log';
  $handler->display->display_options['sorts']['lid']['field'] = 'lid';
  /* Filter criterion: Workflow Log: Entity type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'wf_log';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['operator'] = 'contains';
  $handler->display->display_options['filters']['entity_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entity_type']['expose']['operator_id'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['label'] = 'Entity type';
  $handler->display->display_options['filters']['entity_type']['expose']['operator'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['identifier'] = 'entity_type';
  /* Filter criterion: Workflow Log: Message summary */
  $handler->display->display_options['filters']['message_summary']['id'] = 'message_summary';
  $handler->display->display_options['filters']['message_summary']['table'] = 'wf_log';
  $handler->display->display_options['filters']['message_summary']['field'] = 'message_summary';
  $handler->display->display_options['filters']['message_summary']['operator'] = 'contains';
  $handler->display->display_options['filters']['message_summary']['exposed'] = TRUE;
  $handler->display->display_options['filters']['message_summary']['expose']['operator_id'] = 'message_summary_op';
  $handler->display->display_options['filters']['message_summary']['expose']['label'] = 'Message summary';
  $handler->display->display_options['filters']['message_summary']['expose']['operator'] = 'message_summary_op';
  $handler->display->display_options['filters']['message_summary']['expose']['identifier'] = 'message_summary';
  /* Filter criterion: Workflow Log: Owner */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'wf_log';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Owner';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';

  /* Display: Log admin List */
  $handler = $view->new_display('page', 'Log admin List', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'lid' => 'lid',
    'entity_type' => 'entity_type',
    'entity_id' => 'entity_id',
    'message_summary' => 'message_summary',
    'realname' => 'realname',
    'created' => 'created',
    'link_wf_log' => 'delete_wf_log',
    'edit_wf_log' => 'delete_wf_log',
    'delete_wf_log' => 'delete_wf_log',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'lid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message_summary' => array(
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
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'link_wf_log' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_wf_log' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_wf_log' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Workflow Log: Log ID */
  $handler->display->display_options['fields']['lid']['id'] = 'lid';
  $handler->display->display_options['fields']['lid']['table'] = 'wf_log';
  $handler->display->display_options['fields']['lid']['field'] = 'lid';
  $handler->display->display_options['fields']['lid']['label'] = 'ID';
  $handler->display->display_options['fields']['lid']['separator'] = '';
  /* Field: Workflow Log: Entity type */
  $handler->display->display_options['fields']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['table'] = 'wf_log';
  $handler->display->display_options['fields']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['label'] = 'Entity Type';
  /* Field: Workflow Log: Entity ID */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'wf_log';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  /* Field: Workflow Log: Message summary */
  $handler->display->display_options['fields']['message_summary']['id'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['table'] = 'wf_log';
  $handler->display->display_options['fields']['message_summary']['field'] = 'message_summary';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'Owner';
  $handler->display->display_options['fields']['realname']['empty'] = 'Anonymous';
  /* Field: Workflow Log: Timestamp */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'wf_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Workflow Log: Link */
  $handler->display->display_options['fields']['link_wf_log']['id'] = 'link_wf_log';
  $handler->display->display_options['fields']['link_wf_log']['table'] = 'wf_log';
  $handler->display->display_options['fields']['link_wf_log']['field'] = 'link_wf_log';
  /* Field: Workflow Log: Edit Link */
  $handler->display->display_options['fields']['edit_wf_log']['id'] = 'edit_wf_log';
  $handler->display->display_options['fields']['edit_wf_log']['table'] = 'wf_log';
  $handler->display->display_options['fields']['edit_wf_log']['field'] = 'edit_wf_log';
  /* Field: Workflow Log: Delete Link */
  $handler->display->display_options['fields']['delete_wf_log']['id'] = 'delete_wf_log';
  $handler->display->display_options['fields']['delete_wf_log']['table'] = 'wf_log';
  $handler->display->display_options['fields']['delete_wf_log']['field'] = 'delete_wf_log';
  $handler->display->display_options['fields']['delete_wf_log']['label'] = 'Operations';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Workflow Log: Log ID */
  $handler->display->display_options['sorts']['lid']['id'] = 'lid';
  $handler->display->display_options['sorts']['lid']['table'] = 'wf_log';
  $handler->display->display_options['sorts']['lid']['field'] = 'lid';
  $handler->display->display_options['sorts']['lid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workflow Log: Entity type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'wf_log';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['operator'] = 'contains';
  $handler->display->display_options['filters']['entity_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entity_type']['expose']['operator_id'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['label'] = 'Entity type';
  $handler->display->display_options['filters']['entity_type']['expose']['operator'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['identifier'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Workflow Log: Message summary */
  $handler->display->display_options['filters']['message_summary']['id'] = 'message_summary';
  $handler->display->display_options['filters']['message_summary']['table'] = 'wf_log';
  $handler->display->display_options['filters']['message_summary']['field'] = 'message_summary';
  $handler->display->display_options['filters']['message_summary']['operator'] = 'contains';
  $handler->display->display_options['filters']['message_summary']['exposed'] = TRUE;
  $handler->display->display_options['filters']['message_summary']['expose']['operator_id'] = 'message_summary_op';
  $handler->display->display_options['filters']['message_summary']['expose']['label'] = 'Message summary';
  $handler->display->display_options['filters']['message_summary']['expose']['operator'] = 'message_summary_op';
  $handler->display->display_options['filters']['message_summary']['expose']['identifier'] = 'message_summary';
  /* Filter criterion: Workflow Log: Owner */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'wf_log';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Owner';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  /* Filter criterion: Workflow Log: Entity */
  $handler->display->display_options['filters']['entity']['id'] = 'entity';
  $handler->display->display_options['filters']['entity']['table'] = 'wf_log';
  $handler->display->display_options['filters']['entity']['field'] = 'entity';
  $handler->display->display_options['filters']['entity']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entity']['expose']['operator_id'] = 'entity_op';
  $handler->display->display_options['filters']['entity']['expose']['label'] = 'Entity ID';
  $handler->display->display_options['filters']['entity']['expose']['operator'] = 'entity_op';
  $handler->display->display_options['filters']['entity']['expose']['identifier'] = 'entity';
  $handler->display->display_options['path'] = 'admin/content/wf-log';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Logs';
  $handler->display->display_options['menu']['description'] = 'List wf logs';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Job activities */
  $handler = $view->new_display('page', 'Job activities', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Job activities';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'lid' => 'lid',
    'entity_type' => 'entity_type',
    'entity_id' => 'entity_id',
    'message_summary' => 'message_summary',
    'realname' => 'realname',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'lid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message_summary' => array(
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
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['content'] = 'No results found';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Workflow Log: Message summary */
  $handler->display->display_options['fields']['message_summary']['id'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['table'] = 'wf_log';
  $handler->display->display_options['fields']['message_summary']['field'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['label'] = 'Activity';
  /* Field: Workflow Log: Message body */
  $handler->display->display_options['fields']['message_body']['id'] = 'message_body';
  $handler->display->display_options['fields']['message_body']['table'] = 'wf_log';
  $handler->display->display_options['fields']['message_body']['field'] = 'message_body';
  $handler->display->display_options['fields']['message_body']['label'] = 'Details';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'Owner';
  $handler->display->display_options['fields']['realname']['empty'] = 'Anonymous';
  /* Field: Workflow Log: Timestamp */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'wf_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Workflow Log: Link */
  $handler->display->display_options['fields']['link_wf_log']['id'] = 'link_wf_log';
  $handler->display->display_options['fields']['link_wf_log']['table'] = 'wf_log';
  $handler->display->display_options['fields']['link_wf_log']['field'] = 'link_wf_log';
  $handler->display->display_options['fields']['link_wf_log']['label'] = 'View';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Workflow Log: Log ID */
  $handler->display->display_options['sorts']['lid']['id'] = 'lid';
  $handler->display->display_options['sorts']['lid']['table'] = 'wf_log';
  $handler->display->display_options['sorts']['lid']['field'] = 'lid';
  $handler->display->display_options['sorts']['lid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Workflow Log: Entity */
  $handler->display->display_options['arguments']['entity']['id'] = 'entity';
  $handler->display->display_options['arguments']['entity']['table'] = 'wf_log';
  $handler->display->display_options['arguments']['entity']['field'] = 'entity';
  $handler->display->display_options['arguments']['entity']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['entity']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entity']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workflow Log: Entity type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'wf_log';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'wf_job';
  $handler->display->display_options['path'] = 'admin/wf-log/job/%';

  /* Display: Job activities - Block */
  $handler = $view->new_display('block', 'Job activities - Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Job activities';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['content'] = 'No results found';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Workflow Log: Message summary */
  $handler->display->display_options['fields']['message_summary']['id'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['table'] = 'wf_log';
  $handler->display->display_options['fields']['message_summary']['field'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['label'] = 'Activity';
  /* Field: Workflow Log: Message body */
  $handler->display->display_options['fields']['message_body']['id'] = 'message_body';
  $handler->display->display_options['fields']['message_body']['table'] = 'wf_log';
  $handler->display->display_options['fields']['message_body']['field'] = 'message_body';
  $handler->display->display_options['fields']['message_body']['label'] = 'Details';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'Owner';
  $handler->display->display_options['fields']['realname']['empty'] = 'Anonymous';
  /* Field: Workflow Log: Timestamp */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'wf_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Workflow Log: Link */
  $handler->display->display_options['fields']['link_wf_log']['id'] = 'link_wf_log';
  $handler->display->display_options['fields']['link_wf_log']['table'] = 'wf_log';
  $handler->display->display_options['fields']['link_wf_log']['field'] = 'link_wf_log';
  $handler->display->display_options['fields']['link_wf_log']['label'] = 'View';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Workflow Log: Log ID */
  $handler->display->display_options['sorts']['lid']['id'] = 'lid';
  $handler->display->display_options['sorts']['lid']['table'] = 'wf_log';
  $handler->display->display_options['sorts']['lid']['field'] = 'lid';
  $handler->display->display_options['sorts']['lid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Workflow Log: Entity */
  $handler->display->display_options['arguments']['entity']['id'] = 'entity';
  $handler->display->display_options['arguments']['entity']['table'] = 'wf_log';
  $handler->display->display_options['arguments']['entity']['field'] = 'entity';
  $handler->display->display_options['arguments']['entity']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['entity']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entity']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workflow Log: Entity type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'wf_log';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'wf_job';

  /* Display: Job change log - Block */
  $handler = $view->new_display('block', 'Job change log - Block', 'job_change_log_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Changelog';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'generic-table-view';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own job job';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'wf-log-entry';
  $handler->display->display_options['style_options']['columns'] = array(
    'lid' => 'lid',
    'entity_type' => 'entity_type',
    'entity_id' => 'entity_type',
    'created_1' => 'created_1',
    'created' => 'created',
    'realname' => 'realname',
    'message_summary' => 'message_summary',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'lid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
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
    'message_summary' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Workflow Log: Log ID */
  $handler->display->display_options['fields']['lid']['id'] = 'lid';
  $handler->display->display_options['fields']['lid']['table'] = 'wf_log';
  $handler->display->display_options['fields']['lid']['field'] = 'lid';
  $handler->display->display_options['fields']['lid']['label'] = '';
  $handler->display->display_options['fields']['lid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['lid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['lid']['separator'] = '';
  /* Field: Workflow Log: Timestamp */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'wf_log';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = '';
  $handler->display->display_options['fields']['created_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'long';
  /* Field: Workflow Log: Timestamp */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'wf_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['path'] = 'wf-log/[lid]';
  $handler->display->display_options['fields']['created']['alter']['alt'] = '[created_1]';
  $handler->display->display_options['fields']['created']['alter']['link_class'] = 'log-date';
  $handler->display->display_options['fields']['created']['date_format'] = 'really_short';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'User';
  $handler->display->display_options['fields']['realname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['path'] = 'wf-log/[lid]';
  $handler->display->display_options['fields']['realname']['alter']['link_class'] = 'log-user';
  $handler->display->display_options['fields']['realname']['empty'] = 'Anonymous';
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: Workflow Log: Message summary */
  $handler->display->display_options['fields']['message_summary']['id'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['table'] = 'wf_log';
  $handler->display->display_options['fields']['message_summary']['field'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['label'] = 'Status';
  $handler->display->display_options['fields']['message_summary']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['message_summary']['alter']['path'] = 'wf-log/[lid]';
  $handler->display->display_options['fields']['message_summary']['alter']['link_class'] = 'log-summary';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Workflow Log: Log ID */
  $handler->display->display_options['sorts']['lid']['id'] = 'lid';
  $handler->display->display_options['sorts']['lid']['table'] = 'wf_log';
  $handler->display->display_options['sorts']['lid']['field'] = 'lid';
  $handler->display->display_options['sorts']['lid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Workflow Log: Entity */
  $handler->display->display_options['arguments']['entity']['id'] = 'entity';
  $handler->display->display_options['arguments']['entity']['table'] = 'wf_log';
  $handler->display->display_options['arguments']['entity']['field'] = 'entity';
  $handler->display->display_options['arguments']['entity']['default_action'] = 'default';
  $handler->display->display_options['arguments']['entity']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['entity']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['entity']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workflow Log: Entity type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'wf_log';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'wf_job';

  /* Display: Job proposal comment */
  $handler = $view->new_display('block', 'Job proposal comment', 'job_proposal_comment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Job proposal comment';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'realname' => 'realname',
    'created' => 'created',
  );
  $handler->display->display_options['row_options']['separator'] = '-';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['empty'] = 'Anonymous';
  /* Field: Workflow Log: Timestamp */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'wf_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd M Y - H:i';
  /* Field: Workflow Log: Message body */
  $handler->display->display_options['fields']['message_body']['id'] = 'message_body';
  $handler->display->display_options['fields']['message_body']['table'] = 'wf_log';
  $handler->display->display_options['fields']['message_body']['field'] = 'message_body';
  $handler->display->display_options['fields']['message_body']['label'] = '';
  $handler->display->display_options['fields']['message_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Workflow Log: Log ID */
  $handler->display->display_options['sorts']['lid']['id'] = 'lid';
  $handler->display->display_options['sorts']['lid']['table'] = 'wf_log';
  $handler->display->display_options['sorts']['lid']['field'] = 'lid';
  $handler->display->display_options['sorts']['lid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Workflow Log: Entity */
  $handler->display->display_options['arguments']['entity']['id'] = 'entity';
  $handler->display->display_options['arguments']['entity']['table'] = 'wf_log';
  $handler->display->display_options['arguments']['entity']['field'] = 'entity';
  $handler->display->display_options['arguments']['entity']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['entity']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entity']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Workflow Log: Message type */
  $handler->display->display_options['arguments']['message_type']['id'] = 'message_type';
  $handler->display->display_options['arguments']['message_type']['table'] = 'wf_log';
  $handler->display->display_options['arguments']['message_type']['field'] = 'message_type';
  $handler->display->display_options['arguments']['message_type']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['message_type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['message_type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['message_type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['message_type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['message_type']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workflow Log: Entity type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'wf_log';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'wf_job';

  /* Display: Job Changelog Review */
  $handler = $view->new_display('block', 'Job Changelog Review', 'job_changelog_review');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Job Changelog Review';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Workflow Log: Timestamp */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'wf_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'j M Y';
  /* Field: Workflow Log: Message summary */
  $handler->display->display_options['fields']['message_summary']['id'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['table'] = 'wf_log';
  $handler->display->display_options['fields']['message_summary']['field'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['label'] = 'Action';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'User';
  $handler->display->display_options['fields']['realname']['empty'] = 'Anonymous';
  /* Field: Workflow Log: Message body */
  $handler->display->display_options['fields']['message_body']['id'] = 'message_body';
  $handler->display->display_options['fields']['message_body']['table'] = 'wf_log';
  $handler->display->display_options['fields']['message_body']['field'] = 'message_body';
  $handler->display->display_options['fields']['message_body']['label'] = 'Comment';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Workflow Log: Log ID */
  $handler->display->display_options['sorts']['lid']['id'] = 'lid';
  $handler->display->display_options['sorts']['lid']['table'] = 'wf_log';
  $handler->display->display_options['sorts']['lid']['field'] = 'lid';
  $handler->display->display_options['sorts']['lid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Workflow Log: Entity */
  $handler->display->display_options['arguments']['entity']['id'] = 'entity';
  $handler->display->display_options['arguments']['entity']['table'] = 'wf_log';
  $handler->display->display_options['arguments']['entity']['field'] = 'entity';
  $handler->display->display_options['arguments']['entity']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['entity']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entity']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Site change log - Block */
  $handler = $view->new_display('block', 'Site change log - Block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Changelog';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'generic-table-view';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view sites';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'wf-log-entry';
  $handler->display->display_options['style_options']['columns'] = array(
    'lid' => 'lid',
    'entity_type' => 'entity_type',
    'entity_id' => 'entity_type',
    'created_1' => 'created_1',
    'created' => 'created',
    'realname' => 'realname',
    'message_summary' => 'message_summary',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'lid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', ',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
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
    'message_summary' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Workflow Log: Log ID */
  $handler->display->display_options['fields']['lid']['id'] = 'lid';
  $handler->display->display_options['fields']['lid']['table'] = 'wf_log';
  $handler->display->display_options['fields']['lid']['field'] = 'lid';
  $handler->display->display_options['fields']['lid']['label'] = '';
  $handler->display->display_options['fields']['lid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['lid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['lid']['separator'] = '';
  /* Field: Workflow Log: Timestamp */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'wf_log';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = '';
  $handler->display->display_options['fields']['created_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'long';
  /* Field: Workflow Log: Timestamp */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'wf_log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['path'] = 'wf-log/[lid]';
  $handler->display->display_options['fields']['created']['alter']['alt'] = '[created_1]';
  $handler->display->display_options['fields']['created']['alter']['link_class'] = 'log-date';
  $handler->display->display_options['fields']['created']['date_format'] = 'really_short';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'User';
  $handler->display->display_options['fields']['realname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['path'] = 'wf-log/[lid]';
  $handler->display->display_options['fields']['realname']['alter']['link_class'] = 'log-user';
  $handler->display->display_options['fields']['realname']['empty'] = 'Anonymous';
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: Workflow Log: Message summary */
  $handler->display->display_options['fields']['message_summary']['id'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['table'] = 'wf_log';
  $handler->display->display_options['fields']['message_summary']['field'] = 'message_summary';
  $handler->display->display_options['fields']['message_summary']['label'] = 'Status';
  $handler->display->display_options['fields']['message_summary']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['message_summary']['alter']['path'] = 'wf-log/[lid]';
  $handler->display->display_options['fields']['message_summary']['alter']['link_class'] = 'log-summary';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Workflow Log: Log ID */
  $handler->display->display_options['sorts']['lid']['id'] = 'lid';
  $handler->display->display_options['sorts']['lid']['table'] = 'wf_log';
  $handler->display->display_options['sorts']['lid']['field'] = 'lid';
  $handler->display->display_options['sorts']['lid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Workflow Log: Entity */
  $handler->display->display_options['arguments']['entity']['id'] = 'entity';
  $handler->display->display_options['arguments']['entity']['table'] = 'wf_log';
  $handler->display->display_options['arguments']['entity']['field'] = 'entity';
  $handler->display->display_options['arguments']['entity']['default_action'] = 'default';
  $handler->display->display_options['arguments']['entity']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['entity']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['entity']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Workflow Log: Entity type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'wf_log';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'wf_site';


  // Add view to list of views to provide.
  $views[$view->name] = $view;

  return $views;
}
