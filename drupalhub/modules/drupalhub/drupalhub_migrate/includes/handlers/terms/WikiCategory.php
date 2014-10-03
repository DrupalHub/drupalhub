<?php

/**
 * Migrate terms
 */
class WikiCategory extends DrupalHubMigrate {
  public $entityType = 'taxonomy_term';
  public $bundle = 'wiki_category';
}
