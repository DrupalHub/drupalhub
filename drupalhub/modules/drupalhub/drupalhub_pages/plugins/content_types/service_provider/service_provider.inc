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

  $block = new stdClass();

  $block->content = theme('service_provider');

  return $block;
}

/**
 * Delegating hook_theme().
 */
function drupalhub_pages_service_provider_content_type_theme(&$theme, $plugin) {
  $theme['service_provider'] = array(
    'path' => $plugin['path'],
    'template' => 'service-provider',
  );
}
