<?php

/**
 * @file
 * DrupalHub migrate file.
 */

abstract class DrupalHubMigrate extends Migration {
  public $entityType;
  public $bundle;

  function __construct() {
    parent::__construct();
    $this->description = t('Import @type - @bundle from CSV file.', array('@type' => $this->entityType, '@bundle' => $this->bundle));

  if ($this->entityType == 'taxonomy_term') {
    $class_name = 'MigrateDestinationTerm';

    $this->csvColumns = array(
      array('id', 'ID'),
      array('name', 'Name'),
      array('description', 'Description'),
    );
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('description', 'description');
  }
  else if ($this->entityType == 'comment') {
    $class_name = 'MigrateDestinationComment';
  }
  else {
    $class_name = 'MigrateDestinationNode';
  }

    // Create a map object for tracking the relationships between source rows
    $key = array(
      'id' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      ),
    );
    $this->map = new MigrateSQLMap($this->machineName, $key, MigrateDestinationNode::getKeySchema($this->entityType));

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'drupalhub_migrate') . '/csv/' . $this->entityType . '/' . $this->bundle . '.csv', $this->csvColumns, array('header_rows' => 1));
    $this->destination = new $class_name($this->bundle, array('text_format' => 'filtered_html'));
  }

  /**
   * Vote for/against comments/users
   * @param $uids
   *  Lists of users IDs.
   * @param $type
   *  Define the voting type: against/for
   * @param $entity_id
   *  The entity ID of the comment/node.
   */
  public function vote($uids, $type, $entity_id) {
    foreach ($uids as $uid) {
      $votes = array(
        'entity_type' => $this->entityType,
        'entity_id' => $entity_id,
        'value' => $type == 'for' ? 1 : -1,
        'value_type' => 'point',
        'tag' => 'vote',
        'uid' => $uid,
      );
      votingapi_add_votes($votes);
    }
  }
}
