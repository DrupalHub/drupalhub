<?php

$plugin = array(
  'title' => t('Service provider search'),
  'description' => t('Provide list of service providers'),
  'category' => t('DrupalHub pages'),
);

function drupalhub_pages_service_provider_search_content_type_render($subtype, $conf, $args, $context) {
  if (!drupalhub_group_get_service_providers()) {
    return;
  }

  drupal_add_js(drupal_get_path('module', 'drupalhub_pages') . '/plugins/content_types/service_provider_search/assets/search_provider.js');
  drupal_add_js(
    array('baseURL' => url('', array('absolute' => TRUE))),
    array('type' => 'setting')
  );

  $form = drupal_get_form('service_provider_search');
  $block = new stdClass();
  $block->content = render($form);

  return $block;
}