<?php

$plugin = array(
  'label' => t('Update'),
  'description' => t('Restuling user.'),
  'resource' => 'users',
  'class' => 'DrupalHubUsers',
  'name' => 'update__1_0',
  'entity_type' => 'user',
  'bundle' => 'user',
  'hook_menu' => TRUE,
  'authentication_types' => true,
  'authentication_optional' => TRUE,
);
