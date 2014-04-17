<?php
/**
 * @file
 * drupalhub_group.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function drupalhub_group_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Group page',
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
              'drupalhub_group' => 'drupalhub_group',
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
  $display->layout = 'threecol_33_34_33_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => array(
        'corner_location' => 'pane',
      ),
      'left' => array(
        'corner_location' => 'pane',
      ),
      'middle' => array(
        'corner_location' => 'pane',
      ),
      'right' => array(
        'corner_location' => 'pane',
      ),
      'bottom' => NULL,
    ),
    'top' => array(
      'style' => 'rounded_corners',
    ),
    'right' => array(
      'style' => 'rounded_corners',
    ),
    'middle' => array(
      'style' => 'rounded_corners',
    ),
    'left' => array(
      'style' => 'rounded_corners',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title\'s page';
  $display->uuid = '73b4d8c1-00a4-4caa-b2bd-2bc77b532ad8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c914e306-8e33-4cc0-86af-0e573eede1f5';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_group_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'medium',
        'image_link' => '',
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
    $pane->uuid = 'c914e306-8e33-4cc0-86af-0e573eede1f5';
    $display->content['new-c914e306-8e33-4cc0-86af-0e573eede1f5'] = $pane;
    $display->panels['left'][0] = 'new-c914e306-8e33-4cc0-86af-0e573eede1f5';
    $pane = new stdClass();
    $pane->pid = 'new-bb6103c0-2c94-4858-a268-f17161395822';
    $pane->panel = 'left';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bb6103c0-2c94-4858-a268-f17161395822';
    $display->content['new-bb6103c0-2c94-4858-a268-f17161395822'] = $pane;
    $display->panels['left'][1] = 'new-bb6103c0-2c94-4858-a268-f17161395822';
    $pane = new stdClass();
    $pane->pid = 'new-1c84de1e-f274-4d48-ba22-ff8d55c791b9';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'og_content_for_group_page-panel_pane_3';
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
    $pane->uuid = '1c84de1e-f274-4d48-ba22-ff8d55c791b9';
    $display->content['new-1c84de1e-f274-4d48-ba22-ff8d55c791b9'] = $pane;
    $display->panels['middle'][0] = 'new-1c84de1e-f274-4d48-ba22-ff8d55c791b9';
    $pane = new stdClass();
    $pane->pid = 'new-e8e2eae9-baac-421c-a295-61966b99c331';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'og_content_for_group_page-panel_pane_5';
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
    $pane->uuid = 'e8e2eae9-baac-421c-a295-61966b99c331';
    $display->content['new-e8e2eae9-baac-421c-a295-61966b99c331'] = $pane;
    $display->panels['right'][0] = 'new-e8e2eae9-baac-421c-a295-61966b99c331';
    $pane = new stdClass();
    $pane->pid = 'new-f0ecaeb1-8865-428f-8ee8-19cf199dee8c';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'og_content_for_group_page-panel_pane_4';
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
    $pane->uuid = 'f0ecaeb1-8865-428f-8ee8-19cf199dee8c';
    $display->content['new-f0ecaeb1-8865-428f-8ee8-19cf199dee8c'] = $pane;
    $display->panels['right'][1] = 'new-f0ecaeb1-8865-428f-8ee8-19cf199dee8c';
    $pane = new stdClass();
    $pane->pid = 'new-1ae4045b-cabf-407c-b462-eacfd3372da0';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'og_content_for_group_page-panel_pane_2';
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
    $pane->uuid = '1ae4045b-cabf-407c-b462-eacfd3372da0';
    $display->content['new-1ae4045b-cabf-407c-b462-eacfd3372da0'] = $pane;
    $display->panels['right'][2] = 'new-1ae4045b-cabf-407c-b462-eacfd3372da0';
    $pane = new stdClass();
    $pane->pid = 'new-87458495-42cd-4431-b2d1-fbaae5ea4b6d';
    $pane->panel = 'top';
    $pane->type = 'views';
    $pane->subtype = 'group_page_carousel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
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
    $pane->uuid = '87458495-42cd-4431-b2d1-fbaae5ea4b6d';
    $display->content['new-87458495-42cd-4431-b2d1-fbaae5ea4b6d'] = $pane;
    $display->panels['top'][0] = 'new-87458495-42cd-4431-b2d1-fbaae5ea4b6d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bb6103c0-2c94-4858-a268-f17161395822';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  return $export;
}
