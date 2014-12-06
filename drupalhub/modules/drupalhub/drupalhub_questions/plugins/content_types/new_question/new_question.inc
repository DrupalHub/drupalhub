<?php

$plugin = array(
  'title' => t('New question'),
  'description' => t('News question plugin.'),
  'category' => t('DrupalHub questions'),
  'hook theme' => 'drupalhub_questions_new_question_content_type_theme',
);

function drupalhub_questions_new_question_content_type_render($subtype, $conf, $args, $context) {

  $block = new stdClass();
  $block->title = '';

  if (!node_access('create', 'question')) {
    return;
  }

  $question_link_small = l('', 'node/add/question');

  $block->content = "";

  drupalhub_core_ckeditor_add_assets('question');
  drupal_add_library('system', 'ui.autocomplete');
  $path = '/plugins/content_types/new_question';
  drupal_add_js(drupal_get_path('module', 'drupalhub_questions') . $path . '/new_question.js');

  $block->content .=
    '<div class="link-new-question hidden-xs">' .
      '<a href="#" data-toggle="modal" data-target="#AddQuestion">' .
        t('Ask question') .
      '</a>' .
    '</div>';
  $block->content .= theme('new_question');

  $block->content .= "<span class='link-new-question visible-xs'>" . $question_link_small . "</span>";
  return $block;
}

/**
 * Form settings.
 */
function drupalhub_questions_new_question_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_questions_new_question_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Delegate hook_theme().
 */
function drupalhub_questions_new_question_content_type_theme(&$theme, $plugin) {
  $theme['new_question'] = array(
    'path' => $plugin['path'],
    'template' => 'new-question',
  );
}

