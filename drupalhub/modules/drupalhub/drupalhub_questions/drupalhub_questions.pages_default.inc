<?php
/**
 * @file
 * drupalhub_questions.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function drupalhub_questions_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Question page',
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
              'question' => 'question',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cc9925f9-79bc-471b-ab4b-436e2df2ff2d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-36ddeffb-4d5a-424f-a0bf-c414a33eca77';
    $pane->panel = 'middle';
    $pane->type = 'user_picture';
    $pane->subtype = 'user_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'relationship_entity_from_schema:uid-node-user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-OkUyV8PXezkuNEmm3xxIhPiENH8s1K27TLLplxQAC-s',
      'form_token' => '_ePfOZb6PxOzqb1nZeIUJaydQ3Ad2y3hqndGtOmxcMg',
      'form_id' => 'drupalhub_users_user_picture_content_type_edit_form',
      'op' => 'Finish',
      'image_styles' => 'thumbnail_retina',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '36ddeffb-4d5a-424f-a0bf-c414a33eca77';
    $display->content['new-36ddeffb-4d5a-424f-a0bf-c414a33eca77'] = $pane;
    $display->panels['middle'][0] = 'new-36ddeffb-4d5a-424f-a0bf-c414a33eca77';
    $pane = new stdClass();
    $pane->pid = 'new-0e9720c7-e43d-4a05-8505-0f24be46c250';
    $pane->panel = 'middle';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0e9720c7-e43d-4a05-8505-0f24be46c250';
    $display->content['new-0e9720c7-e43d-4a05-8505-0f24be46c250'] = $pane;
    $display->panels['middle'][1] = 'new-0e9720c7-e43d-4a05-8505-0f24be46c250';
    $pane = new stdClass();
    $pane->pid = 'new-5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $pane->panel = 'middle';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $display->content['new-5a225a5e-c342-49f4-86e9-87edc792ecb8'] = $pane;
    $display->panels['middle'][2] = 'new-5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $pane = new stdClass();
    $pane->pid = 'new-a69beb2d-1387-43da-8673-d3850142d632';
    $pane->panel = 'middle';
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
    $display->panels['middle'][3] = 'new-a69beb2d-1387-43da-8673-d3850142d632';
    $pane = new stdClass();
    $pane->pid = 'new-d795f590-ca63-43a6-af05-a8747b8a80a8';
    $pane->panel = 'middle';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'd795f590-ca63-43a6-af05-a8747b8a80a8';
    $display->content['new-d795f590-ca63-43a6-af05-a8747b8a80a8'] = $pane;
    $display->panels['middle'][4] = 'new-d795f590-ca63-43a6-af05-a8747b8a80a8';
    $pane = new stdClass();
    $pane->pid = 'new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $pane->panel = 'middle';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $display->content['new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8'] = $pane;
    $display->panels['middle'][5] = 'new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $pane = new stdClass();
    $pane->pid = 'new-100fdcfb-4e76-4b9f-be0e-997bd235790e';
    $pane->panel = 'middle';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '100fdcfb-4e76-4b9f-be0e-997bd235790e';
    $display->content['new-100fdcfb-4e76-4b9f-be0e-997bd235790e'] = $pane;
    $display->panels['middle'][6] = 'new-100fdcfb-4e76-4b9f-be0e-997bd235790e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}
