<?php
/**
 * @file
 * drupalhub_videos.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function drupalhub_videos_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_address'
  $field_bases['field_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_address',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'video_embed_field',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'video_embed_field',
  );

  // Exported field_base: 'field_youtube_rating'
  $field_bases['field_youtube_rating'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_youtube_rating',
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

  return $field_bases;
}
