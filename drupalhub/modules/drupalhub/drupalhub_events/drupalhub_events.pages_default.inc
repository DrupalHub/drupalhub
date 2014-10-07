<?php
/**
 * @file
 * drupalhub_events.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function drupalhub_events_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_7';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'Event',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'User from Node (on node.node_author)',
        'keyword' => 'user',
        'name' => 'entity_from_schema:uid-node-user',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'events' => 'events',
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
  $display->layout = 'drupalhub_blog';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'bottom' => NULL,
      'top_first' => NULL,
      'top_second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cc9925f9-79bc-471b-ab4b-436e2df2ff2d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d795f590-ca63-43a6-af05-a8747b8a80a8';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd795f590-ca63-43a6-af05-a8747b8a80a8';
    $display->content['new-d795f590-ca63-43a6-af05-a8747b8a80a8'] = $pane;
    $display->panels['bottom'][0] = 'new-d795f590-ca63-43a6-af05-a8747b8a80a8';
    $pane = new stdClass();
    $pane->pid = 'new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $pane->panel = 'bottom';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $display->content['new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8'] = $pane;
    $display->panels['bottom'][1] = 'new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $pane = new stdClass();
    $pane->pid = 'new-0e9720c7-e43d-4a05-8505-0f24be46c250';
    $pane->panel = 'top_first';
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
    $pane->uuid = '0e9720c7-e43d-4a05-8505-0f24be46c250';
    $display->content['new-0e9720c7-e43d-4a05-8505-0f24be46c250'] = $pane;
    $display->panels['top_first'][0] = 'new-0e9720c7-e43d-4a05-8505-0f24be46c250';
    $pane = new stdClass();
    $pane->pid = 'new-5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $pane->panel = 'top_first';
    $pane->type = 'node_metatags';
    $pane->subtype = 'node_metatags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'form_build_id' => 'form-03YJIQhPNIizsGdR2g_JT20XAoOywSIz8wna44HgA6k',
      'form_token' => 'yjPS_pCxPKq-MJ45c1h8ssdKtacY4PX1bi8yxrLmtgM',
      'form_id' => 'drupalhub_core_node_metatags_content_type_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $display->content['new-5a225a5e-c342-49f4-86e9-87edc792ecb8'] = $pane;
    $display->panels['top_first'][1] = 'new-5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $pane = new stdClass();
    $pane->pid = 'new-b54cacb4-5856-469d-9742-fb52d0ca0ef7';
    $pane->panel = 'top_first';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'long',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
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
    $pane->uuid = 'b54cacb4-5856-469d-9742-fb52d0ca0ef7';
    $display->content['new-b54cacb4-5856-469d-9742-fb52d0ca0ef7'] = $pane;
    $display->panels['top_first'][2] = 'new-b54cacb4-5856-469d-9742-fb52d0ca0ef7';
    $pane = new stdClass();
    $pane->pid = 'new-a69beb2d-1387-43da-8673-d3850142d632';
    $pane->panel = 'top_first';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'a69beb2d-1387-43da-8673-d3850142d632';
    $display->content['new-a69beb2d-1387-43da-8673-d3850142d632'] = $pane;
    $display->panels['top_first'][3] = 'new-a69beb2d-1387-43da-8673-d3850142d632';
    $pane = new stdClass();
    $pane->pid = 'new-100fdcfb-4e76-4b9f-be0e-997bd235790e';
    $pane->panel = 'top_first';
    $pane->type = 'increase_count';
    $pane->subtype = 'increase_count';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '100fdcfb-4e76-4b9f-be0e-997bd235790e';
    $display->content['new-100fdcfb-4e76-4b9f-be0e-997bd235790e'] = $pane;
    $display->panels['top_first'][4] = 'new-100fdcfb-4e76-4b9f-be0e-997bd235790e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_7'] = $handler;

  return $export;
}

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
