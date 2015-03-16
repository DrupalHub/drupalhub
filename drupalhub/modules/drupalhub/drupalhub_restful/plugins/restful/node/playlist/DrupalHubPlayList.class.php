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
      'property' => 'field_videos',
      'process_callbacks' => array(
        array($this, 'videosProcess'),
      ),
    );

    $public_fields['access'] = array(
      'property' => 'field_access_level',
    );

    return $public_fields;
  }

}
