<?php

/**
 * Migrating ideas.
 */
class DrupalHubBlog extends DrupalHubMigrate {
  public $entityType = 'node';
  public $bundle = 'blog';

  public $csvColumns = array(
    array('id', 'Unique ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('uid', 'User'),
  );

  public $dependencies = array('DrupalHubUsers', 'DrupalHubCategoryTerms');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('DrupalHubUsers');
  }
}