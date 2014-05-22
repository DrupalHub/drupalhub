<?php

/**
 * Migrating ideas.
 */
class Question extends DrupalHubMigrate {
  public $entityType = 'node';
  public $bundle = 'question';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('field_tags', 'Tags'),
    array('uid', 'User'),
  );

  public $dependencies = array('User', 'Category');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('field_tags', 'field_tags')
      ->sourceMigration(array('Category'))
      ->separator("|")
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('User');
  }
}