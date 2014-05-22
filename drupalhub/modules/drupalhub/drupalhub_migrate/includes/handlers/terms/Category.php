<?php

/**
 * Migrate terms
 */
class Category extends DrupalHubMigrate {
  public $entityType = 'taxonomy_term';
  public $bundle = 'tags';
}