<?php

$plugin = array(
  'label' => t('Company'),
  'description' => t('Restfuling companies.'),
  'resource' => 'company',
  'class' => 'DrupalHubCompany',
  'name' => 'company__1_0',
  'entity_type' => 'node',
  'bundle' => 'companies',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
