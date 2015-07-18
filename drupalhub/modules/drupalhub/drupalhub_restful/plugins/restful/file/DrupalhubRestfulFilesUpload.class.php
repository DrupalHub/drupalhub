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

}