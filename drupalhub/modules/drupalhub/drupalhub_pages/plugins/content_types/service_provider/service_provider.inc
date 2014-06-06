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

  $chunks = array_chunk($nodes, 20);
  $providers = '';

  $i = $j = 0;
  foreach ($chunks as $nodes) {

    $active = $i == 0 ? 'active' : '';
    $providers .= '<div class="item ' . $active . '">';
      $providers .= '<div class="row">';

      foreach ($nodes as $node) {
        $providers .= '<div class="col-xs-2">' . $node->title . '</div>';
        $j++;

        // Each row need to have 10 providers. When the $j is smaller then 20
        // that's mean we didn't got to end of the provider in the current
        // carousel item.
        if ($j % 10 == 0 && $j < 20) {
          $providers .= '</div><div class="row">';
        }
      }

      $providers .= '</div>';
    $providers .= '</div>';

    $i++;
  }

  $block = new stdClass();

  $block->content = theme('service_provider', array('providers' => $providers));

  return $block;
}

/**
 * Delegating hook_theme().
 */
function drupalhub_pages_service_provider_content_type_theme(&$theme, $plugin) {
  $theme['service_provider'] = array(
    'path' => $plugin['path'],
    'template' => 'service-provider',
    'variables' => array(
      'providers' => '',
    ),
  );
}
