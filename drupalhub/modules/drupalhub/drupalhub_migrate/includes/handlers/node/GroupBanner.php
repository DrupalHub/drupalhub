<?php

class GroupBanner extends DrupalHubMigrate {
  public $entityType = 'node';
  public $bundle = 'group_banner';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('image', 'Image'),
    array('body', 'Body'),
    array('promote', 'Promote'),
  );

  public $dependencies = array('Group');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('promote', 'promote');
    $this->addFieldMapping('field_group_banner_cropimage', 'image');
    $this->addFieldMapping('field_group_banner_cropimage:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_group_banner_cropimage:source_dir')
      ->defaultValue(drupal_get_path('module', 'drupalhub_migrate') . '/includes/images/nodes');
    $this->addFieldMapping('field_group_banner_cropimage:destination_dir', 'destination');
  }
}