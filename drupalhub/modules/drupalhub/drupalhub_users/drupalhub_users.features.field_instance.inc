<?php
/**
 * @file
 * drupalhub_users.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function drupalhub_users_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_about'
  $field_instances['user-user-field_about'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_about',
    'label' => 'About',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'user-user-field_entity_view_count'
  $field_instances['user-user-field_entity_view_count'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entity_view_count',
        'settings' => array(),
        'type' => 'default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_entity_view_count',
    'label' => 'Entity view count',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'entity_view_count',
      'settings' => array(),
      'type' => 'default',
      'weight' => 13,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Entity view count');

  return $field_instances;
}
