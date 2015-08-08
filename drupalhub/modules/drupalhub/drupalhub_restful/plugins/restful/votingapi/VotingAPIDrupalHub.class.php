<?php

/**
 * @file
 * Contains RestfulExampleNodeUserResource.
 */

class VotingAPIDrupalHub extends \RestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {

  /**
   * {@inheritdoc}
   */
  public function publicFieldsInfo() {
    $public_fields['id'] = array(
      'property' => 'vote_id',
    );

    $simple_field = array('entity_type', 'entity_id', 'value', 'value_type', 'tag', 'uid', 'timestamp', 'vote_source');

    foreach ($simple_field as $field) {
      $public_fields[$field] = array(
        'property' => $field,
      );
    }

    return $public_fields;
  }

}
