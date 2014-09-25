<?php

class DrupalHubUsers extends RestfulEntityBaseUser {

  public function getPublicFields() {
    $fields = parent::getPublicFields();

    $public_fields['about'] = array(
      'property' => 'field_about',
      'sub_property' => 'value',
    );

    return $fields;
  }
}