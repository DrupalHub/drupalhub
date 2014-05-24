<?php

$plugin = array(
  'title' => t('Popular tags'),
  'description' => t('Display a list of all the popular tags terms.'),
  'category' => t('DrupalHub pages'),
);

function drupalhub_pages_popular_tags_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = '';

  // Get all the tagged terms.
  $tagged_tids = drupalhub_pages_tagged_terms();

  // Load all the terms.
  $terms = taxonomy_term_load_multiple(array_keys($tagged_tids));

  // Build a list with a link to the terms and the number of tagged items.
  $tagged_items = array();

  foreach ($terms as $term) {
    $uri = entity_uri('taxonomy_term', $term);

    $tagged_items[] = array(
      'link' => l($term->name, $uri['path']),
      'tagged' => drupalhub_pages_count_tagged_entities($term->tid),
    );
  }

  // Ordering the terms by the number of tagged nodes.
  usort($tagged_items, 'drupalhub_pages_order_terms');

  // Build an array of items for the theme list function.
  $items = array();

  foreach ($tagged_items as $item) {
    $items[] = $item['link'];
  }

  $variables = array(
    'items' => $items,
    'attributes' => array(
      'class' => 'tagged_items',
    ),
  );

  $block->content = theme('item_list', $variables);

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_pages_popular_tags_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_pages_popular_tags_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

