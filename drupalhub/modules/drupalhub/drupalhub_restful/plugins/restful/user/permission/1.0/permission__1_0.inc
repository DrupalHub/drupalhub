<?php

$plugin = array(
  'label' => t('Permission'),
  'description' => t('Check if the user as the privilege to invoke something'),
  'resource' => 'permission',
  'class' => 'DrupalHubPermission',
  'entity_type' => 'user',
  'bundle' => 'user',
  // Try to authenticate users with all available authentication types.
  'authentication_types' => TRUE,
  'render_cache' => array(
    'render' => FALSE,
  ),
);