<?php

class DrupalHubCompanyMembership extends \RestfulEntityBase {

  /**
   * {@inheritdoc}
   */
  public function publicFieldsInfo() {
    $fields = parent::publicFieldsInfo();

    $fields['role'] = array(
      'property' => 'field_role_title',
    );

    $fields['group'] = array(
      'property' => 'group',
      'sub_property' => 'nid',
    );

    $fields['uid'] = array(
      'property' => 'entity',
      'sub_property' => 'uid',
    );

    return $fields;
  }

}
