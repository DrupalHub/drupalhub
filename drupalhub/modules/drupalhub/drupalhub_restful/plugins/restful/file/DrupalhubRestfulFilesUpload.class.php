<?php

class DrupalhubRestfulFilesUpload extends \RestfulFilesUpload {

  /**
   * Overrides \RestfulBase::controllersInfo().
   */
  public static function controllersInfo() {
    return array(
      '' => array(
        \RestfulInterface::POST => 'createEntity',
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

    return $fields;
  }

}
