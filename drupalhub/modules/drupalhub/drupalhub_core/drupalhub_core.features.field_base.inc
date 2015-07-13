<?php
/**
 * @file
 * drupalhub_core.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function drupalhub_core_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_settings'
  $field_bases['field_settings'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_settings',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_config',
    'settings' => array(
      'show_textarea' => 0,
    ),
    'translatable' => 0,
    'type' => 'serialized',
  );

  return $field_bases;
}
