<?php

/**
 * Migrating users.
 */
class User extends Migration {

  public $csvColumns = array(
    array('id', 'ID'),
    array('name', 'Username'),
    array('pass', 'Password'),
    array('mail', 'Email'),
    array('picture', 'Picture'),
  );

  public function __construct() {
    parent::__construct();
    $this->description = t('Import users from a CSV file.');

    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('pass', 'pass');
    $this->addFieldMapping('mail', 'mail');
    $this->addFieldMapping('picture', 'picture');
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
   * Add picture for the user.
   */
  function complete($entity, $row) {
    // Copy the file.
    $uri = file_unmanaged_copy(DRUPAL_ROOT . '/' . drupal_get_path('module', 'drupalhub_migrate') . '/includes/images/users/' . $row->picture, 'public://pictures');

    // Create the file manage entry.
    $file = new stdClass;
    $file->uid = $entity->uid;
    $file->filename = $row->picture;
    $file->uri = $uri;
    $file->status = 1;
    $file->filemime = 'image/jpg';
    file_save($file);

    // Update the user picture.
    $file->status = 0;
    $edit = array ('picture' => $file);
    user_save($entity, $edit);
  }
}