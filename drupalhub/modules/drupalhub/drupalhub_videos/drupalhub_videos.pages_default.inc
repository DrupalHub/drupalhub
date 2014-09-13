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
  $display->layout = 'drupalhub_video';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'first' => NULL,
      'second' => NULL,
      'video' => NULL,
      'others' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3139bc4b-55ae-4c37-b4cf-1e78a16469e6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-634d0c9a-f271-4e58-ae57-6380f559e079';
    $pane->panel = 'bottom';
    $pane->type = 'video_metadata';
    $pane->subtype = 'video_metadata';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-qqTBWYlmJgynPaqQJloB2OyzXjBIqJainMfIIuwkBvM',
      'form_token' => 'r-adXnms0CcutF404n0y32tYYOW4DaY-yagcdaZrGvY',
      'form_id' => 'drupalhub_videos_video_metadata_content_type_edit_form',
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
    $pane->uuid = '634d0c9a-f271-4e58-ae57-6380f559e079';
    $display->content['new-634d0c9a-f271-4e58-ae57-6380f559e079'] = $pane;
    $display->panels['bottom'][0] = 'new-634d0c9a-f271-4e58-ae57-6380f559e079';
    $pane = new stdClass();
    $pane->pid = 'new-0be6b39f-4666-4956-943b-4aa918f0cf20';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'idea_comments-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0be6b39f-4666-4956-943b-4aa918f0cf20';
    $display->content['new-0be6b39f-4666-4956-943b-4aa918f0cf20'] = $pane;
    $display->panels['bottom'][1] = 'new-0be6b39f-4666-4956-943b-4aa918f0cf20';
    $pane = new stdClass();
    $pane->pid = 'new-8c995151-61cb-4832-9d31-bf01e68f69f3';
    $pane->panel = 'bottom';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8c995151-61cb-4832-9d31-bf01e68f69f3';
    $display->content['new-8c995151-61cb-4832-9d31-bf01e68f69f3'] = $pane;
    $display->panels['bottom'][2] = 'new-8c995151-61cb-4832-9d31-bf01e68f69f3';
    $pane = new stdClass();
    $pane->pid = 'new-5f759a6a-7512-454c-a67f-98ed8d63dd91';
    $pane->panel = 'others';
    $pane->type = 'views_panes';
    $pane->subtype = 'videos-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '5f759a6a-7512-454c-a67f-98ed8d63dd91';
    $display->content['new-5f759a6a-7512-454c-a67f-98ed8d63dd91'] = $pane;
    $display->panels['others'][0] = 'new-5f759a6a-7512-454c-a67f-98ed8d63dd91';
    $pane = new stdClass();
    $pane->pid = 'new-c8396366-4739-4a70-9d10-45feb1da2510';
    $pane->panel = 'video';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c8396366-4739-4a70-9d10-45feb1da2510';
    $display->content['new-c8396366-4739-4a70-9d10-45feb1da2510'] = $pane;
    $display->panels['video'][0] = 'new-c8396366-4739-4a70-9d10-45feb1da2510';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
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
  $page->name = 'playlists';
  $page->task = 'page';
  $page->admin_title = 'Playlists';
  $page->admin_description = '';
  $page->path = 'video/playlists';
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
  $handler->name = 'page_playlists_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'playlists';
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
  $display->layout = 'drupalhub_9_3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => NULL,
      'second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b4291601-1bc5-4ffb-bac1-e7e73446fb55';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['playlists'] = $page;

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
  $display->layout = 'drupalhub_9_3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'first' => NULL,
      'second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'beffb588-a980-4ba4-ad82-4e65d69e3b94';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b43b9c84-cd11-4fba-ba58-85ea02db62bc';
    $pane->panel = 'first';
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
    $display->panels['first'][0] = 'new-b43b9c84-cd11-4fba-ba58-85ea02db62bc';
    $pane = new stdClass();
    $pane->pid = 'new-f17b972d-241c-4e40-9396-53eae241e655';
    $pane->panel = 'second';
    $pane->type = 'manage_links';
    $pane->subtype = 'manage_links';
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
    $pane->uuid = 'f17b972d-241c-4e40-9396-53eae241e655';
    $display->content['new-f17b972d-241c-4e40-9396-53eae241e655'] = $pane;
    $display->panels['second'][0] = 'new-f17b972d-241c-4e40-9396-53eae241e655';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['video'] = $page;

  return $pages;

}
