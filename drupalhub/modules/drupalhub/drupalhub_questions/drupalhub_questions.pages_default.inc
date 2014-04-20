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
  $display->uuid = '35372234-e348-44db-bcd7-d8286a6c93f7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4576d00e-a79a-4ae6-ac03-fcefb827bc45';
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
    $pane->uuid = '4576d00e-a79a-4ae6-ac03-fcefb827bc45';
    $display->content['new-4576d00e-a79a-4ae6-ac03-fcefb827bc45'] = $pane;
    $display->panels['left'][0] = 'new-4576d00e-a79a-4ae6-ac03-fcefb827bc45';
    $pane = new stdClass();
    $pane->pid = 'new-28f37c2e-de00-4135-b66b-c24a88f792de';
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
    $pane->uuid = '28f37c2e-de00-4135-b66b-c24a88f792de';
    $display->content['new-28f37c2e-de00-4135-b66b-c24a88f792de'] = $pane;
    $display->panels['left'][1] = 'new-28f37c2e-de00-4135-b66b-c24a88f792de';
    $pane = new stdClass();
    $pane->pid = 'new-bfd78a4f-d5e5-4553-97c7-687f01165cdd';
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
    $pane->uuid = 'bfd78a4f-d5e5-4553-97c7-687f01165cdd';
    $display->content['new-bfd78a4f-d5e5-4553-97c7-687f01165cdd'] = $pane;
    $display->panels['left'][2] = 'new-bfd78a4f-d5e5-4553-97c7-687f01165cdd';
    $pane = new stdClass();
    $pane->pid = 'new-def7ebb6-10d8-415c-b289-fdb8fbf20586';
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
    $pane->uuid = 'def7ebb6-10d8-415c-b289-fdb8fbf20586';
    $display->content['new-def7ebb6-10d8-415c-b289-fdb8fbf20586'] = $pane;
    $display->panels['left'][3] = 'new-def7ebb6-10d8-415c-b289-fdb8fbf20586';
    $pane = new stdClass();
    $pane->pid = 'new-110861f7-5ff7-4fd3-b72a-cb120f003549';
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
    $pane->uuid = '110861f7-5ff7-4fd3-b72a-cb120f003549';
    $display->content['new-110861f7-5ff7-4fd3-b72a-cb120f003549'] = $pane;
    $display->panels['left'][4] = 'new-110861f7-5ff7-4fd3-b72a-cb120f003549';
    $pane = new stdClass();
    $pane->pid = 'new-8a44c33f-bea9-4250-8136-4fd4bf0d1844';
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
    $pane->uuid = '8a44c33f-bea9-4250-8136-4fd4bf0d1844';
    $display->content['new-8a44c33f-bea9-4250-8136-4fd4bf0d1844'] = $pane;
    $display->panels['right'][0] = 'new-8a44c33f-bea9-4250-8136-4fd4bf0d1844';
    $pane = new stdClass();
    $pane->pid = 'new-491847eb-6dee-4609-b917-2c489fb9666f';
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
    $pane->uuid = '491847eb-6dee-4609-b917-2c489fb9666f';
    $display->content['new-491847eb-6dee-4609-b917-2c489fb9666f'] = $pane;
    $display->panels['right'][1] = 'new-491847eb-6dee-4609-b917-2c489fb9666f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}
