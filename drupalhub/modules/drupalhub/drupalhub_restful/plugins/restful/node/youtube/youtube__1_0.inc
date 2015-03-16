<?php

$plugin = array(
  'label' => t('Video'),
  'description' => t('Exposing videos'),
  'resource' => 'video',
  'class' => 'DrupalHubVideos',
  'name' => 'youtube__1_0',
  'entity_type' => 'node',
  'bundle' => 'youtube',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
