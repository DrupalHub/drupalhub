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
  $display->uuid = '3a1209ff-e4ef-4fe5-bd07-3a5e003e8e6e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-10ab30a1-1c28-40e7-b979-4e218f8a2915';
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
    $pane->uuid = '10ab30a1-1c28-40e7-b979-4e218f8a2915';
    $display->content['new-10ab30a1-1c28-40e7-b979-4e218f8a2915'] = $pane;
    $display->panels['left'][0] = 'new-10ab30a1-1c28-40e7-b979-4e218f8a2915';
    $pane = new stdClass();
    $pane->pid = 'new-ede2bc13-8055-4590-867a-5acb735f4644';
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
    $pane->uuid = 'ede2bc13-8055-4590-867a-5acb735f4644';
    $display->content['new-ede2bc13-8055-4590-867a-5acb735f4644'] = $pane;
    $display->panels['right'][0] = 'new-ede2bc13-8055-4590-867a-5acb735f4644';
    $pane = new stdClass();
    $pane->pid = 'new-a988e3ca-3f26-4f9c-b685-b6331ae4a634';
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
    $pane->uuid = 'a988e3ca-3f26-4f9c-b685-b6331ae4a634';
    $display->content['new-a988e3ca-3f26-4f9c-b685-b6331ae4a634'] = $pane;
    $display->panels['right'][1] = 'new-a988e3ca-3f26-4f9c-b685-b6331ae4a634';
    $pane = new stdClass();
    $pane->pid = 'new-c5dae5c3-f046-4a8a-a98a-4d2114ade46c';
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
    $pane->uuid = 'c5dae5c3-f046-4a8a-a98a-4d2114ade46c';
    $display->content['new-c5dae5c3-f046-4a8a-a98a-4d2114ade46c'] = $pane;
    $display->panels['right'][2] = 'new-c5dae5c3-f046-4a8a-a98a-4d2114ade46c';
    $pane = new stdClass();
    $pane->pid = 'new-2348e651-915e-40ae-9128-33abd90d1d3f';
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
    $pane->uuid = '2348e651-915e-40ae-9128-33abd90d1d3f';
    $display->content['new-2348e651-915e-40ae-9128-33abd90d1d3f'] = $pane;
    $display->panels['right'][3] = 'new-2348e651-915e-40ae-9128-33abd90d1d3f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-10ab30a1-1c28-40e7-b979-4e218f8a2915';
  $mini->display = $display;
  $export['question_display'] = $mini;

  return $export;
}
