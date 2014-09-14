<?php

/**
 * @file
 * Contains RestfulEntityBaseUser.
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

    unset($public_fields['self']);

    return $public_fields;
  }

  /**
   * Overrides \RestfulEntityBase::getQueryForList().
   *
   * Skip the anonymous user in listing.
   */
  public function getQueryForList() {
    return parent::getQueryForList()
      ->propertyCondition('title', $_GET['title'], 'CONTAINS')
      ->fieldCondition('field_show_in_videos', 'value', 1);
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
}
