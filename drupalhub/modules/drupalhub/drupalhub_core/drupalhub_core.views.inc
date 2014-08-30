<?php
/**
 * @file
 * integration with the views module.
 */

/**
 * Implements hook_views_data().
 */
function drupalhub_core_views_data() {
  $data['node']['time_name_tags'] = array(
    'title' => t('Time name tags'),
    'help' => t('Provide a unified strip of the publishing date, the author name and the tags.'),
    'field' => array(
      'handler' => 'drupalhub_core_time_name_tags',
    ),
  );
  return $data;
}
