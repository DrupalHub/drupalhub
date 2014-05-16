<?php

/**
 * Migrate terms
 */
class DrupalHubCategoryTerms extends DrupalHubMigrate {
  public $entityType = 'taxonomy_term';
  public $bundle = 'tags';
}