<?php

$plugin = array(
  'label' => t('Wiki'),
  'description' => t('Restuling wiki nodes'),
  'resource' => 'wiki',
  'class' => 'DrupalHubWiki',
  'name' => 'wiki__1_0',
  'entity_type' => 'node',
  'bundle' => 'wiki',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
