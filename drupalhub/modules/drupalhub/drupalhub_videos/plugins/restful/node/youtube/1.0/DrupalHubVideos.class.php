<?php

/**
 * @file
 * Contains DrupalHubVideos.
 */

class DrupalHubVideos extends \RestfulEntityBase {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['image'] = array(
      'property' => 'field_address',
      'process_callbacks' => array(
        array($this, 'imageProcess'),
      ),
    );

    $public_fields['length'] = array(
      'property' => 'field_address',
      'process_callbacks' => array(
        array($this, 'lengthProcess'),
      ),
    );

    $public_fields['description'] = array(
      'property' => 'body',
    );

    $public_fields['address'] = array(
      'property' => 'field_address',
      'process_callbacks' => array(
        array($this, 'addressProcess'),
      ),
    );

    unset($public_fields['self']);

    return $public_fields;
  }

  /**
   * Overrides \RestfulEntityBase::getQueryForList().
   *
   * Return a list of playlist matching to a given title.
   */
  public function getQueryForList() {
    $query = parent::getQueryForList();
    if (!empty($_GET['title'])) {
      $query
        ->propertyCondition('title', $_GET['title'], 'CONTAINS')
        ->fieldCondition('field_show_in_videos', 'value', 1);
    }

    return $query;
  }

  /**
   * Return the duration of the video.
   */
  public function lengthProcess($value) {
    $info = unserialize($value['video_data']);
    return drupalhub_videos_youtube_metadata::durationToText($info['media$group']['media$content'][0]);
  }

  /**
   * Return the path for the video picture.
   */
  public function imageProcess($value) {
    return file_create_url($value['thumbnail_path']);
  }

  /**
   * Return the address of the youtube video and all the metadata from the
   * field.
   */
  public function addressProcess($value) {
    return $value['video_url'];
  }
}
