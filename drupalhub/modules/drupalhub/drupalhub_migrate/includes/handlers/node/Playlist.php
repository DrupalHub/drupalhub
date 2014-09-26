<?php

/**
 * @file
 *
 * Migrating youtube playlists.
 */

class Playlist extends DrupalHubMigrate {
  public $entityType = 'node';
  public $bundle = 'playlist';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Description'),
    array('field_access_level', 'Access'),
    array('field_videos', 'Videos'),
  );

  public $dependencies = array('Youtube');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('field_access_level', 'field_access_level');
    $this->addFieldMapping('field_videos', 'field_videos')
      ->sourceMigration('Youtube')
      ->separator('|');
  }
}
