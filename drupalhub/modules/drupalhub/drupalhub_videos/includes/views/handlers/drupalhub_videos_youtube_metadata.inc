<?php

/**
 * Get metadata information about a youtube video.
 */
class drupalhub_videos_youtube_metadata extends views_handler_field_entity {

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $wrapper = entity_metadata_wrapper('node', $this->get_value($values, 'nid'));

    if (!$address = $wrapper->field_address->value()) {
      return '';
    }
    $id = _video_embed_field_get_youtube_id($address['video_url']);

    if (!$information = drupalhub_videos_get_metadata($id)) {
      return;
    }

    // For now, handle the duration of the movie.
    return $this->durationToText($information);
  }

  /**
   * Return the duration of a video in a smart way.
   *
   * @param Array $information
   *   The video metadata.
   *
   * @return String
   *   The duration of the video in a string format.
   */
  public static function durationToText($information) {
    $duration = $information['duration'];

    switch ($duration) {
      case $duration <= 60:
        return gmdate('s', $duration);

      case $duration > 60 && $duration <= 3600:
        return gmdate('i:s', $duration);

      default:
        return gmdate('H:i:s', $duration);
    }
  }
}