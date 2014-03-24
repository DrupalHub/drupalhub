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
  $display->uuid = 'fd5678f5-dea1-4f71-bebf-9b0ad3f95422';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-74330fdd-bb63-439c-b779-097eb7de3198';
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
    $pane->uuid = '74330fdd-bb63-439c-b779-097eb7de3198';
    $display->content['new-74330fdd-bb63-439c-b779-097eb7de3198'] = $pane;
    $display->panels['left'][0] = 'new-74330fdd-bb63-439c-b779-097eb7de3198';
    $pane = new stdClass();
    $pane->pid = 'new-abd68fc5-0c4b-4ed9-88de-81cb404a6107';
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
    $pane->uuid = 'abd68fc5-0c4b-4ed9-88de-81cb404a6107';
    $display->content['new-abd68fc5-0c4b-4ed9-88de-81cb404a6107'] = $pane;
    $display->panels['left'][1] = 'new-abd68fc5-0c4b-4ed9-88de-81cb404a6107';
    $pane = new stdClass();
    $pane->pid = 'new-310f1e2b-44c2-44cd-9bc4-ba9a426e2901';
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
    $pane->uuid = '310f1e2b-44c2-44cd-9bc4-ba9a426e2901';
    $display->content['new-310f1e2b-44c2-44cd-9bc4-ba9a426e2901'] = $pane;
    $display->panels['left'][2] = 'new-310f1e2b-44c2-44cd-9bc4-ba9a426e2901';
    $pane = new stdClass();
    $pane->pid = 'new-908dccff-003e-4ef9-956a-c14f1ea3cf45';
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
    $pane->uuid = '908dccff-003e-4ef9-956a-c14f1ea3cf45';
    $display->content['new-908dccff-003e-4ef9-956a-c14f1ea3cf45'] = $pane;
    $display->panels['left'][3] = 'new-908dccff-003e-4ef9-956a-c14f1ea3cf45';
    $pane = new stdClass();
    $pane->pid = 'new-7fec6a26-c419-480d-a14e-413b3a38cfc5';
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
    $pane->uuid = '7fec6a26-c419-480d-a14e-413b3a38cfc5';
    $display->content['new-7fec6a26-c419-480d-a14e-413b3a38cfc5'] = $pane;
    $display->panels['left'][4] = 'new-7fec6a26-c419-480d-a14e-413b3a38cfc5';
    $pane = new stdClass();
    $pane->pid = 'new-7ef1184c-1acc-4511-afe5-42a200f9c2a3';
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
    $pane->uuid = '7ef1184c-1acc-4511-afe5-42a200f9c2a3';
    $display->content['new-7ef1184c-1acc-4511-afe5-42a200f9c2a3'] = $pane;
    $display->panels['right'][0] = 'new-7ef1184c-1acc-4511-afe5-42a200f9c2a3';
    $pane = new stdClass();
    $pane->pid = 'new-1e4985aa-3fc6-4c59-b131-62ba1c95e6e2';
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
    $pane->uuid = '1e4985aa-3fc6-4c59-b131-62ba1c95e6e2';
    $display->content['new-1e4985aa-3fc6-4c59-b131-62ba1c95e6e2'] = $pane;
    $display->panels['right'][1] = 'new-1e4985aa-3fc6-4c59-b131-62ba1c95e6e2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}
