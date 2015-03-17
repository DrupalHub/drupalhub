<?php

/**
 * @file
 * Contains DrupalHubPlayList.
 */

class DrupalHubPlayList extends \DrupalHubRestfulNode {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['videos'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'videosProcess'),
      ),
    );

    $public_fields['videos_number'] = array(
      'property' => 'field_videos',
      'process_callbacks' => array(
        array($this, 'countVideos'),
      ),
    );

    $public_fields['duration'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'countDuration'),
      ),
    );

    $public_fields['image'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'processImage'),
      ),
    );

    return $public_fields;
  }

  public function videosProcess($nid) {
    $handler = restful_get_restful_handler('video');
    $wrapper = entity_metadata_wrapper('node', $nid);

    $ids = $wrapper->field_videos->value(array('identifier' => TRUE));

    $videos = array();
    foreach ($ids as $id) {
      $videos[] = $handler->viewEntity($id);
    }
    return $videos;
  }

  public function countVideos($field_videos) {
    return count($field_videos);
  }

  public function countDuration($nid) {
    $wrapper = entity_metadata_wrapper('node', $nid);
    $duration = 0;
    foreach ($wrapper->field_videos as $video) {
      $address = $video->field_address->value();
      $data = unserialize($address['video_data']);
      $duration += $data['media$group']['media$content'][0]['duration'];
    }

    return gmdate("H:i:s", $duration);
  }

  public function processImage($nid) {
    $wrapper = entity_metadata_wrapper('node', $nid);
    $address = $wrapper->field_videos->get(0)->field_address->value();
    $embed = _video_embed_field_get_youtube_id($address['video_url']);
    return "http://img.youtube.com/vi/{$embed}/0.jpg";;
  }

}
