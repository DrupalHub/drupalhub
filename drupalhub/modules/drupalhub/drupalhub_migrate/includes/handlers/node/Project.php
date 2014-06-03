<?php

class Project extends DrupalHubMigrate {
  public $entityType = 'node';
  public $bundle = 'project';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('image', 'Image'),
    array('body', 'Body'),
    array(OG_AUDIENCE_FIELD,'Group'),
    array('dotm', 'Drupal of the month'),
  );

  public $dependencies = array('Group');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping(OG_AUDIENCE_FIELD, OG_AUDIENCE_FIELD)
      ->sourceMigration('Group');
    $this->addFieldMapping('field_project_banner_cropimage', 'image');
    $this->addFieldMapping('field_project_banner_cropimage:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_project_banner_cropimage:source_dir')
      ->defaultValue(drupal_get_path('module', 'drupalhub_migrate') . '/includes/images/nodes');
    $this->addFieldMapping('field_project_banner_cropimage:destination_dir', 'destination');
  }

  /**
   * Set the group admin as the publisher of the project.
   */
  public function complete($entity, $row) {
    $wrapper = entity_metadata_wrapper('node', $entity);
    $wrapper->author->set($wrapper->{OG_AUDIENCE_FIELD}->get(0)->getIdentifier());
    if ($row->dotm) {
      variable_set('drupal_of_the_month', $entity->nid);
    }
  }
}