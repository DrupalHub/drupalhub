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

  public function create() {
    $request = $this->getRequest();
    static::cleanRequest($request);

    foreach (array('entity_type', 'entity_id', 'value') as $required) {
      if (empty($request[$required])) {
        throw new \RestfulBadRequestException(format_string('The field @field cannot be empty.', array('@field' => $required)));
      }
    }

    if (!in_array($request['value'], array(-1, 1))) {
      throw new \RestfulBadRequestException('The value need to be between -1 or 1.');
    }

    $this->processRequest();

    return parent::create();
  }

  /**
   * Checking a couple of things before creating the vote.
   */
  private function processRequest() {
    $account = $this->getAccount();

    // Check what's the type of the request.
    $type = $this->request['value'] == 1 ? 'up' : 'down';

    $this->checkIfUserCanVote();
    $this->checkIfTypeHasCommitted();
  }

  private function checkIfUserCanVote() {
    
  }

  private function checkIfTypeHasCommitted() {
  }

}
