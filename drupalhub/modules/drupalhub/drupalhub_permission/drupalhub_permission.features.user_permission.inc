<?php
/**
 * @file
 * drupalhub_permission.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drupalhub_permission_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create events content'.
  $permissions['create events content'] = array(
    'name' => 'create events content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create youtube content'.
  $permissions['create youtube content'] = array(
    'name' => 'create youtube content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any events content'.
  $permissions['delete any events content'] = array(
    'name' => 'delete any events content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any youtube content'.
  $permissions['delete any youtube content'] = array(
    'name' => 'delete any youtube content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own events content'.
  $permissions['delete own events content'] = array(
    'name' => 'delete own events content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own youtube content'.
  $permissions['delete own youtube content'] = array(
    'name' => 'delete own youtube content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any events content'.
  $permissions['edit any events content'] = array(
    'name' => 'edit any events content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any youtube content'.
  $permissions['edit any youtube content'] = array(
    'name' => 'edit any youtube content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own events content'.
  $permissions['edit own events content'] = array(
    'name' => 'edit own events content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own youtube content'.
  $permissions['edit own youtube content'] = array(
    'name' => 'edit own youtube content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
