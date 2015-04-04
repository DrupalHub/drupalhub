<?php

class DrupalHubEntityBase extends \RestfulEntityBase {

  /**
   * {@inheritdoc}
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['image'] = array(
      'property' => 'author',
      'process_callbacks' => array(
        array($this, 'authorImage'),
      ),
    );

    $public_fields['author'] = array(
      'property' => 'author',
      'process_callbacks' => array(
        array($this, 'processAuthor'),
      ),
    );

    $public_fields['date'] = array(
      'property' => 'created',
      'process_callbacks' => array(
        array($this, 'processDate'),
      ),
    );

    return $public_fields;
  }

  /**
   * {@inheritdoc}
   */
  public function viewEntity($id) {

    if (!empty($this->request['add_view'])) {
      $entity = entity_load_single($this->getEntityType(), $id);
      $params = array(
        'entity_type' => $this->getEntityType(),
        'entity' => $entity,
        'view_mode' => '',
        'entity_owner' => !empty($entity->uid) ? $entity->uid : 0,
      );

      entity_view_count_create($params)->save();
    }


    return parent::viewEntity($id);
  }

  /**
   * {@inheritdoc}
   */
  public function propertyValuesPreprocess($property_name, $value, $public_field_name) {
    if (in_array($property_name, array('body', 'comment_body'))) {
      return array('value' => $this->request['text']);
    }
    return parent::propertyValuesPreprocess($property_name, $value, $public_field_name);
  }

  /**
   * Allow manipulating the entity before it is saved.
   *
   * @param \EntityMetadataWrapper $wrapper
   *   The unsaved wrapped entity.
   */
  public function entityPreSave(\EntityMetadataWrapper $wrapper) {
    parent::entityPreSave($wrapper);
    $wrapper->author->set($this->getAccount());
  }

  /**
   * Processing a date.
   */
  protected function processDate($value) {
    return date('d/m/Y', $value);
  }

  /**
   * Process a user.
   */
  protected function processAuthor($value) {
    return $value->name;
  }

  /**
   * Count how many times entry was viewed.
   */
  protected function countViewed($nid) {
    return entity_view_count_get_entity_count('node', $nid);
  }

  /**
   * Count the number of likes for the current node.
   */
  protected function countLiked($nid) {
    $flag = flag_get_counts($this->getEntityType(), $nid);
    $flag_type = $this->getEntityType() == 'node' ? 'like' : 'like_comments';

    return $flag[$flag_type] ? $flag[$flag_type] : 0;
  }

  /**
   * Return the user image.
   */
  protected function authorImage($author) {
    return drupalhub_users_user_picture($author, 'thumbnail');
  }

  protected function processPoint($cid) {
    // todo: do.
    return 0;
  }

}