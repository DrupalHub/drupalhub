<?php

$plugin = array(
  'label' => t('Playlists'),
  'description' => t('Expose all the playlists'),
  'resource' => 'playlist',
  'class' => 'DrupalHubPlayList',
  'name' => 'playlist__1_0',
  'entity_type' => 'node',
  'bundle' => 'playlist',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
