<?php
/**
 * @file
 * drupalhub_users.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function drupalhub_users_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
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
  $display->layout = 'twocol_stacked';
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
  $display->uuid = '20ff8520-8afe-432d-9afc-57bed76b0834';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bb2ad759-bdc0-41f0-9cb5-852b3d606b45';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'activity_stram-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:user_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bb2ad759-bdc0-41f0-9cb5-852b3d606b45';
    $display->content['new-bb2ad759-bdc0-41f0-9cb5-852b3d606b45'] = $pane;
    $display->panels['bottom'][0] = 'new-bb2ad759-bdc0-41f0-9cb5-852b3d606b45';
    $pane = new stdClass();
    $pane->pid = 'new-ecef5c95-7c51-4b72-b9a6-a391e4ac291e';
    $pane->panel = 'top';
    $pane->type = 'token';
    $pane->subtype = 'user:picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
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
    $pane->uuid = 'ecef5c95-7c51-4b72-b9a6-a391e4ac291e';
    $display->content['new-ecef5c95-7c51-4b72-b9a6-a391e4ac291e'] = $pane;
    $display->panels['top'][0] = 'new-ecef5c95-7c51-4b72-b9a6-a391e4ac291e';
    $pane = new stdClass();
    $pane->pid = 'new-a285af62-f14d-481e-acad-de82337c6574';
    $pane->panel = 'top';
    $pane->type = 'token';
    $pane->subtype = 'user:name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
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
    $pane->uuid = 'a285af62-f14d-481e-acad-de82337c6574';
    $display->content['new-a285af62-f14d-481e-acad-de82337c6574'] = $pane;
    $display->panels['top'][1] = 'new-a285af62-f14d-481e-acad-de82337c6574';
    $pane = new stdClass();
    $pane->pid = 'new-3a6d0912-a83b-4d26-b50e-218a434f4cd5';
    $pane->panel = 'top';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_reputation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'number_integer',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
      ),
      'context' => 'argument_entity_id:user_1',
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
    $pane->uuid = '3a6d0912-a83b-4d26-b50e-218a434f4cd5';
    $display->content['new-3a6d0912-a83b-4d26-b50e-218a434f4cd5'] = $pane;
    $display->panels['top'][2] = 'new-3a6d0912-a83b-4d26-b50e-218a434f4cd5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ecef5c95-7c51-4b72-b9a6-a391e4ac291e';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}

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
