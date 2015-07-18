<?php

class DrupalHubUsers extends \RestfulEntityBaseUser {

  /**
   * Overrides RestfulEntityBaseUser::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['about'] = array(
      'property' => 'field_about',
      'sub_property' => 'value',
    );

    $public_fields['password'] = array(
      'property' => 'pass',
      'callback' => array($this, 'hideField')
    );

    $public_fields['image'] = array(
      'property' => 'uid',
      'process_callbacks' => array(
        array($this, 'processImage'),
      ),
    );

    $public_fields['image_fid'] = array(
      'property' => 'picture',
    );

    $public_fields['reputation'] = array(
      'property' => 'field_reputation',
    );

    $public_fields['joined'] = array(
      'property' => 'created',
      'process_callbacks' => array(
        array($this, 'processJoined'),
      ),
    );

    $public_fields['number'] = array(
      'property' => 'uid',
      'process_callbacks' => array(
        array($this, 'processNumber'),
      )
    );

    $public_fields['activity'] = array(
      'property' => 'uid',
      'process_callbacks' => array(
        array($this, 'activityFeed'),
      ),
    );

    $public_fields['first_name'] = array(
      'property'=> 'field_first_name',
    );

    $public_fields['last_name'] = array(
      'property'=> 'field_last_name',
    );

    $public_fields['settings'] = array(
      'property' => 'field_settings',
      'process_callbacks' => array(
        array($this, 'settingsProcess'),
      ),
    );

    return $public_fields;
  }

  /**
   * Hide the field value.
   *
   * @return null
   */
  protected function hideField() {
    return NULL;
  }

  protected function processImage($uid) {
    $author = user_load($uid);
    return drupalhub_users_user_picture($author);
  }

  protected function processJoined($created) {
    return date('d/m/Y', $created);
  }

  protected function processNumber($uid) {
    $query = new EntityFieldQuery();
    $questions = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('uid', $uid)
      ->propertyCondition('type', 'question')
      ->count()
      ->execute();

    $query = new EntityFieldQuery();
    $comments = $query->entityCondition('entity_type', 'comment')
      ->propertyCondition('uid', $uid)
      ->count()
      ->execute();


    return array(
      'questions' => $questions,
      'comments' => $comments,
    );
  }

  protected function activityFeed($uid) {
    $query = new EntityFieldQuery();
    $results = $query
      ->entityCondition('entity_type', 'message')
      ->propertyCondition('uid', $uid)
      ->execute();

    if (empty($results['message'])) {
      return array();
    }

    $messages = message_load_multiple(array_keys($results['message']));

    $feed = array();
    foreach ($messages as $message) {
      $wrapper = entity_metadata_wrapper('message', $message);
      $name = $wrapper->user->field_first_name->value() . ' ' . $wrapper->user->field_last_name->value();

      if ($name != ' ') {
        $display_name = $name . ' - @<a href="user.html/#' . $wrapper->user->getIdentifier() . '">' . $wrapper->user->label() . '</a>';
      }
      else {
        $display_name = '@<a href="user.html/#' . $wrapper->user->getIdentifier() . '">' . $wrapper->user->label() . '</a>';
      }

      $feed[] = array(
        'user' => $display_name,
        'image' => $this->processImage($wrapper->user->getIdentifier()),
        'text' => $message->getText(),
        'date' => format_date($message->timestamp, 'custom', 'd/m/Y H:i'),
      );
    }

    return $feed;
  }

  public function checkEntityAccess($op, $entity_type, $entity) {
    if ($this->getMethod() == \RestfulBase::POST) {
      return TRUE;
    }

    if ($this->getMethod() == \RestfulBase::PATCH) {
      return $this->getAccount()->uid == $entity->uid || user_access('administer users', $this->getAccount());
    }

    return parent::checkEntityAccess($op, $entity_type, $entity);
  }

  public function checkPropertyAccess($op, $public_field_name, EntityMetadataWrapper $property_wrapper, EntityMetadataWrapper $wrapper) {
    if ($this->getMethod() == \RestfulBase::POST) {
      return TRUE;
    }

    return parent::checkPropertyAccess($op, $public_field_name, $property_wrapper, $wrapper);
  }

  public function entityPreSave(\EntityMetadataWrapper $wrapper) {
    $wrapper->status->set(1);

    parent::entityPreSave($wrapper);
  }

  /**
   * {@inheritdoc}
   */
  public function propertyValuesPreprocess($property_name, $value, $public_field_name) {

    if ($public_field_name == 'about') {
      return array('value' => $value);
    }

    if ($public_field_name == 'settings') {
      return array('value' => $value);
    }

    if ($public_field_name == 'image_fid') {
      return file_load($value);
    }

    return parent::propertyValuesPreprocess($property_name, $value, $public_field_name);
  }

  public function settingsProcess($value) {
    return $value['value'];
  }
}
