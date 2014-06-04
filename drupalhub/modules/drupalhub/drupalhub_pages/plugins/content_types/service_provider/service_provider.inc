<?php

$plugin = array(
  'title' => t('Service provider'),
  'description' => t('Provide list of service providers'),
  'category' => t('DrupalHub pages'),
);

function drupalhub_pages_service_provider_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = 's';
  return $block;
}
