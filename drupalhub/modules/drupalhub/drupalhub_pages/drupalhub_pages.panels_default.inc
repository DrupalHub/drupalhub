<?php
/**
 * @file
 * drupalhub_pages.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function drupalhub_pages_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'question_display';
  $mini->category = 'DrupalHub';
  $mini->admin_title = 'Question display';
  $mini->admin_description = '';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'Node',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5961638e-9a52-43e5-95c9-55c2c4498487';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-54b63e5a-2d58-4d87-a6d9-f7c3eb25e227';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_vote';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = '54b63e5a-2d58-4d87-a6d9-f7c3eb25e227';
    $display->content['new-54b63e5a-2d58-4d87-a6d9-f7c3eb25e227'] = $pane;
    $display->panels['left'][0] = 'new-54b63e5a-2d58-4d87-a6d9-f7c3eb25e227';
    $pane = new stdClass();
    $pane->pid = 'new-533249f1-8d54-4d5b-9067-f5a56880a293';
    $pane->panel = 'right';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = '533249f1-8d54-4d5b-9067-f5a56880a293';
    $display->content['new-533249f1-8d54-4d5b-9067-f5a56880a293'] = $pane;
    $display->panels['right'][0] = 'new-533249f1-8d54-4d5b-9067-f5a56880a293';
    $pane = new stdClass();
    $pane->pid = 'new-7a3cd7b1-e896-4eb1-8bbc-edce219b0c1e';
    $pane->panel = 'right';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'long',
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = '7a3cd7b1-e896-4eb1-8bbc-edce219b0c1e';
    $display->content['new-7a3cd7b1-e896-4eb1-8bbc-edce219b0c1e'] = $pane;
    $display->panels['right'][1] = 'new-7a3cd7b1-e896-4eb1-8bbc-edce219b0c1e';
    $pane = new stdClass();
    $pane->pid = 'new-5bc5b4d3-2e35-46b9-bcdf-6d101f85772c';
    $pane->panel = 'right';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = '5bc5b4d3-2e35-46b9-bcdf-6d101f85772c';
    $display->content['new-5bc5b4d3-2e35-46b9-bcdf-6d101f85772c'] = $pane;
    $display->panels['right'][2] = 'new-5bc5b4d3-2e35-46b9-bcdf-6d101f85772c';
    $pane = new stdClass();
    $pane->pid = 'new-513d16ef-4790-4021-86fb-ef2cc42d7c9b';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_social_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'social_buttons_formatter_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
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
    $pane->uuid = '513d16ef-4790-4021-86fb-ef2cc42d7c9b';
    $display->content['new-513d16ef-4790-4021-86fb-ef2cc42d7c9b'] = $pane;
    $display->panels['right'][3] = 'new-513d16ef-4790-4021-86fb-ef2cc42d7c9b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-54b63e5a-2d58-4d87-a6d9-f7c3eb25e227';
  $mini->display = $display;
  $export['question_display'] = $mini;

  return $export;
}
