<?php

/**
 * @file
 * Contains RestfulEntityBaseUser.
 */

class DrupalHubPlayList extends \RestfulEntityBase {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['videos'] = array(
      'property' => 'field_videos',
    );

    $public_fields['access'] = array(
      'property' => 'field_access_level',
    );

    $public_fields['body'] = array(
      'property' => 'body',
    );

    return $public_fields;
  }

}
