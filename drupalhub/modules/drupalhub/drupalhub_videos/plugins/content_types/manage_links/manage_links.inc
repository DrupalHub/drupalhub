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
    return $block;
  }

  if ($conf['page'] == 'manage_playlist') {
    $block->content = '<div class="new-video hidden-xs"><a href="#" class="show-playlist-form">New playlist</a></div>';
  }
  else {
    $block->content = '<div class="hidden-xs">';

    // Any user can manage playlists.
    $block->content .= "<div class='manage-playlist clearfix'>" . l(t('Manage playlists'), 'video/playlists') . '</div>';


    if (user_access('create youtube content')) {
      $path = '/plugins/content_types/manage_links/';
      drupal_add_js(drupal_get_path('module', 'drupalhub_videos') . $path . '/add_video.js');

      $block->content .=
        '<div class="new-video">' .
        '<a href="#" data-toggle="modal" data-target="#AddVideo">' .
        t('Add video') .
        '</a>'.
        '</div>';
      $block->content .= theme('add_video');
    }
    $block->content .= '</div>';
  }

  return $block;
}

function drupalhub_videos_manage_links_content_type_theme(&$theme, $plugin) {
  $theme['add_video'] = array(
    'path' => $plugin['path'],
    'template' => 'add-video',
  );
}

/**
 * Form settings.
 */
function drupalhub_videos_manage_links_content_type_edit_form($form, &$form_state) {
  $form['page'] = array(
    '#type' => 'select',
    '#title' => t('Page'),
    '#options' => array(
      'gallery' => t('Gallery front page'),
      'manage_playlist' => t('Playlist manager'),
    ),
    '#default_value' => !empty($form_state['conf']['page']) ? $form_state['conf']['page'] : 'gallery',
  );
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_videos_manage_links_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
