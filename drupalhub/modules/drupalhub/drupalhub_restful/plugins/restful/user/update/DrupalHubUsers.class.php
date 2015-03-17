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

    $public_fields['image'] = array(
      'property' => 'uid',
      'process_callbacks' => array(
        array($this, 'processImage'),
      ),
    );

    $public_fields['company'] = array(
      'property' => 'field_company',
      'sub_property' => 'name',
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

    return $public_fields;
  }

  protected function processImage($uid) {
    $author = user_load($uid);
    return drupalhub_users_user_picture($author, 'thumbnail');
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
      $feed[] = array(
        'user' => $message->uid,
      );
    }

    return $feed;
  }

}
