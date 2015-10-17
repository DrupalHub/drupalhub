<?php

class DrupalHubComments extends \DrupalHubEntityBase {

  /**
   * {@inheritdoc}
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['point'] = array(
      'property' => 'cid',
      'process_callbacks' => array(
        array($this, 'countLiked'),
      ),
    );

    $public_fields['nid'] = array(
      'property' => 'node',
    );

    $public_fields['text'] = array(
      'property' => 'comment_body',
      'process_callbacks' => array(
        array($this, 'body'),
        array($this, 'processAuthor'),
      ),
    );

    return $public_fields;
  }

  /**
   * The full body value.
   *
   * @param $body
   *   The body field.
   * @return mixed
   *   The safe value.
   */
  protected function body($body) {
    return $body['value'];
  }

  protected function queryForListFilter(\EntityFieldQuery $query) {
    parent::queryForListFilter($query);

    if (!empty($this->request['nid'])) {
      $query->propertyCondition('nid', $this->request['nid']);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function checkEntityAccess($op, $entity_type, $entity) {
    $account = $this->getAccount();

    // When determining access to a comment, 'comment_access' does not take any
    // access restrictions to the comment's associated node into account. If a
    // comment has an associated node, the user must be able to view it in order
    // to access the comment.
    if (isset($entity->nid)) {
      if (!entity_access('view', 'node', node_load($entity->nid), $account)) {
        return FALSE;
      }
    }

    if (user_access('administer comments', $account)) {
      return TRUE;
    }

    // Unpublished comments can never be accessed by non-admins.
    if (isset($entity->status) && $entity->status == COMMENT_NOT_PUBLISHED) {
      return FALSE;
    }

    switch ($this->getMethod()) {
      case \RestfulBase::POST:
        return user_access('post comments', $account);

      case \RestfulBase::GET:
        return user_access('access comments', $account);

      case \RestfulBase::DELETE:
      case \RestfulBase::PATCH:
      case \RestfulBase::PUT:
        return $entity->uid == $account->uid ? user_access('edit own comments', $account) : user_access('administer comments', $account);

      default:
        return FALSE;
    }
  }

  public function checkPropertyAccess($op, $public_field_name, EntityMetadataWrapper $property_wrapper, EntityMetadataWrapper $wrapper) {
    return $this->checkEntityAccess($this->getMethod(), 'comment', $wrapper->value());
  }

}
