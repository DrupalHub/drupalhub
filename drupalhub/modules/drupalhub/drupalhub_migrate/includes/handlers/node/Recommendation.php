<?php

class Recommendation extends DrupalHubMigrate {
  public $entityType = 'node';
  public $bundle = 'recommendation';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('links', 'Links'),
    array('images', 'Images'),
    array(OG_AUDIENCE_FIELD,'Group')
  );

  public $dependencies = array('Group');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('links', 'links');
    $this->addFieldMapping(OG_AUDIENCE_FIELD, OG_AUDIENCE_FIELD)
      ->sourceMigration('Group');
    $this->addFieldMapping('field_recommendation_images', 'images');
    $this->addFieldMapping('field_recommendation_images:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_recommendation_images:source_dir')
      ->defaultValue(drupal_get_path('module', 'drupalhub_migrate') . '/includes/images');
    $this->addFieldMapping('field_recommendation_images:destination_dir', 'destination');
  }

  /**
   * Set the group admin as the publisher of the project and deal with link
   * field.
   */
  public function prepare($entity, $row) {
    $wrapper = entity_metadata_wrapper('node', $entity);
    list($title, $href) = explode("|", $row->links);
    $wrapper->field_recommendation_links->set(array('url' => $href, 'title' => $title));
    $wrapper->author->set($wrapper->{OG_AUDIENCE_FIELD}->get(0)->getIdentifier());
  }
}