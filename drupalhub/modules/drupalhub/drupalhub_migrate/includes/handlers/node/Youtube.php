<?php

class Youtube extends DrupalHubMigrate {
  public $entityType = 'node';
  public $bundle = 'youtube';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('youtube', 'Address'),
    array('field_show_in_videos', 'Display in library'),
    array(OG_AUDIENCE_FIELD, 'Group')
  );

  public $dependencies = array('Group');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_address', 'youtube');
    $this->addFieldMapping('field_show_in_videos', 'field_show_in_videos');
    $this->addFieldMapping(OG_AUDIENCE_FIELD, OG_AUDIENCE_FIELD)
      ->sourceMigration('Group');
  }

  /**
   * Set the group admin as the publisher of the youtube.
   */
  public function prepare($entity, $row) {
    $wrapper = entity_metadata_wrapper('node', $entity);
    if ($wrapper->{OG_AUDIENCE_FIELD}->get(0)->value()) {
      $wrapper->author->set($wrapper->{OG_AUDIENCE_FIELD}->get(0)->getIdentifier());
    }
  }
}