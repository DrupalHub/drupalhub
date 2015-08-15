<?php

class DrupalHubFlagLike extends \RestfulEntityBase {

  /**
   * {@inheritdoc}
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['entity_type'] = array(
      'property' => 'entity_type',
    );

    $public_fields['entity_id'] = array(
      'property' => 'entity_id',
    );

    $public_fields['uid'] = array(
      'property' => 'uid',
    );

    return $public_fields;
  }

  /**
   * Sort the query for list.
   *
   * @param \EntityFieldQuery $query
   *   The query object.
   *
   * @throws \RestfulBadRequestException
   *
   * @see \RestfulEntityBase::getQueryForList
   */
  protected function queryForListSort(\EntityFieldQuery $query) {
    $query->propertyOrderBy('fid', 'ASC');
  }

  /**
   * {@inheritdoc}
   */
  protected function queryForListFilter(\EntityFieldQuery $query) {

    $request = $this->getRequest();

    if (isset($request['check_flagged'])) {

      // Check if the user already flagged the current entity.
      if (empty($request['entity']) || empty($request['id'])) {
        throw new RestfulBadRequestException('You did not provide entity type or ID.');
      }

      // We need to check if the user already flagged this an entity.
      $query
        ->propertyCondition('uid', $this->getUserId())
        ->propertyCondition('entity_type', $request['entity'])
        ->propertyCondition('entity_id', $request['id']);
    }

    parent::queryForListFilter($query);
  }

  /**
   * Set the bundle of the flag as the flag name.
   */
  public function entityPreSave(\EntityMetadataWrapper $wrapper) {
    $wrapper->name->set($this->getBundle());
    $wrapper->uid->set($this->getUserId());
  }

  /**
   * Validating for a single flag.
   */
  public function entityValidate(\EntityMetadataWrapper $wrapper) {
    $request = $this->getRequest();

    $query = new EntityFieldQuery();
    $results = $query
      ->entityCondition('entity_type', 'flagging')
      ->propertyCondition('entity_type', $request['entity_type'])
      ->propertyCondition('entity_id', $request['id'])
      ->propertyCondition('uid', $this->getUserId())
      ->count()
      ->execute();

    if ($results > 0) {
      throw new \RestfulBadRequestException('The user already flagged this entity.');
    }

    parent::entityValidate($wrapper);
  }

  /**
   * {@inheritdoc}
   */
  public function deleteEntity($entity_id) {

    $flag = flag_get_flag($this->getBundle());
    $flag->flag('unflag', $entity_id, $this->getAccount());

    // Set the HTTP headers.
    $this->setHttpHeaders('Status', 204);
  }

  /**
   * Get the user ID from the request or the authentication manager.
   *
   * @return integer
   *   The user ID.
   */
  private function getUserId() {
    $request = $this->getRequest();
    return empty($request['uid']) ? $this->getAccount()->uid : $request['uid'];
  }

}
