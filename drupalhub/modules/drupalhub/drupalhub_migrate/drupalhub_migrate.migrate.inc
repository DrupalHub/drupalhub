<?php

/**
 * @file
 * Holds the migration classes for DrupalHub migrate module.
 */

/**
 * Migrating ideas.
 */
class DrupalHubIdea extends DrupalHubMigrate {
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

/**
 * Migrating users.
 */
class DrupalHubUsers extends Migration {

  public $csvColumns = array(
    array('id', 'ID'),
    array('name', 'Username'),
    array('pass', 'Password'),
    array('mail', 'Email'),
  );

  public function __construct() {
    parent::__construct();
    $this->description = t('Import users from a CSV file.');

    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('pass', 'pass');
    $this->addFieldMapping('mail', 'mail');
    $this->addFieldMapping('status')
      ->defaultValue(TRUE);

    // Create a map object for tracking the relationships between source rows
    $key = array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $destination_handler = new MigrateDestinationUser();
    $this->map = new MigrateSQLMap($this->machineName, $key, $destination_handler->getKeySchema());

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drupalhub_migrate') . '/csv/user/user.csv', $this->csvColumns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationUser();
  }

  /**
   * Granting a role to the user from the CSV.
   */
  function complete($entity, $row) {
    $edit = array();
    user_save($entity, $edit);
  }
}

/**
 * Migrate terms
 */
class DrupalHubCategoryTerms extends DrupalHubMigrate {
  public $entityType = 'taxonomy_term';
  public $bundle = 'tags';
}

/**
 * Migrate comments.
 */
class DrupalHubIdeaComments extends DrupalHubMigrate {
  public $entityType = 'comment';
  public $bundle = 'question';

  public $csvColumns = array(
    array('id', 'ID'),
    array('node', 'Node'),
    array('body', 'Body'),
    array('uid', 'UID'),
    array('for', 'Voted for'),
    array('against', 'Voted against')
  );

  public $dependencies = array('DrupalHubUsers', 'DrupalHubCategoryTerms');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('nid', 'node')
      ->sourceMigration('DrupalHubIdea');

    // TODO: Fix.
    $this->addFieldMapping('comment_body', 'body');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('DrupalHubUsers');

    // Get the users which voted against the comment and vor the comment.
    $this->addFieldMapping('for', 'for')
      ->sourceMigration(array('DrupalHubUsers'))
      ->separator('|');

    $this->addFieldMapping('against', 'against')
      ->sourceMigration(array('DrupalHubUsers'))
      ->separator('|');
  }

  public function complete($entity, $row) {
    // Vote for/against this comment.
//    $this->vote($entity->for, 'for', $entity->cid);
//    $this->vote($entity->against, 'against', $entity->cid);
  }
}
