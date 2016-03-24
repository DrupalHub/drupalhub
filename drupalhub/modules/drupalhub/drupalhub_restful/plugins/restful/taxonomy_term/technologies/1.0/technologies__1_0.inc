<?php

$plugin = array(
  'label' => t('Technologies'),
  'description' => t('Restfuling technologies terms'),
  'resource' => 'technologies',
  'class' => 'DrupalHubTechnologies',
  'name' => 'technologies__1_0',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'technlogies',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
