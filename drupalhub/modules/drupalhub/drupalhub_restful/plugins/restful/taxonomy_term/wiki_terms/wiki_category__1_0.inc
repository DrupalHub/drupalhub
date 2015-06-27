<?php

$plugin = array(
  'label' => t('Wiki tags'),
  'description' => t('Restfuling tags terms for the wiki'),
  'resource' => 'wiki_category',
  'class' => 'DrupalHubTagsWiki',
  'name' => 'wiki_category__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'wiki_category',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
