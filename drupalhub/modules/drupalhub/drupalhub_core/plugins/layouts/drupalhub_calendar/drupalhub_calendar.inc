<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('DrupalHub calendar'),
  'category' => t('DrupalHub'),
  'icon' => 'drupalhub_calendar.png',
  'theme' => 'drupalhub-calendar',
  'admin css' => '../panels-bootstrap-layouts-admin.css',
  'regions' => array(
    'calendar' => t('Calendar'),
    'bottom-first' => t('Bottom first'),
    'bottom-second' => t('Bottom second'),
    'bottom-third' => t('Bottom third'),
  ),
);
