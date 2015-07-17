<?php

class DrupalHubRestfulFilesUpload extends \RestfulFilesUpload {

  /**
   * Overrides \RestfulBase::controllersInfo().
   */
  public static function controllersInfo() {
    return array(
      '' => array(
        \RestfulInterface::POST => 'createEntity',
        \RestfulInterface::GET => 'getList',
      ),
      '^.*$' => array(
        \RestfulInterface::GET => 'viewEntities',
      ),
    );
  }

  /**
   * Overrides \RestfulBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $fields = parent::publicFieldsInfo();

    $fields['url'] = array(
      'property' => 'url',
    );

    $fields['uid'] = array(
      'property' => 'owner',
      'wrapper_method' => 'getIdentifier',
    );

    return $fields;
  }

}