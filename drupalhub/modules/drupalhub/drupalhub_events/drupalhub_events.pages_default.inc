<?php
/**
 * @file
 * drupalhub_events.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function drupalhub_events_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'calendar';
  $page->task = 'page';
  $page->admin_title = 'Calendar';
  $page->admin_description = '';
  $page->path = 'calendar';
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
  $handler->name = 'page_calendar_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'calendar';
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
  $display->layout = 'drupalhub_calendar';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => NULL,
      'second' => NULL,
      'calendar' => NULL,
      'bottom-first' => NULL,
      'bottom-second' => NULL,
      'bottom-third' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b111fe71-379b-4da8-b4a7-aea03127c275';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-377c4518-afb2-43a7-b382-28e7a180896d';
    $pane->panel = 'bottom-first';
    $pane->type = 'upcoming_events';
    $pane->subtype = 'upcoming_events';
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
    $pane->uuid = '377c4518-afb2-43a7-b382-28e7a180896d';
    $display->content['new-377c4518-afb2-43a7-b382-28e7a180896d'] = $pane;
    $display->panels['bottom-first'][0] = 'new-377c4518-afb2-43a7-b382-28e7a180896d';
    $pane = new stdClass();
    $pane->pid = 'new-9c5fb96f-1c49-4f91-a4c9-a6815e7e5b9c';
    $pane->panel = 'calendar';
    $pane->type = 'quick_links';
    $pane->subtype = 'quick_links';
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
    $pane->uuid = '9c5fb96f-1c49-4f91-a4c9-a6815e7e5b9c';
    $display->content['new-9c5fb96f-1c49-4f91-a4c9-a6815e7e5b9c'] = $pane;
    $display->panels['calendar'][0] = 'new-9c5fb96f-1c49-4f91-a4c9-a6815e7e5b9c';
    $pane = new stdClass();
    $pane->pid = 'new-d0b61a01-c5ec-4ce4-9e76-37e4bcc766a6';
    $pane->panel = 'calendar';
    $pane->type = 'views';
    $pane->subtype = 'calendar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
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
    $pane->uuid = 'd0b61a01-c5ec-4ce4-9e76-37e4bcc766a6';
    $display->content['new-d0b61a01-c5ec-4ce4-9e76-37e4bcc766a6'] = $pane;
    $display->panels['calendar'][1] = 'new-d0b61a01-c5ec-4ce4-9e76-37e4bcc766a6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['calendar'] = $page;

  return $pages;

}
