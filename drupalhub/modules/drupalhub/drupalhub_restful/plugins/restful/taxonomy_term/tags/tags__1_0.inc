<?php

$plugin = array(
  'label' => t('Tags'),
  'description' => t('Restfuling tags terms'),
  'resource' => 'tags',
  'class' => 'DrupalHubTags',
  'name' => 'tags__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'tags',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
