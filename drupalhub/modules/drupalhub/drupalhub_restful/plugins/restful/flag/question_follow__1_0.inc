<?php

$plugin = array(
  'label' => t('Follow question'),
  'description' => t('Following a question.'),
  'resource' => 'question_follow',
  'class' => 'DrupalHubFlagLike',
  'name' => 'question_follow__1_0',
  'entity_type' => 'flagging',
  'bundle' => 'like',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
