<?php

$plugin = array(
  'title' => t('Manage links'),
  'description' => t('Links for the drupalhub youtube module'),
  'category' => t('DrupalHub youtube'),
  'hook theme' => 'drupalhub_videos_manage_links_content_type_theme',
);

function drupalhub_videos_manage_links_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  // Anonymous users can't do anything relate to youtube.
  if (!user_is_logged_in()) {
    return;
  }

  $block->content = '';

  if (user_access('create youtube content')) {
    $path = '/plugins/content_types/manage_links/';
    drupal_add_js(drupal_get_path('module', 'drupalhub_videos') . $path . '/add_video.js');

    $block->content .=
      '<div class="new-video hidden-xs">' .
        '<a href="#" data-toggle="modal" data-target="#AddVideo">' .
          t('Add video') .
        '</a>'.
      '</div>';
    $block->content .= theme('add_video');
  }

  // Any user can manage playlists.
  $block->content .= '<div class="manage-playlist hidden-xs">' . l(t('Manage playlists'), 'video/playlists') . '</div>';

  return $block;
}

function drupalhub_videos_manage_links_content_type_theme(&$theme, $plugin) {
  $theme['add_video'] = array(
    'path' => $plugin['path'],
    'template' => 'add-video',
  );
}
