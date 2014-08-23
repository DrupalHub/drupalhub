<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('DrupalHub blog layout'),
  'category' => t('DrupalHub'),
  'icon' => 'drupalhub_blog.png',
  'theme' => 'drupalhub-blog',
  'admin css' => '../panels-bootstrap-layouts-admin.css',
  'regions' => array(
    'top_first' => t('Top first'),
    'top_second' => t('Top second'),
    'bottom' => t('Bottom'),
  ),
);
