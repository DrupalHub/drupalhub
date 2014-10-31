<?php

$plugin = array(
  'title' => t('Title with inline edit'),
  'description' => t('Inline edit title'),
  'category' => t('DrupalHub questions'),
  'hook theme' => 'drupalhub_questions_title_inline_edit_content_type_theme',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

function drupalhub_questions_title_inline_edit_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = theme('title_inline_edit', array(
    'title' => $context->data->title,
  ));

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_questions_title_inline_edit_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_questions_title_inline_edit_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Delegate hook_theme().
 */
function drupalhub_questions_title_inline_edit_content_type_theme(&$theme, $plugin) {
  $theme['title_inline_edit'] = array(
    'path' => $plugin['path'],
    'template' => 'title-inline-edit',
  );
}

