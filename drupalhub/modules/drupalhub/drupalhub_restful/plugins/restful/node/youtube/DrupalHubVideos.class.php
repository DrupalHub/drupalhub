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
    $start = new DateTime();
    $start->add(new DateInterval($data['duration']));
    $start->format('H:i:s');
    return $start->format('H:i:s');
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
      $data = array('video_url' => $value);
      return $data;
    }

    return parent::propertyValuesPreprocess($property_name, $value, $public_field_name);
  }

}
