<?php
/**
 * @file
 * wf_environment_generic.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function wf_environment_generic_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'environment_jobs';
  $view->description = 'Jobs for the current environment.';
  $view->tag = 'default';
  $view->base_table = 'wf_job';
  $view->human_name = 'Environment Jobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Jobs';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Workflow Job: ID */
  $handler->display->display_options['fields']['jid']['id'] = 'jid';
  $handler->display->display_options['fields']['jid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jid']['field'] = 'jid';
  $handler->display->display_options['fields']['jid']['label'] = '';
  $handler->display->display_options['fields']['jid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['jid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['jid']['alter']['make_link'] = 1;
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
  $handler->display->display_options['fields']['jid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['jid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['jid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['jid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['jid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['jid']['format_plural'] = 0;
  /* Field: Workflow Job: Status */
  $handler->display->display_options['fields']['jsid']['id'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['table'] = 'wf_job';
  $handler->display->display_options['fields']['jsid']['field'] = 'jsid';
  $handler->display->display_options['fields']['jsid']['label'] = '';
  $handler->display->display_options['fields']['jsid']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['jsid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['jsid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['jsid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['jsid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['jsid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['jsid']['machine_name'] = 0;
  /* Field: Workflow Job: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'wf_job';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] ([jsid])';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'job/[jid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  /* Contextual filter: Workflow Job: Environment */
  $handler->display->display_options['arguments']['eid']['id'] = 'eid';
  $handler->display->display_options['arguments']['eid']['table'] = 'wf_job';
  $handler->display->display_options['arguments']['eid']['field'] = 'eid';
  $handler->display->display_options['arguments']['eid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['eid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['eid']['default_argument_options']['code'] = '$env = menu_get_object(\'wf_environment\');
return is_object($env) ? $env->id : FALSE;';
  $handler->display->display_options['arguments']['eid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['eid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['eid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['eid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['eid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['eid']['not'] = 0;
  /* Filter criterion: Workflow Job: Status */
  $handler->display->display_options['filters']['jsid']['id'] = 'jsid';
  $handler->display->display_options['filters']['jsid']['table'] = 'wf_job';
  $handler->display->display_options['filters']['jsid']['field'] = 'jsid';
  $handler->display->display_options['filters']['jsid']['operator'] = 'not in';
  $handler->display->display_options['filters']['jsid']['value'] = array(
    5 => '5',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Environment Jobs';
  $export['environment_jobs'] = $view;

  return $export;
}
