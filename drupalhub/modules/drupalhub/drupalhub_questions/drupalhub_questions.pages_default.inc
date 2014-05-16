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
    'relationships' => array(),
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
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cc9925f9-79bc-471b-ab4b-436e2df2ff2d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ccb07d60-8afc-41e2-bcd2-ae2758e9187f';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_vote';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'vud',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ccb07d60-8afc-41e2-bcd2-ae2758e9187f';
    $display->content['new-ccb07d60-8afc-41e2-bcd2-ae2758e9187f'] = $pane;
    $display->panels['left'][0] = 'new-ccb07d60-8afc-41e2-bcd2-ae2758e9187f';
    $pane = new stdClass();
    $pane->pid = 'new-ef0dd499-00e7-4213-9dc8-f275a49011d3';
    $pane->panel = 'left';
    $pane->type = 'panels_mini';
    $pane->subtype = 'question_display';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
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
    $pane->uuid = 'ef0dd499-00e7-4213-9dc8-f275a49011d3';
    $display->content['new-ef0dd499-00e7-4213-9dc8-f275a49011d3'] = $pane;
    $display->panels['left'][1] = 'new-ef0dd499-00e7-4213-9dc8-f275a49011d3';
    $pane = new stdClass();
    $pane->pid = 'new-d795f590-ca63-43a6-af05-a8747b8a80a8';
    $pane->panel = 'left';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd795f590-ca63-43a6-af05-a8747b8a80a8';
    $display->content['new-d795f590-ca63-43a6-af05-a8747b8a80a8'] = $pane;
    $display->panels['left'][2] = 'new-d795f590-ca63-43a6-af05-a8747b8a80a8';
    $pane = new stdClass();
    $pane->pid = 'new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $pane->panel = 'left';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $display->content['new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8'] = $pane;
    $display->panels['left'][3] = 'new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $pane = new stdClass();
    $pane->pid = 'new-bb3d2f83-ed62-4935-aff3-da6d5ff1dd98';
    $pane->panel = 'left';
    $pane->type = 'rate_widget';
    $pane->subtype = 'rate_widget';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'build_mode' => '1',
      'widget_name' => '1',
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'bb3d2f83-ed62-4935-aff3-da6d5ff1dd98';
    $display->content['new-bb3d2f83-ed62-4935-aff3-da6d5ff1dd98'] = $pane;
    $display->panels['left'][4] = 'new-bb3d2f83-ed62-4935-aff3-da6d5ff1dd98';
    $pane = new stdClass();
    $pane->pid = 'new-0710523a-30a2-4cb4-ae2e-503d783e67c6';
    $pane->panel = 'right';
    $pane->type = 'token';
    $pane->subtype = 'node:flag-node-follow-link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
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
    $pane->uuid = '0710523a-30a2-4cb4-ae2e-503d783e67c6';
    $display->content['new-0710523a-30a2-4cb4-ae2e-503d783e67c6'] = $pane;
    $display->panels['right'][0] = 'new-0710523a-30a2-4cb4-ae2e-503d783e67c6';
    $pane = new stdClass();
    $pane->pid = 'new-2c3bb982-429d-4ca6-b69e-8dbf93b9e8ac';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2c3bb982-429d-4ca6-b69e-8dbf93b9e8ac';
    $display->content['new-2c3bb982-429d-4ca6-b69e-8dbf93b9e8ac'] = $pane;
    $display->panels['right'][1] = 'new-2c3bb982-429d-4ca6-b69e-8dbf93b9e8ac';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}
