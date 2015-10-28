<?php

$plugin = array(
  'label' => t('Front page'),
  'description' => t('Holds the fronts page assets.'),
  'name' => 'front_page',
  'resource' => 'front_page',
  'class' => 'FrontPageAssets',
  // Try to authenticate users with all available authentication types.
  'authentication_types' => array(),
);
