<?php

/**
 * @file
 * vote_up_down.inc
 *
 * todo: Remove after finishing the work on the new vote up down.
 */

$plugin = array(
  'title' => t('Vote up down'),
  'description' => t('Supplying the widget for voting to a question without using the full node content.'),
  'category' => t('DrupalHub questions'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Content type render function.
 */
function drupalhub_questions_vote_up_down_content_type_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  $node_type = $node->type;
  $widget_showmode = variable_get('vud_node_widget_show', VUD_NODE_DISPLAY_BOTH);
  $tag = variable_get('vud_tag', 'vote');
  $widget = variable_get('vud_node_widget', 'plain');
  $vote_on_teaser = (bool)variable_get('vud_node_widget_vote_on_teaser', TRUE);
  $can_edit = user_access('use vote up/down on nodes');

  $widget_message_code = VUD_WIDGET_MESSAGE_ERROR;

  if (!$can_edit) {
    $widget_message_code = VUD_WIDGET_MESSAGE_DENIED;
  }
  elseif (!$vote_on_teaser) {
    $widget_message_code = VUD_NODE_WIDGET_MESSAGE_TEASER_DENIED;
  }

  $block = new stdClass();
  $block->title = '';
  $block->content = theme('vud_widget', array(
    'entity_id' => $node->nid,
    'type' => 'node',
    'tag' => $tag,
    'widget_theme' => $widget,
    'readonly' => !$can_edit,
    'widget_message_code' => $widget_message_code,
  ));


  return $block;
}

/**
 * Form callback for editing config.
 */
function drupalhub_questions_vote_up_down_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Form submit callback;
 */
function drupalhub_questions_vote_up_down_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
