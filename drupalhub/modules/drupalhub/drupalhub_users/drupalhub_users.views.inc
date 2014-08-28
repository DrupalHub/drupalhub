<?php
/**
 * @file
 * integration with the views module.
 */

/**
 * Implements hook_views_data().
 */
function drupalhub_users_views_data() {
  $data['users']['user_picture'] = array(
    'title' => t('Drupalhub users profile picture'),
    'help' => t('Generate a profile picture according to DrupalHub logic.'),
    'field' => array(
      'handler' => 'drupalhub_users_profile_picture',
    ),
  );
  return $data;
}
