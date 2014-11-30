<?php

$plugin = array(
  'title' => t('Search results'),
  'description' => t('News question plugin.'),
  'category' => t('DrupalHub search'),
  'required context' => array(
    new ctools_context_optional(t('Type'), 'string'),
    new ctools_context_optional(t('String'), 'string'),
  ),
);

function drupalhub_search_search_results_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = '';
  list($type, $string) = $context;

  $indexes = array(
    'node' => t('Content'),
    'taxonomy_term' => t('Tags'),
    'user' => t('Users'),
    'comment' => t('Comments'),
  );

  $items = array();

  foreach ($indexes as $index => $label) {
    $link = l($label, 'search_results/' . $index . '/' . $string->data, array('attributes' => array('role' => 'tab')));

    $class = $index == $type->data ? array('active') : array();
    $items[] = array('data' => $link, 'class' => $class);
  }

  $block->content = "";
  $block->content .= theme('item_list', array('items' => $items, 'attributes' => array('class' => 'nav nav-tabs', 'role' => 'tablist')));
  $block->content .= drupalhub_search_results($type->data, $string->data);

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

