<?php
/**
 * @file
 * drupalhub_blog.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function drupalhub_blog_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_blog_rating'
  $field_bases['field_blog_rating'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_blog_rating',
    'foreign keys' => array(
      'votingapi_vote' => array(
        'columns' => array(
          'voteid' => 'voteid',
        ),
        'table' => 'votingapi_vote',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'voteid',
      ),
    ),
    'locked' => 0,
    'module' => 'vud',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'vud',
  );

  // Exported field_base: 'field_images'
  $field_bases['field_images'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_images',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
