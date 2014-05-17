<?php

class Youtube extends DrupalHubMigrate {
  public $entityType = 'node';
  public $bundle = 'youtube';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('youtube', 'Address'),
    array(OG_AUDIENCE_FIELD,'Group')
  );

  public $dependencies = array('Group');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('address', 'field_address');
    $this->addFieldMapping(OG_AUDIENCE_FIELD, OG_AUDIENCE_FIELD)
      ->sourceMigration('Group');
  }

  /**
   * Set the group admin as the publisher of the youtube.
   */
  public function prepare($entity, $row) {
    $wrapper = entity_metadata_wrapper('node', $entity);
    $wrapper->author->set($wrapper->{OG_AUDIENCE_FIELD}->get(0)->getIdentifier());
  }
}