<?php

$plugin = array(
  'label' => t('Question'),
  'description' => t('Restuling question bundle.'),
  'resource' => 'question',
  'class' => 'DrupalHubQuestion',
  'name' => 'question__1_0',
  'entity_type' => 'node',
  'bundle' => 'question',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
