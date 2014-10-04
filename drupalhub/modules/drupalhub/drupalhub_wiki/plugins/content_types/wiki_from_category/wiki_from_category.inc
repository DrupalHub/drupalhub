<?php

$plugin = array(
  'title' => t('Wiki from category'),
  'description' => t('DDisplay a list of nodes from a given category.'),
  'category' => t('DrupalHub wiki'),
);

function drupalhub_wiki_wiki_from_category_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = '';
  return $block;
}

/**
 * Form settings.
 */
function drupalhub_wiki_wiki_from_category_content_type_edit_form($form, &$form_state) {
  $form['position'] = array(
    '#type' => 'select',
    '#title' => t('Position'),
    '#description' => t('Select the position: first, second or third'),
    '#options' => array(
      1 => t('First'),
      2 => t('Second'),
      3 => t('Third'),
    ),
  );
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_wiki_wiki_from_category_box_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

