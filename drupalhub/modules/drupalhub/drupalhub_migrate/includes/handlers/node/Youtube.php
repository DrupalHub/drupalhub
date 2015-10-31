<?php

class Youtube extends DrupalHubMigrate {
  public $entityType = 'node';
  public $bundle = 'youtube';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('youtube', 'Address'),
    array('field_show_in_videos', 'Display in library'),
    array(OG_AUDIENCE_FIELD, 'Group'),
  );

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_address', 'youtube');
    $this->addFieldMapping('field_show_in_videos', 'field_show_in_videos');
  }
}
