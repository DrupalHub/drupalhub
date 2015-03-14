<?php

class DrupalHubUsers extends RestfulEntityBaseUser {

  /**
   * Overrides \RestfulBase::controllersInfo().
   */
  public static function controllersInfo() {
    return array(
      '' => array(
        // GET returns a list of entities.
        \RestfulInterface::GET => 'getList',
        \RestfulInterface::PATCH => 'entityUpdate',
      ),
    );
  }

  public function __getPublicFields() {
    $fields = parent::getPublicFields();

    $fields['about'] = array(
      'property' => 'field_about',
      'wrapper_method' => 'getIdentifier',
      'process_callback' => array(
        array($this, 'aboutProcess'),
      ),
    );

    return $fields;
  }

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

  /**
   * Update the entity.
   */
  public function entityUpdate() {
    $request = $this->getRequest();
    $id = $request['id'];
    unset($request['id']);
    $this->setRequest($request);
    $this->updateEntity($id);

    drupal_json_output(array('id' => $id) + $request);
  }
}
