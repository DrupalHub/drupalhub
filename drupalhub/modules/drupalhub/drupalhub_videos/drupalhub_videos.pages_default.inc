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
  $display->uuid = '3139bc4b-55ae-4c37-b4cf-1e78a16469e6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6a940ebd-82a1-4efc-a8d7-8899525435c8';
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
    $pane->uuid = '6a940ebd-82a1-4efc-a8d7-8899525435c8';
    $display->content['new-6a940ebd-82a1-4efc-a8d7-8899525435c8'] = $pane;
    $display->panels['bottom'][0] = 'new-6a940ebd-82a1-4efc-a8d7-8899525435c8';
    $pane = new stdClass();
    $pane->pid = 'new-0a692f81-9917-4c0f-bab0-3eac0ccbde8f';
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
    $pane->uuid = '0a692f81-9917-4c0f-bab0-3eac0ccbde8f';
    $display->content['new-0a692f81-9917-4c0f-bab0-3eac0ccbde8f'] = $pane;
    $display->panels['top'][0] = 'new-0a692f81-9917-4c0f-bab0-3eac0ccbde8f';
    $pane = new stdClass();
    $pane->pid = 'new-411bc6b1-c990-4c63-9e30-81bc48574968';
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
    $pane->uuid = '411bc6b1-c990-4c63-9e30-81bc48574968';
    $display->content['new-411bc6b1-c990-4c63-9e30-81bc48574968'] = $pane;
    $display->panels['top'][1] = 'new-411bc6b1-c990-4c63-9e30-81bc48574968';
    $pane = new stdClass();
    $pane->pid = 'new-c8396366-4739-4a70-9d10-45feb1da2510';
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
    $pane->uuid = 'c8396366-4739-4a70-9d10-45feb1da2510';
    $display->content['new-c8396366-4739-4a70-9d10-45feb1da2510'] = $pane;
    $display->panels['top'][2] = 'new-c8396366-4739-4a70-9d10-45feb1da2510';
    $pane = new stdClass();
    $pane->pid = 'new-bfcc508f-6a60-4254-8f2f-579f51fff8ac';
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
    $pane->uuid = 'bfcc508f-6a60-4254-8f2f-579f51fff8ac';
    $display->content['new-bfcc508f-6a60-4254-8f2f-579f51fff8ac'] = $pane;
    $display->panels['top'][3] = 'new-bfcc508f-6a60-4254-8f2f-579f51fff8ac';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6a940ebd-82a1-4efc-a8d7-8899525435c8';
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
  $display->uuid = 'beffb588-a980-4ba4-ad82-4e65d69e3b94';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b43b9c84-cd11-4fba-ba58-85ea02db62bc';
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
    $pane->uuid = 'b43b9c84-cd11-4fba-ba58-85ea02db62bc';
    $display->content['new-b43b9c84-cd11-4fba-ba58-85ea02db62bc'] = $pane;
    $display->panels['bottom'][0] = 'new-b43b9c84-cd11-4fba-ba58-85ea02db62bc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['video'] = $page;

  return $pages;

}
