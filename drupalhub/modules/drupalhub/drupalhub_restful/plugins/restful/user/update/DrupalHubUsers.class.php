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

    return $public_fields;
  }

}
