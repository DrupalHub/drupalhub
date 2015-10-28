<?php

$plugin = array(
  'label' => t('Like'),
  'description' => t('Like a specific entity.'),
  'resource' => 'like_comment',
  'class' => 'DrupalHubFlagLike',
  'name' => 'flag_link__1_0',
  'entity_type' => 'flagging',
  'bundle' => 'like_comments',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
