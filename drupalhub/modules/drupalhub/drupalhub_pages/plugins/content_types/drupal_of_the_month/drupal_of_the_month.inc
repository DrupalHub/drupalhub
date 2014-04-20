<?php

$plugin = array(
  'title' => t('Drupal of the month'),
  'description' => t('Display the drupal of the month.'),
  'category' => t('DrupalHub pages'),
);

function drupalhub_pages_drupal_of_the_month_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = '';
  $block->content = 'a';

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_pages_drupal_of_the_month_content_type_edit_form($form, &$form_state) {
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => 'foo',
  );
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_pages_drupal_of_the_month_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

