<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('DrupalHub home page layout'),
  'category' => t('DrupalHub'),
  'icon' => 'drupalhub_homepage.png',
  'theme' => 'drupalhub_homepage',
  'admin css' => '../panels-bootstrap-layouts-admin.css',
  'regions' => array(
    'first' => t('First'),
    'first_left' => t('First left side'),
    'fist_right' => t('First right side'),
    'second-top' => t('Second top'),
    'second-middle' => t('Second middle'),
    'second-last' => t('Second last'),
    'second_left' => t('Second left side'),
    'second_right' => t('Second right side'),
  ),
);
