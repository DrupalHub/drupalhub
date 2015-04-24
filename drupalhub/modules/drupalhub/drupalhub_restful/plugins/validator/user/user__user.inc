<?php

$plugin = array(
  'label' => t('Users'),
  'description' => t('Validate youtube videos upon creation.'),
  'entity_type' => 'user',
  'bundle' => 'user',
  'class' => 'DrupalHubUsersValidate',
);
