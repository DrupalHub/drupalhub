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
  $display->uuid = '33e1fe90-b674-4e24-8ce5-a4834818e663';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-18c17792-e2a8-4cc5-b24a-a9a4d61b8bd4';
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
    $pane->uuid = '18c17792-e2a8-4cc5-b24a-a9a4d61b8bd4';
    $display->content['new-18c17792-e2a8-4cc5-b24a-a9a4d61b8bd4'] = $pane;
    $display->panels['left'][0] = 'new-18c17792-e2a8-4cc5-b24a-a9a4d61b8bd4';
    $pane = new stdClass();
    $pane->pid = 'new-e932d58e-2e85-4511-90be-c4db9ef1e6f3';
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
    $pane->uuid = 'e932d58e-2e85-4511-90be-c4db9ef1e6f3';
    $display->content['new-e932d58e-2e85-4511-90be-c4db9ef1e6f3'] = $pane;
    $display->panels['left'][1] = 'new-e932d58e-2e85-4511-90be-c4db9ef1e6f3';
    $pane = new stdClass();
    $pane->pid = 'new-37463e57-2fc1-4b4c-b012-fa23152e9454';
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
    $pane->uuid = '37463e57-2fc1-4b4c-b012-fa23152e9454';
    $display->content['new-37463e57-2fc1-4b4c-b012-fa23152e9454'] = $pane;
    $display->panels['left'][2] = 'new-37463e57-2fc1-4b4c-b012-fa23152e9454';
    $pane = new stdClass();
    $pane->pid = 'new-c3ddada3-7619-4fcd-b3c6-6c7a48bbacca';
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
    $pane->uuid = 'c3ddada3-7619-4fcd-b3c6-6c7a48bbacca';
    $display->content['new-c3ddada3-7619-4fcd-b3c6-6c7a48bbacca'] = $pane;
    $display->panels['left'][3] = 'new-c3ddada3-7619-4fcd-b3c6-6c7a48bbacca';
    $pane = new stdClass();
    $pane->pid = 'new-bd225a86-d7d6-4779-b14a-b4ea73245715';
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
    $pane->uuid = 'bd225a86-d7d6-4779-b14a-b4ea73245715';
    $display->content['new-bd225a86-d7d6-4779-b14a-b4ea73245715'] = $pane;
    $display->panels['left'][4] = 'new-bd225a86-d7d6-4779-b14a-b4ea73245715';
    $pane = new stdClass();
    $pane->pid = 'new-7501319c-5f7f-44e7-9c13-9a7631bb5aaa';
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
    $pane->uuid = '7501319c-5f7f-44e7-9c13-9a7631bb5aaa';
    $display->content['new-7501319c-5f7f-44e7-9c13-9a7631bb5aaa'] = $pane;
    $display->panels['right'][0] = 'new-7501319c-5f7f-44e7-9c13-9a7631bb5aaa';
    $pane = new stdClass();
    $pane->pid = 'new-a2bae353-1225-4eeb-8a94-dfeeb8c1951e';
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
    $pane->uuid = 'a2bae353-1225-4eeb-8a94-dfeeb8c1951e';
    $display->content['new-a2bae353-1225-4eeb-8a94-dfeeb8c1951e'] = $pane;
    $display->panels['right'][1] = 'new-a2bae353-1225-4eeb-8a94-dfeeb8c1951e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}
