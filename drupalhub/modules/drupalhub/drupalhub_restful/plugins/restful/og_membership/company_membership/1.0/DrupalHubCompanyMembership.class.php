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
      'process_callbacks' => array(
        array($this, 'userEndpoint'),
      ),
    );

    return $fields;
  }

  /**
   * Display a single group member after processed by the me endpoint handler.
   *
   * @param $entity
   *   The user object.
   *
   * @return array
   *   The user information.
   */
  protected function userEndpoint($entity) {
    /** @var DrupalHubMe $handler */
    $handler = restful_get_restful_handler('me');
    return $handler->viewEntity($entity->uid);
  }

}
