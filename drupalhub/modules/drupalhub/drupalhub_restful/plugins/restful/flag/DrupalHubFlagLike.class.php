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
   * Set the bundle of the flag as the flag name.
   */
  public function entityPreSave(\EntityMetadataWrapper $wrapper) {
    $wrapper->name->set($this->getBundle());
    $request = $this->getRequest();
    $uid = empty($request['uid']) ? $this->getAccount()->uid : $request['uid'];
    $wrapper->uid->set($uid);
  }

  /**
   * Validating for a single flag.
   */
  public function entityValidate(\EntityMetadataWrapper $wrapper) {
    $request = $this->getRequest();
    $uid = empty($request['uid']) ? $this->getAccount()->uid : $request['uid'];
    $query = new EntityFieldQuery();
    $results = $query
      ->entityCondition('entity_type', 'flagging')
      ->propertyCondition('entity_type', $request['entity_type'])
      ->propertyCondition('entity_id', $request['entity_id'])
      ->propertyCondition('uid', $uid)
      ->count()
      ->execute();

    if ($results > 0) {
      throw new \RestfulBadRequestException('The user already flagged this entity.');
    }

    parent::entityValidate($wrapper);
  }

  public function deleteEntity($entity_id) {
    db_delete('flagging')
      ->condition('flagging_id', $entity_id)
      ->execute();

    // Set the HTTP headers.
    $this->setHttpHeaders('Status', 204);
  }

}
