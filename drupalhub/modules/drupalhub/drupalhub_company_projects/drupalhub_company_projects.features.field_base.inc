<?php
/**
 * @file
 * drupalhub_company_projects.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function drupalhub_company_projects_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_live_address'.
  $field_bases['field_live_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_live_address',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  return $field_bases;
}
