<?php
/**
 * @file
 * drupalhub_users.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function drupalhub_users_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_about'
  $field_bases['field_about'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_about',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_entity_view_count'
  $field_bases['field_entity_view_count'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_entity_view_count',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'entity_view_count',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'entity_view_count',
  );

  return $field_bases;
}
