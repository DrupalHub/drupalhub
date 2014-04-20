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
  $display->uuid = 'fc8cb91b-ae32-47b4-8027-a459eb34cc2b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-37dfe948-a29e-4b8f-9318-4bc05094109d';
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
    $pane->uuid = '37dfe948-a29e-4b8f-9318-4bc05094109d';
    $display->content['new-37dfe948-a29e-4b8f-9318-4bc05094109d'] = $pane;
    $display->panels['bottom'][0] = 'new-37dfe948-a29e-4b8f-9318-4bc05094109d';
    $pane = new stdClass();
    $pane->pid = 'new-a8da9141-1a3a-44f9-99ea-00ac63806836';
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
    $pane->uuid = 'a8da9141-1a3a-44f9-99ea-00ac63806836';
    $display->content['new-a8da9141-1a3a-44f9-99ea-00ac63806836'] = $pane;
    $display->panels['top'][0] = 'new-a8da9141-1a3a-44f9-99ea-00ac63806836';
    $pane = new stdClass();
    $pane->pid = 'new-763114df-2c47-4357-a353-b97611bb17dd';
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
    $pane->uuid = '763114df-2c47-4357-a353-b97611bb17dd';
    $display->content['new-763114df-2c47-4357-a353-b97611bb17dd'] = $pane;
    $display->panels['top'][1] = 'new-763114df-2c47-4357-a353-b97611bb17dd';
    $pane = new stdClass();
    $pane->pid = 'new-8df6b89e-e66c-4eb8-9e6f-76a5fffeab5f';
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
    $pane->uuid = '8df6b89e-e66c-4eb8-9e6f-76a5fffeab5f';
    $display->content['new-8df6b89e-e66c-4eb8-9e6f-76a5fffeab5f'] = $pane;
    $display->panels['top'][2] = 'new-8df6b89e-e66c-4eb8-9e6f-76a5fffeab5f';
    $pane = new stdClass();
    $pane->pid = 'new-0bfb15d1-c719-40c3-a54b-6f193a6354d3';
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
    $pane->uuid = '0bfb15d1-c719-40c3-a54b-6f193a6354d3';
    $display->content['new-0bfb15d1-c719-40c3-a54b-6f193a6354d3'] = $pane;
    $display->panels['top'][3] = 'new-0bfb15d1-c719-40c3-a54b-6f193a6354d3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-37dfe948-a29e-4b8f-9318-4bc05094109d';
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
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
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
  $display->uuid = 'b33d779d-2930-43ba-a3b4-cc0e009e0530';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3b03dce6-364f-48cb-b55d-6e0e0109bb6c';
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
    $pane->uuid = '3b03dce6-364f-48cb-b55d-6e0e0109bb6c';
    $display->content['new-3b03dce6-364f-48cb-b55d-6e0e0109bb6c'] = $pane;
    $display->panels['bottom'][0] = 'new-3b03dce6-364f-48cb-b55d-6e0e0109bb6c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['video'] = $page;

  return $pages;

}
