<?php

$plugin = array(
  'label' => t('Like'),
  'description' => t('Like a specific entity.'),
  'resource' => 'like',
  'class' => 'DrupalHubFlagLike',
  'name' => 'flag__1_0',
  'entity_type' => 'flagging',
  'bundle' => 'like',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
