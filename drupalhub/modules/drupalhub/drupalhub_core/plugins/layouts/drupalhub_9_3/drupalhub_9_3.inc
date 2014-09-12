<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('DrupalHub 9-3'),
  'category' => t('DrupalHub'),
  'icon' => 'drupalhub_9_3.png',
  'theme' => 'drupalhub-9-3',
  'admin css' => '../panels-bootstrap-layouts-admin.css',
  'regions' => array(
    'first' => t('First'),
    'second' => t('Second'),
  ),
);
