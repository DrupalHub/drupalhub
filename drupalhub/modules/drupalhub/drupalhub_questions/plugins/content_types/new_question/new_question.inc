<?php

$plugin = array(
  'title' => t('New question'),
  'description' => t('News question plugin.'),
  'category' => t('DrupalHub questions'),
);

function drupalhub_questions_new_question_content_type_render($subtype, $conf, $args, $context) {

  $block = new stdClass();
  $block->title = '';

  $question_array_large = array(
    'text' => t('Post a question!'),
    'href' => 'drupalhub_questions/create',
    'class' => 'create-question',
    'modal_settings' => array(
      'modalSize' => array(
        'type' => 'scale',
      ),
      'modalOptions' => array('opacity' => .6),
      'animation' => 'fadeIn',
    ),
  );

  $question_array_small = array(
    'text' => '',
  ) + $question_array_large ;


  $question_link_large = drupalhub_core_modal_window($question_array_large);
  $question_link_small = drupalhub_core_modal_window($question_array_small);

  $block->content = "
    <span class='link-new-question hidden-xs'>" . $question_link_large . "</span>
    <span class='link-new-question visible-xs'>" . $question_link_small . "</span>
  ";
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

