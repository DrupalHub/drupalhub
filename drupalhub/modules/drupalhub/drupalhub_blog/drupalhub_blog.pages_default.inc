<?php
/**
 * @file
 * drupalhub_blog.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function drupalhub_blog_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'blogs';
  $page->task = 'page';
  $page->admin_title = 'Blogs';
  $page->admin_description = '';
  $page->path = 'blogs';
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
  $handler->name = 'page_blogs_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'blogs';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3b888ab0-a70d-48bc-917a-656f5a084e28';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2ae1c58a-448e-460e-a4d4-e551aacc7b96';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'blogs-panel_pane_1';
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
    $pane->uuid = '2ae1c58a-448e-460e-a4d4-e551aacc7b96';
    $display->content['new-2ae1c58a-448e-460e-a4d4-e551aacc7b96'] = $pane;
    $display->panels['middle'][0] = 'new-2ae1c58a-448e-460e-a4d4-e551aacc7b96';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2ae1c58a-448e-460e-a4d4-e551aacc7b96';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['blogs'] = $page;

  return $pages;

}
