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


  $chunks = array_chunk($nodes, 12);
  $providers = '';

  $i = $j = 0;
  foreach ($chunks as $nodes) {

    $active = $i == 0 ? 'active' : '';
    $providers .= '<div class="item ' . $active . '">';
      $providers .= '<div class="row">';

      foreach ($nodes as $node) {
        $params = array(
          'title' => views_trim_text(array('max_length' => 20, 'html' => TRUE), $node->title),
          'image' => 'a',
        );
        $providers .= '<div class="col-xs-2">' . theme('service_provider', $params) . '</div>';
        $j++;

        // Each row need to have 10 providers. When the $j is smaller then 20
        // that's mean we didn't got to end of the provider in the current
        // carousel item.
        if ($j % 6 == 0) {
          $providers .= '</div><div class="row">';
        }
      }

      $providers .= '</div>';
    $providers .= '</div>';

    $i++;
  }

  $block = new stdClass();

  $block->content = theme('service_providers', array('providers' => $providers));

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
