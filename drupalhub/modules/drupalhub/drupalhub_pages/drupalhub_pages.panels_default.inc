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
  $display->uuid = '91fe208d-8692-4faf-ab85-e1931249953e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-61702c00-6d8a-4528-b2f0-d47f1af54f73';
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
    $pane->uuid = '61702c00-6d8a-4528-b2f0-d47f1af54f73';
    $display->content['new-61702c00-6d8a-4528-b2f0-d47f1af54f73'] = $pane;
    $display->panels['left'][0] = 'new-61702c00-6d8a-4528-b2f0-d47f1af54f73';
    $pane = new stdClass();
    $pane->pid = 'new-d3e5c917-ccca-4846-a890-239f8894a90f';
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
    $pane->uuid = 'd3e5c917-ccca-4846-a890-239f8894a90f';
    $display->content['new-d3e5c917-ccca-4846-a890-239f8894a90f'] = $pane;
    $display->panels['right'][0] = 'new-d3e5c917-ccca-4846-a890-239f8894a90f';
    $pane = new stdClass();
    $pane->pid = 'new-fb7c2a14-262c-426f-8507-1f344f2406ab';
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
    $pane->uuid = 'fb7c2a14-262c-426f-8507-1f344f2406ab';
    $display->content['new-fb7c2a14-262c-426f-8507-1f344f2406ab'] = $pane;
    $display->panels['right'][1] = 'new-fb7c2a14-262c-426f-8507-1f344f2406ab';
    $pane = new stdClass();
    $pane->pid = 'new-2fed52b9-a0a0-46eb-8120-e3c6879574e4';
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
    $pane->uuid = '2fed52b9-a0a0-46eb-8120-e3c6879574e4';
    $display->content['new-2fed52b9-a0a0-46eb-8120-e3c6879574e4'] = $pane;
    $display->panels['right'][2] = 'new-2fed52b9-a0a0-46eb-8120-e3c6879574e4';
    $pane = new stdClass();
    $pane->pid = 'new-8f3d65ee-8140-48b1-be1a-a2e924e1219e';
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
    $pane->uuid = '8f3d65ee-8140-48b1-be1a-a2e924e1219e';
    $display->content['new-8f3d65ee-8140-48b1-be1a-a2e924e1219e'] = $pane;
    $display->panels['right'][3] = 'new-8f3d65ee-8140-48b1-be1a-a2e924e1219e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-61702c00-6d8a-4528-b2f0-d47f1af54f73';
  $mini->display = $display;
  $export['question_display'] = $mini;

  return $export;
}
