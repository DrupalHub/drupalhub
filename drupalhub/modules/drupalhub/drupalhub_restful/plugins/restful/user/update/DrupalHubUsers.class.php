<?php

class DrupalHubUsers extends RestfulEntityBaseUser {

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

    return $public_fields;
  }

  public function processImage($uid) {
    $author = user_load($uid);
    return drupalhub_users_user_picture($author, 'thumbnail');
  }

  public function processJoined($created) {
    return date('d/m/Y', $created);
  }

  public function processNumber($uid) {
    return array(
      'questions' => 22,
      'comments' => 22,
    );
  }

}
