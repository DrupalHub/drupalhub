<?php

$plugin = array(
  'title' => t('Playlist videos'),
  'category' => t('DrupalHub youtube'),
);

function drupalhub_videos_playlist_videos_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  if (empty($_GET['playlist'])) {
    return $block;
  }

  $wrapper = entity_metadata_wrapper('node', $_GET['playlist']);

  $playlists = array();

  foreach ($wrapper->field_videos as $video) {
    $address = $video->field_address->value();

    $id = _video_embed_field_get_youtube_id($address['video_url']);
    $information = drupalhub_videos_get_metadata($id);

    $playlists[] = theme('playlist_item', array(
      'label' => l($video->label(), 'node/' . $video->getIdentifier(), array('query' => array('playlist' => $wrapper->getIdentifier()))),
      'length' => drupalhub_videos_youtube_metadata::durationToText($information),
      'image' => theme('image_style', array('style_name' => 'thumbnail', 'path' => $address['thumbnail_path'])),
    ));
  }

  $block->content = theme('playlist_views', array(
    'label' => $wrapper->label(),
    'list' => theme('item_list', array('items' => $playlists)),
  ));

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_videos_playlist_videos_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_videos_playlist_videos_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}