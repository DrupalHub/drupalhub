<?php

$plugin = array(
  'label' => t('Entity access'),
  'description' => t('Check operation for a given entity.'),
  'resource' => 'entity_access',
  'class' => 'DrupalHubEntityAccess',
  'authentication_types' => TRUE,
);