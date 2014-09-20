<?php

$plugin = array(
  'label' => t('Playlists'),
  'description' => t('Expose all the playlists'),
  'resource' => 'youtube',
  'class' => 'DrupalHubVideos',
  'name' => 'youtube__1_0',
  'entity_type' => 'node',
  'bundle' => 'youtube',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
