<?php
/**
 * @file
 * drupalhub_wiki.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function drupalhub_wiki_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'drupalhub_wiki';
  $page->task = 'page';
  $page->admin_title = 'DrupalHub wiki';
  $page->admin_description = '';
  $page->path = 'documentation';
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
  $handler->name = 'page_drupalhub_wiki_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'drupalhub_wiki';
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
  $display->layout = 'drupalhub_wiki';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main_top' => NULL,
      'category_1' => NULL,
      'category_2' => NULL,
      'category_3' => NULL,
      'second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '08be3e0b-8ac3-4c73-9982-9e3cd64c2358';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9e27e616-f4b7-4ef8-b051-7f173e30abf1';
    $pane->panel = 'second';
    $pane->type = 'search_box';
    $pane->subtype = 'search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-jAbuzVp4453W4EyQiGT2C71z34TcnFzg0GpEcwPKmBo',
      'form_token' => '-A9G4zpYYH2LQ5ELFybMH7kAMThVvTZB9JOLI20Ee48',
      'form_id' => 'drupalhub_wiki_search_box_content_type_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9e27e616-f4b7-4ef8-b051-7f173e30abf1';
    $display->content['new-9e27e616-f4b7-4ef8-b051-7f173e30abf1'] = $pane;
    $display->panels['second'][0] = 'new-9e27e616-f4b7-4ef8-b051-7f173e30abf1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['drupalhub_wiki'] = $page;

  return $pages;

}
