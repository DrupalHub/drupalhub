<?php

$plugin = array(
  'title' => t('Search results'),
  'description' => t('News question plugin.'),
  'category' => t('DrupalHub search'),
);

function drupalhub_search_search_results_content_type_render($subtype, $conf, $args, $context) {

  $block = new stdClass();
  $block->title = '';

  $block->content = "";
  $block->content .= drupalhub_search_results('Drupal');

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_search_search_results_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_search_search_results_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

