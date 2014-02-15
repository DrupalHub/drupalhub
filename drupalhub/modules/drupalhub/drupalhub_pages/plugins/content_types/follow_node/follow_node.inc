<?php

$plugin = array(
  'title' => t('Follow node'),
  'description' => t('Display a follow link to a node'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('DrupalHub pages'),
);

function drupalhub_pages_follow_node_content_type_render($subtype, $conf, $args, $context) {
  global $language;
  $block = new stdClass();
  $node = $context->data;

  watcher_node_view($node, 'full', $language->language);

  $block->content = empty($node->content['watcher']['#markup']) ? '' : $node->content['watcher']['#markup'];
  return $block;
}
