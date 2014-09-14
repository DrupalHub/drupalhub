<?php

$plugin = array(
  'label' => t('Playlists'),
  'description' => t('Expose all the playlists'),
  'resource' => 'playlists',
  'class' => 'DrupalHubVideosPlaylists',
  'entity_type' => 'node',
  'bundle' => 'playlists',
  // Try to authenticate users with all available authentication types.
  'authentication_types' => TRUE,
  // Allow anonymous users to access the resource, given they have the right
  // permissions.
  'authentication_optional' => TRUE,
  'hook_menu' => TRUE,
  'menu_item' => 'playlists',
);
