<?php

class Group extends DrupalHubMigrate {
  public $entityType = 'node';
  public $bundle = 'group';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Mission'),
    array('logo', 'Logo'),
    array('uid', 'User'),
  );

  public $dependencies = array('User');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('field_group_logo', 'logo');
    $this->addFieldMapping('field_group_logo:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_group_logo:source_dir')
      ->defaultValue(drupal_get_path('module', 'drupalhub_migrate') . '/includes/images');
    $this->addFieldMapping('field_group_logo:destination_dir', 'destination');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('User');
  }
}