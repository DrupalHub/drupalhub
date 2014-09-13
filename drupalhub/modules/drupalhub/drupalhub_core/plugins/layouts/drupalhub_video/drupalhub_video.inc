<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('DrupalHub video page layout'),
  'category' => t('DrupalHub'),
  'icon' => 'drupalhub_video.png',
  'theme' => 'drupalhub_video',
  'admin css' => '../panels-bootstrap-layouts-admin.css',
  'regions' => array(
    'video' => t('Video'),
    'others' => t('Other videos'),
    'bottom' => t('Bottom'),
  ),
);
