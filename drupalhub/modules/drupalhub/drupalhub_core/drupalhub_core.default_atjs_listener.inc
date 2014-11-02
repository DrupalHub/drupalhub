<?php
/**
 * @file
 * drupalhub_core.default_atjs_listener.inc
 */

/**
 * Implements hook_default_atjs_listener().
 */
function drupalhub_core_default_atjs_listener() {
  $export = array();

  $listener = new stdClass();
  $listener->disabled = FALSE; /* Edit this to true to make a default listener disabled initially */
  $listener->api_version = 1;
  $listener->name = 'users';
  $listener->title = 'Users';
  $listener->entity_type = 'user';
  $listener->bundles = array();
  $listener->record_usage = FALSE;
  $listener->at = '@';
  $listener->tpl = '<li data-value="${atwho-at}${name}">${name}</li>';
  $listener->insert_tpl = '<span>${atwho-data-value}</span>';
  $listener->search_key = 'property:name';
  $listener->data_to_supply = array(
    'uid' => 'uid',
    'name' => 'name',
    'pass' => 0,
    'mail' => 0,
    'theme' => 0,
    'signature' => 0,
    'signature_format' => 0,
    'created' => 0,
    'access' => 0,
    'login' => 0,
    'status' => 0,
    'timezone' => 0,
    'language' => 0,
    'picture' => 0,
    'init' => 0,
    'data' => 0,
    'og_user_node1' => 0,
    'og_user_node' => 0,
    'field_reputation' => 0,
    'field_views' => 0,
    'field_about' => 0,
    'field_entity_view_count' => 0,
    'field_first_name' => 0,
    'field_last_name' => 0,
  );
  $listener->query_limit = TRUE;
  $listener->max_length = TRUE;
  $export['users'] = $listener;

  return $export;
}
