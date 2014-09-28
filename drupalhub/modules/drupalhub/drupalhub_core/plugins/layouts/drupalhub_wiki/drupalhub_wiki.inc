<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('DrupalHub wiki'),
  'category' => t('DrupalHub'),
  'icon' => 'drupalhub_wiki.png',
  'theme' => 'drupalhub-wiki',
  'admin css' => '../panels-bootstrap-layouts-admin.css',
  'regions' => array(
    'main_top' => t('Main top'),
    'category_1' => t('Category 1'),
    'category_2' => t('Category 2'),
    'category_3' => t('Category 3'),
    'second' => t('Second'),
  ),
);
