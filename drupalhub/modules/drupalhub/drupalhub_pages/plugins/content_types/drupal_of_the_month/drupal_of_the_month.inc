<?php

$plugin = array(
  'title' => t('Drupal of the month'),
  'description' => t('Display the drupal of the month.'),
  'category' => t('DrupalHub pages'),
);

function drupalhub_pages_drupal_of_the_month_content_type_render($subtype, $conf, $args, $context) {
  $node = node_load(variable_get('drupal_of_the_month'));

  $block = new stdClass();
  $block->title = '';

  if ($node) {
    $block->content = node_view($node, 'full');
  }

  return $block;
}


