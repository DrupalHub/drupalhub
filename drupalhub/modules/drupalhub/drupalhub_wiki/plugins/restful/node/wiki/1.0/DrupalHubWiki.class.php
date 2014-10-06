<?php

class DrupalHubWiki extends RestfulEntityBaseNode {

  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['category'] = array(
      'property' => 'field_category',
      'sub_property' => 'name',
    );

    return $public_fields;
  }
}