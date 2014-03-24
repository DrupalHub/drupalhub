<?php
/**
 * @file
 * drupalhub_videos.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function drupalhub_videos_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Video',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'youtube' => 'youtube',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3ea06d74-711e-4eb3-83c3-f99432f5b996';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cf3a3b82-ae48-4629-8da8-f99ddff122fc';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'videos-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'cf3a3b82-ae48-4629-8da8-f99ddff122fc';
    $display->content['new-cf3a3b82-ae48-4629-8da8-f99ddff122fc'] = $pane;
    $display->panels['bottom'][0] = 'new-cf3a3b82-ae48-4629-8da8-f99ddff122fc';
    $pane = new stdClass();
    $pane->pid = 'new-72da9f15-d63b-419d-86f5-4e60e8f0064d';
    $pane->panel = 'top';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '72da9f15-d63b-419d-86f5-4e60e8f0064d';
    $display->content['new-72da9f15-d63b-419d-86f5-4e60e8f0064d'] = $pane;
    $display->panels['top'][0] = 'new-72da9f15-d63b-419d-86f5-4e60e8f0064d';
    $pane = new stdClass();
    $pane->pid = 'new-5bfb29fb-a4a5-4a90-968c-9c06b7824282';
    $pane->panel = 'top';
    $pane->type = 'video_navigation';
    $pane->subtype = 'video_navigation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'navigation_type' => 'back',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5bfb29fb-a4a5-4a90-968c-9c06b7824282';
    $display->content['new-5bfb29fb-a4a5-4a90-968c-9c06b7824282'] = $pane;
    $display->panels['top'][1] = 'new-5bfb29fb-a4a5-4a90-968c-9c06b7824282';
    $pane = new stdClass();
    $pane->pid = 'new-68426252-9987-4722-84d2-60be3c62249a';
    $pane->panel = 'top';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_address';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'video_embed_field',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'video_style' => 'normal',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '68426252-9987-4722-84d2-60be3c62249a';
    $display->content['new-68426252-9987-4722-84d2-60be3c62249a'] = $pane;
    $display->panels['top'][2] = 'new-68426252-9987-4722-84d2-60be3c62249a';
    $pane = new stdClass();
    $pane->pid = 'new-672d9c56-c77c-4072-b1e3-d7a26ba07c5f';
    $pane->panel = 'top';
    $pane->type = 'video_navigation';
    $pane->subtype = 'video_navigation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'navigation_type' => 'next',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '672d9c56-c77c-4072-b1e3-d7a26ba07c5f';
    $display->content['new-672d9c56-c77c-4072-b1e3-d7a26ba07c5f'] = $pane;
    $display->panels['top'][3] = 'new-672d9c56-c77c-4072-b1e3-d7a26ba07c5f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cf3a3b82-ae48-4629-8da8-f99ddff122fc';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function drupalhub_videos_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'video';
  $page->task = 'page';
  $page->admin_title = 'Video';
  $page->admin_description = '';
  $page->path = 'video';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_video_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'video';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3cc3d3f8-16c2-4496-9a83-2c22402ee0b9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-27c99137-5729-4afe-908a-7a19be7be212';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'videos-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '27c99137-5729-4afe-908a-7a19be7be212';
    $display->content['new-27c99137-5729-4afe-908a-7a19be7be212'] = $pane;
    $display->panels['bottom'][0] = 'new-27c99137-5729-4afe-908a-7a19be7be212';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['video'] = $page;

  return $pages;

}
