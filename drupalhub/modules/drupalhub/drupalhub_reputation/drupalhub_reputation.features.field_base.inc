<?php
/**
 * @file
 * drupalhub_reputation.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function drupalhub_reputation_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_reputation'
  $field_bases['field_reputation'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_reputation',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
