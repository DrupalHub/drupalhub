<?php

$plugin = array(
  'title' => t('Playlist views'),
  'category' => t('DrupalHub youtube'),
  'hook theme' => 'drupalhub_videos_playlist_views_content_type_theme',
);

function drupalhub_videos_playlist_views_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  // Get all the non private playlists.
  $query = new EntityFieldQuery();
  $results = $query
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'playlist')
    ->fieldCondition('field_access_level', 'value', 3, '<>')
    ->execute();

  if (empty($results['node'])) {
    return $block;
  }

  $nodes = node_load_multiple(array_keys($results['node']));

  $playlists = array();
  foreach ($nodes as $node) {
    $wrapper = entity_metadata_wrapper('node', $node);
    $video = $wrapper->field_videos->get(0);
    $address = $video->field_address->value();
    $image = theme('image_style', array('style_name' => 'thumbnail', 'path' => $address['thumbnail_path']));

    $duration = 0;
    foreach ($wrapper->field_videos as $video) {
      $address = $video->field_address->value();

      $id = _video_embed_field_get_youtube_id($address['video_url']);
      $information = drupalhub_videos_get_metadata($id);
      $duration += $information['duration'];
    }

    $playlists[] = theme('playlist_item', array(
      'label' => l($wrapper->label(), 'node/' . $video->getIdentifier(), array('query' => array('playlist' => $wrapper->getIdentifier()))),
      'length' => drupalhub_videos_youtube_metadata::durationToText(array('duration' => $duration)),
      'image' => $image,
    ));
  }

  $block->content = theme('playlist_views', array('list' => theme('item_list', array('items' => $playlists, 'attributes' => array('class' => 'playlist')))));
  return $block;
}

/**
 * Form settings.
 */
function drupalhub_videos_playlist_views_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_videos_playlist_views_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function drupalhub_videos_playlist_views_content_type_theme(&$theme, $plugin) {
  $theme['playlist_views'] = array(
    'path' => $plugin['path'],
    'template' => 'playlist-views',
  );

  $theme['playlist_item'] = array(
    'path' => $plugin['path'],
    'template' => 'playlist-item',
  );
}
