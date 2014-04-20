<?php
/**
 * @file
 * drupalhub_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function drupalhub_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front_page';
  $page->task = 'page';
  $page->admin_title = 'Front page';
  $page->admin_description = '';
  $page->path = 'front';
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
  $handler->name = 'page_front_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '#block-system-main {
  width: 100% !important;
}',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'drupalhub_homepage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => array(
        'column_type' => 'col-lg',
        'column_size' => '3',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-lg',
        'column_size' => '8',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '1',
      ),
      'bottom' => NULL,
      'first' => NULL,
      'first_left' => NULL,
      'fist_right' => NULL,
      'second' => NULL,
      'second_left' => NULL,
      'second_right' => NULL,
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fd09fe21-1d0e-4431-8602-3e220dc94ce3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cc00f0fc-9a85-4c53-9c26-a588833d7676';
    $pane->panel = 'first';
    $pane->type = 'views_panes';
    $pane->subtype = 'front_page_gallery-panel_pane_1';
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
    $pane->uuid = 'cc00f0fc-9a85-4c53-9c26-a588833d7676';
    $display->content['new-cc00f0fc-9a85-4c53-9c26-a588833d7676'] = $pane;
    $display->panels['first'][0] = 'new-cc00f0fc-9a85-4c53-9c26-a588833d7676';
    $pane = new stdClass();
    $pane->pid = 'new-3b34c93c-18b4-437e-96c3-dd4608e2ad9a';
    $pane->panel = 'fist_right';
    $pane->type = 'popular_tags';
    $pane->subtype = 'popular_tags';
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
    $pane->uuid = '3b34c93c-18b4-437e-96c3-dd4608e2ad9a';
    $display->content['new-3b34c93c-18b4-437e-96c3-dd4608e2ad9a'] = $pane;
    $display->panels['fist_right'][0] = 'new-3b34c93c-18b4-437e-96c3-dd4608e2ad9a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}
