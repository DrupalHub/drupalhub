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
  $display->uuid = 'e1225ecc-1fc8-49ee-bb98-6dc6d1142327';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-50ec4ee6-fd4d-40e6-8071-9c4de495e57a';
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
    $pane->uuid = '50ec4ee6-fd4d-40e6-8071-9c4de495e57a';
    $display->content['new-50ec4ee6-fd4d-40e6-8071-9c4de495e57a'] = $pane;
    $display->panels['left'][0] = 'new-50ec4ee6-fd4d-40e6-8071-9c4de495e57a';
    $pane = new stdClass();
    $pane->pid = 'new-821f91ea-fcc9-4f6e-9845-82d0775e6d09';
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
    $pane->uuid = '821f91ea-fcc9-4f6e-9845-82d0775e6d09';
    $display->content['new-821f91ea-fcc9-4f6e-9845-82d0775e6d09'] = $pane;
    $display->panels['right'][0] = 'new-821f91ea-fcc9-4f6e-9845-82d0775e6d09';
    $pane = new stdClass();
    $pane->pid = 'new-39a98286-9f11-48e3-9015-b13f1b87795e';
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
    $pane->uuid = '39a98286-9f11-48e3-9015-b13f1b87795e';
    $display->content['new-39a98286-9f11-48e3-9015-b13f1b87795e'] = $pane;
    $display->panels['right'][1] = 'new-39a98286-9f11-48e3-9015-b13f1b87795e';
    $pane = new stdClass();
    $pane->pid = 'new-1f46cc75-ecf9-4c1e-8baa-8c66cf4012d2';
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
    $pane->uuid = '1f46cc75-ecf9-4c1e-8baa-8c66cf4012d2';
    $display->content['new-1f46cc75-ecf9-4c1e-8baa-8c66cf4012d2'] = $pane;
    $display->panels['right'][2] = 'new-1f46cc75-ecf9-4c1e-8baa-8c66cf4012d2';
    $pane = new stdClass();
    $pane->pid = 'new-c88b2d6c-4845-47a5-b8de-f7ca534825fb';
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
    $pane->uuid = 'c88b2d6c-4845-47a5-b8de-f7ca534825fb';
    $display->content['new-c88b2d6c-4845-47a5-b8de-f7ca534825fb'] = $pane;
    $display->panels['right'][3] = 'new-c88b2d6c-4845-47a5-b8de-f7ca534825fb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-50ec4ee6-fd4d-40e6-8071-9c4de495e57a';
  $mini->display = $display;
  $export['question_display'] = $mini;

  return $export;
}
