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
  $display->layout = 'bootstrap_twocol_stacked';
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
    $pane->pid = 'new-11e3fe63-bdc7-48e8-8908-9b83c39bace0';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h3>Recent friends activity</h3>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '11e3fe63-bdc7-48e8-8908-9b83c39bace0';
    $display->content['new-11e3fe63-bdc7-48e8-8908-9b83c39bace0'] = $pane;
    $display->panels['bottom'][0] = 'new-11e3fe63-bdc7-48e8-8908-9b83c39bace0';
    $pane = new stdClass();
    $pane->pid = 'new-7668c0cb-5d5b-45b7-bca6-3efcc4888515';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h1>Starred media</h1>

photos, youtube movies.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7668c0cb-5d5b-45b7-bca6-3efcc4888515';
    $display->content['new-7668c0cb-5d5b-45b7-bca6-3efcc4888515'] = $pane;
    $display->panels['bottom'][1] = 'new-7668c0cb-5d5b-45b7-bca6-3efcc4888515';
    $pane = new stdClass();
    $pane->pid = 'new-416bdcda-8808-44af-b1f4-c6e4594b1956';
    $pane->panel = 'bottom';
    $pane->type = 'get_involve';
    $pane->subtype = 'get_involve';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 1,
      'override_title_text' => '',
      'form_build_id' => 'form-cdQg-WeOSeeM1GMyTeNYiSja91Pb0AfINjJn9W6k_Z4',
      'form_token' => 'OpoRS5ZIH1qRxRhwaYcC-_qfMN5YVm-a5ltRugT75cQ',
      'form_id' => 'drupalhub_pages_get_involve_content_type_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '416bdcda-8808-44af-b1f4-c6e4594b1956';
    $display->content['new-416bdcda-8808-44af-b1f4-c6e4594b1956'] = $pane;
    $display->panels['bottom'][2] = 'new-416bdcda-8808-44af-b1f4-c6e4594b1956';
    $pane = new stdClass();
    $pane->pid = 'new-e2c8d251-1f97-4350-bab6-4b551e9e01b3';
    $pane->panel = 'left';
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
    $pane->uuid = 'e2c8d251-1f97-4350-bab6-4b551e9e01b3';
    $display->content['new-e2c8d251-1f97-4350-bab6-4b551e9e01b3'] = $pane;
    $display->panels['left'][0] = 'new-e2c8d251-1f97-4350-bab6-4b551e9e01b3';
    $pane = new stdClass();
    $pane->pid = 'new-72d2c1cb-56bb-4f80-9390-8f68249f6a09';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h3>System messages</h3>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '72d2c1cb-56bb-4f80-9390-8f68249f6a09';
    $display->content['new-72d2c1cb-56bb-4f80-9390-8f68249f6a09'] = $pane;
    $display->panels['left'][1] = 'new-72d2c1cb-56bb-4f80-9390-8f68249f6a09';
    $pane = new stdClass();
    $pane->pid = 'new-1c5d19fb-94fb-4f17-bb59-9fc58a4f0a8b';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'front_page_blogs-panel_pane_1';
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
    $pane->uuid = '1c5d19fb-94fb-4f17-bb59-9fc58a4f0a8b';
    $display->content['new-1c5d19fb-94fb-4f17-bb59-9fc58a4f0a8b'] = $pane;
    $display->panels['right'][0] = 'new-1c5d19fb-94fb-4f17-bb59-9fc58a4f0a8b';
    $pane = new stdClass();
    $pane->pid = 'new-3b1f886d-896b-4955-92f7-acbf732ffc5f';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'main_page_questions-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3b1f886d-896b-4955-92f7-acbf732ffc5f';
    $display->content['new-3b1f886d-896b-4955-92f7-acbf732ffc5f'] = $pane;
    $display->panels['right'][1] = 'new-3b1f886d-896b-4955-92f7-acbf732ffc5f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}
