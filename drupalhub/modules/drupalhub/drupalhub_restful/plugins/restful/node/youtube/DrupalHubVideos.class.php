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

    $public_fields['address'] = array(
      'property' => 'field_address',
      'sub_property' => 'video_url',
    );

    return $public_fields;
  }

}
