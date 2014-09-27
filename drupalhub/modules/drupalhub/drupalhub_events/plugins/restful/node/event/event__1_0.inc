<?php

$plugin = array(
  'label' => t('Event'),
  'description' => t('Restuling event bundle.'),
  'resource' => 'event',
  'class' => 'DrupalHubEvent',
  'name' => 'event__1_0',
  'entity_type' => 'node',
  'bundle' => 'events',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
