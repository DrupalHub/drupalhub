<?php

$plugin = array(
  'title' => t('Service provider'),
  'description' => t('Provide list of service providers'),
  'category' => t('DrupalHub pages'),
  'hook theme' => 'drupalhub_pages_service_provider_content_type_theme',
);

function drupalhub_pages_service_provider_content_type_render($subtype, $conf, $args, $context) {
  if (!$nodes = drupalhub_group_get_service_providers()) {
    return;
  }

  $path = drupal_get_path('module', 'drupalhub_pages') . '/plugins/content_types/service_provider/assets';
  drupal_add_js($path . '/slideshow.js');

  $results = drupalhub_pages_services_providers($nodes);

  $block = new stdClass();
  $block->content = theme('service_providers', array('providers' => $results['providers'], 'navigation' => $results['navigation']));

  return $block;
}

/**
 * Delegating hook_theme().
 */
function drupalhub_pages_service_provider_content_type_theme(&$theme, $plugin) {
  $theme['service_providers'] = array(
    'path' => $plugin['path'] . '/templates',
    'template' => 'service-providers',
    'variables' => array(
      'providers' => '',
    ),
  );

  $theme['service_provider'] = array(
    'path' => $plugin['path'] . '/templates',
    'template' => 'service-provider',
    'variables' => array(
      'title' => '',
      'image' => '',
    ),
  );
}
