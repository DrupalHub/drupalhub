<?php

$plugin = array(
  'title' => t('Events links'),
  'description' => t('Links for the drupalhub calendar'),
  'category' => t('DrupalHub events'),
);

function drupalhub_events_quick_links_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  $block->content = '';
  $block->content .= '<div class="new-event hidden-xs">' . l(t('Add event'), 'node/add/events') . '</div>';

  return $block;
}