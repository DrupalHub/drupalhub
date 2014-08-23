<?php
/**
 * @file
 * drupalhub_users.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function drupalhub_users_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'questions';
  $page->task = 'page';
  $page->admin_title = 'Questions';
  $page->admin_description = '';
  $page->path = 'questions';
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
  $handler->name = 'page_questions_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'questions';
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
  $display->uuid = '9101a6d3-933a-4231-b457-bf0921f9a56f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a5cdd4b1-171c-488a-a3d2-95bf2b93efda';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'question-panel_pane_1';
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
    $pane->uuid = 'a5cdd4b1-171c-488a-a3d2-95bf2b93efda';
    $display->content['new-a5cdd4b1-171c-488a-a3d2-95bf2b93efda'] = $pane;
    $display->panels['middle'][0] = 'new-a5cdd4b1-171c-488a-a3d2-95bf2b93efda';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['questions'] = $page;

  return $pages;

}
