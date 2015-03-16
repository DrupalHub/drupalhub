<?php

/**
 * @file
 * Contains DrupalHubPlayList.
 */

class DrupalHubQuestion extends \DrupalHubRestfulNode {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['tags'] = array(
      'property' => 'field_tags',
      'process_callbacks' => array(
        array($this, 'processTags'),
      ),
    );

    return $public_fields;
  }

}
