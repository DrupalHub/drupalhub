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
    $pane->pid = 'new-af2b47bf-980c-4ecc-bd7b-2a7308ae5367';
    $pane->panel = 'main_top';
    $pane->type = 'links';
    $pane->subtype = 'links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'tabs',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'af2b47bf-980c-4ecc-bd7b-2a7308ae5367';
    $display->content['new-af2b47bf-980c-4ecc-bd7b-2a7308ae5367'] = $pane;
    $display->panels['main_top'][0] = 'new-af2b47bf-980c-4ecc-bd7b-2a7308ae5367';
    $pane = new stdClass();
    $pane->pid = 'new-78b38779-ce03-4749-bc53-2bdefd857471';
    $pane->panel = 'main_top';
    $pane->type = 'wiki_description';
    $pane->subtype = 'wiki_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '78b38779-ce03-4749-bc53-2bdefd857471';
    $display->content['new-78b38779-ce03-4749-bc53-2bdefd857471'] = $pane;
    $display->panels['main_top'][1] = 'new-78b38779-ce03-4749-bc53-2bdefd857471';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'clearfix',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9e27e616-f4b7-4ef8-b051-7f173e30abf1';
    $display->content['new-9e27e616-f4b7-4ef8-b051-7f173e30abf1'] = $pane;
    $display->panels['second'][0] = 'new-9e27e616-f4b7-4ef8-b051-7f173e30abf1';
    $pane = new stdClass();
    $pane->pid = 'new-472fa41e-8cca-4814-a73c-abba383a3aec';
    $pane->panel = 'second';
    $pane->type = 'wikipedia_terms';
    $pane->subtype = 'wikipedia_terms';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-zligi4plCYqODEey49caKnQEUOxDmM4mkd-MFE5j04g',
      'form_token' => '7AW2aE6Em8M85TT6hZMbiJ-VxZfUcbkJiEa9hpxRBU8',
      'form_id' => 'drupalhub_wiki_wikipedia_terms_content_type_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'clearfix',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '472fa41e-8cca-4814-a73c-abba383a3aec';
    $display->content['new-472fa41e-8cca-4814-a73c-abba383a3aec'] = $pane;
    $display->panels['second'][1] = 'new-472fa41e-8cca-4814-a73c-abba383a3aec';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['drupalhub_wiki'] = $page;

  return $pages;

}
