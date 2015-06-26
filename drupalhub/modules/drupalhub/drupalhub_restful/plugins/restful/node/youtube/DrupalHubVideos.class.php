<?php

/**
 * @file
 * Contains DrupalHubVideos.
 */

class DrupalHubVideos extends \DrupalHubRestfulNode {

  /**
   * @var integer
   *
   * The playlist ID. When dealing with a playlist the url should be different.
   */
  public $playlist;

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

  protected function getListForAutocomplete() {
    $nodes = node_load_multiple(array_keys(parent::getListForAutocomplete()));
    $return = array();

    foreach ($nodes as $node) {
      $return[] = $this->viewEntity($node->nid);
    }

    return $return;
  }

  /**
   * {@inheritdoc}
   */
  public function propertyValuesPreprocess($property_name, $value, $public_field_name) {
    if ($public_field_name == 'embed') {
      $id = _video_embed_field_get_youtube_id($value);
      $data = drupal_http_request('https://www.googleapis.com/youtube/v3/videos?id=' . $id . '&key=AIzaSyB9GaMYWcFitmreglsphxlBIm1WO5IXUeM&part=snippet,contentDetails,statistics,status');
      $video_info = drupal_json_decode($data->data);
      $data = array(
        'video_url' => $value,
        'video_data' => $video_info + array('handler' => 'youtube'),
      );
      return $data;
    }
    return parent::propertyValuesPreprocess($property_name, $value, $public_field_name);
  }

}
