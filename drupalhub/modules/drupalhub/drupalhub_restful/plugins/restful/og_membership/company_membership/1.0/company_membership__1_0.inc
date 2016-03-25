<?php

$plugin = array(
  'label' => t('Company membership'),
  'description' => t('Show all the memberships of users for companies.'),
  'resource' => 'companies_membership',
  'class' => 'DrupalHubCompanyMembership',
  'name' => 'company_membership__1_0',
  'entity_type' => 'og_membership',
  'bundle' => 'company_membership',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
