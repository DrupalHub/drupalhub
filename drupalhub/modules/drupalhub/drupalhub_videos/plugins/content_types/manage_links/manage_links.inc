<?php

$plugin = array(
  'title' => t('Manage links'),
  'description' => t('Links for the drupalhub youtube module'),
  'category' => t('DrupalHub youtube'),
);

function drupalhub_videos_manage_links_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  $block->content = '';
  $block->content .= '<div class="new-video hidden-xs">' . l(t('Add video'), 'node/add/youtube') . '</div>';

  return $block;
}
