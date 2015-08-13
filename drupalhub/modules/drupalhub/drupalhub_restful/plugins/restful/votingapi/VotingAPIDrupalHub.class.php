<?php

/**
 * @file
 * Contains VotingAPIDrupalHub.
 */

class VotingAPIDrupalHub extends \RestfulDataProviderDbQuery implements \RestfulDataProviderDbQueryInterface {

  /**
   * @var String
   *
   * The type of the vote.
   */
  private $type;

  /**
   * @var \StdClass
   *
   * The user object.
   */
  private $account;

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

    $this->request['uid'] = $this->getAccount()->uid;

    $this->processRequest();

    return parent::create();
  }

  /**
   * Checking a couple of things before creating the vote.
   */
  private function processRequest() {
    $this->account = $this->getAccount();

    // Check what's the type of the request.
    $this->type = $this->request['value'] == 1 ? 'up' : 'down';

    $this->checkIfUserCanVote();
    $this->checkIfTypeHasCommitted();
  }

  /**
   * User can vote up or down from a certain amount of point. We need to check
   * it.
   */
  private function checkIfUserCanVote() {
    $wrapper = entity_metadata_wrapper('user', $this->account);
    $points = $wrapper->field_reputation->value();

    if (user_access('can bypass vote limitation', $this->account)) {
      // This user can by pass the voting limitation.
      return;
    }

    // todo: add those variables as something to set in the admin.

    if ($this->type == 'down' && variable_get('drupalhub_min_points_downvote', 20) < 20) {
      // User under 20 points cannot vote against something.
    }

    if ($this->type == 'up' && variable_get('drupalhub_max_points_downvote', 20) < 5) {
      // User with less than 5 points cannot vote for a question.
    }
  }

  /**
   * Check if the user already did this voted up or down. If voted up already
   * then he cannot vote again. The same goes for voting down. If the user
   * voted up and voting down we need to remove the old vote and create the new
   * one.
   */
  private function checkIfTypeHasCommitted() {
    $row = db_select('votingapi_vote', 'v')
      ->fields('v')
      ->condition('entity_type', $this->request['entity_type'])
      ->condition('entity_id', $this->request['entity_id'])
      ->condition('uid' , $this->account->uid)
      ->execute()
      ->fetchAssoc();

    $args['@type'] = $this->type;

    if ($row['value'] == $this->request['value']) {
      throw new \RestfulBadRequestException(format_string('You cannot vote @type again for this entry', $args));
    }
    else {
      db_delete('votingapi_vote')
      ->condition('vote_id', $row['vote_id'])
      ->execute();
    }
  }

  /**
   * {@inheritdoc}
   */
  public function mapDbRowToPublicFields($row) {
    $parent = parent::mapDbRowToPublicFields($row);

    $parent['new_value'] = \DrupalHubEntityBase::processEntityVotes($parent['entity_id'], $parent['entity_type']);

    return $parent;
  }

}
