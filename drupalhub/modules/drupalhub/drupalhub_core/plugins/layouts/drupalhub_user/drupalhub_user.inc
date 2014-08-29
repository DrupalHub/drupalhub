<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('DrupalHub user page layout'),
  'category' => t('DrupalHub'),
  'icon' => 'drupalhub_user.png',
  'theme' => 'drupalhub_user',
  'admin css' => '../panels-bootstrap-layouts-admin.css',
  'regions' => array(
    'top-first' => t('Top first'),
    'top-second' => t('Top second'),
    'first' => t('First'),
    'second' => t('Second'),
  ),
);
