<?php

$plugin = array(
  'label' => t('Comment'),
  'description' => t('Restuling comments.'),
  'resource' => 'comments',
  'class' => 'DrupalHubComments',
  'name' => 'comments__1_0',
  'entity_type' => 'comment',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
