<?php

$plugin = array(
  'label' => t('Playlist'),
  'description' => t('Expose all the play lists'),
  'resource' => 'playlist',
  'class' => 'DrupalHubPlayList',
  'name' => 'playlist__1_0',
  'entity_type' => 'node',
  'bundle' => 'playlist',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
