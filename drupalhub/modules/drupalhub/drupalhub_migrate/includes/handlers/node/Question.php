<?php

/**
 * Migrating ideas.
 */
class DrupalHubQuestion extends DrupalHubMigrate {
  public $entityType = 'node';
  public $bundle = 'question';

  public $csvColumns = array(
    array('id', 'Unique ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('field_tags', 'Tags'),
    array('uid', 'User'),
  );

  public $dependencies = array('DrupalHubUsers', 'DrupalHubCategoryTerms');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('field_tags', 'field_tags')
      ->sourceMigration(array('DrupalHubCategoryTerms'))
      ->separator("|")
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('DrupalHubUsers');
  }
}