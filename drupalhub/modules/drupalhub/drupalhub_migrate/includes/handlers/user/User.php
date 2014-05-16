<?php

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