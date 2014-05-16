<?php

$plugin = array(
  'title' => t('Drupal of the month'),
  'description' => t('Display the drupal of the month.'),
  'category' => t('DrupalHub pages'),
);

function drupalhub_pages_drupal_of_the_month_content_type_render($subtype, $conf, $args, $context) {
  $node = node_load($conf['node_id']);

  $block = new stdClass();
  $block->title = '';

  if ($node) {
    $block->content = node_view($node, 'full');
  }

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_pages_drupal_of_the_month_content_type_edit_form($form, &$form_state) {
  $form['node_id'] = array(
    '#type' => 'textfield',
    '#title' => 'Drupal of the month',
    '#autocomplete_path' => 'drupalhub_pages/autocomplete',
  );

  if ($node = node_load($form_state['conf']['node_id'])) {
    $form['node_id']['#default_value'] = $node->title . ' (' . $node->nid . ')';
  }

  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_pages_drupal_of_the_month_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if ($key == 'node_id') {
      preg_match("/.+\((\d+)\)/", $form_state['values'][$key], $matches);
      $form_state['values'][$key] = $matches[1];
    }

    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

