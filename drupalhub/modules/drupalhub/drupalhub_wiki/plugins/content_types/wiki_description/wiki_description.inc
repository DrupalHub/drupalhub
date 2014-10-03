<?php

$plugin = array(
  'title' => t('Welcome text'),
  'description' => t('Welcome text.'),
  'category' => t('DrupalHub wiki'),
);

function drupalhub_wiki_wiki_description_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = '';
  $block->content = t('Welcome to DrupalHub wikipedia. This is where you can find info on how to work with Drupal in several levels. Good luck!');
  return $block;
}

/**
 * Form settings.
 */
function drupalhub_wiki_wiki_description_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_wiki_wiki_description_box_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

