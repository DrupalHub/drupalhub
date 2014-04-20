<?php

$plugin = array(
  'title' => t('Popular tags'),
  'description' => t('Display a list of all the popular tags terms.'),
  'category' => t('DrupalHub pages'),
);

function drupalhub_pages_popular_tags_content_type_render($subtype, $conf, $args, $context) {
  drupal_add_css(drupal_get_path('module', 'drupalhub_pages') . '/css/drupalhub_pages.css');

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
    $items[] = $item['link'] . ' (' . $item['tagged'] . ')';
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
