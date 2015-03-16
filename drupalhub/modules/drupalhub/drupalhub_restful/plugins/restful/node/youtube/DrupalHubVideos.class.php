<?php

/**
 * @file
 * Contains DrupalHubVideos.
 */

class DrupalHubVideos extends \DrupalHubRestfulNode {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['duration'] = array(
      'property' => 'field_address',
      'process_callbacks' => array(
        array($this, 'processDuration'),
      )
    );

    $public_fields['embed'] = array(
      'property' => 'field_address',
      'process_callbacks' => array(
        array($this, 'processVideoId'),
      ),
    );

    $public_fields['image'] = array(
      'property' => 'field_address',
      'process_callbacks' => array(
        array($this, 'processImage'),
      ),
    );

    return $public_fields;
  }

  protected function processDuration($field_address) {
    $data = unserialize($field_address['video_data']);
    return gmdate("H:i:s", $data['media$group']['media$content'][0]['duration']);
  }

  protected function processVideoId($field_address) {
    return _video_embed_field_get_youtube_id($field_address['video_url']);
  }

  protected function processImage($field_address) {
    $embed = $this->processVideoId($field_address);
    return "http://img.youtube.com/vi/{$embed}/0.jpg";
  }

}
