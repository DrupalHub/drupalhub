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

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create events content'.
  $permissions['create events content'] = array(
    'name' => 'create events content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create playlist content'.
  $permissions['create playlist content'] = array(
    'name' => 'create playlist content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create question content'.
  $permissions['create question content'] = array(
    'name' => 'create question content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create youtube content'.
  $permissions['create youtube content'] = array(
    'name' => 'create youtube content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any events content'.
  $permissions['delete any events content'] = array(
    'name' => 'delete any events content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any playlist content'.
  $permissions['delete any playlist content'] = array(
    'name' => 'delete any playlist content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any question content'.
  $permissions['delete any question content'] = array(
    'name' => 'delete any question content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
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
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own playlist content'.
  $permissions['delete own playlist content'] = array(
    'name' => 'delete own playlist content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own question content'.
  $permissions['delete own question content'] = array(
    'name' => 'delete own question content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own youtube content'.
  $permissions['delete own youtube content'] = array(
    'name' => 'delete own youtube content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any events content'.
  $permissions['edit any events content'] = array(
    'name' => 'edit any events content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any playlist content'.
  $permissions['edit any playlist content'] = array(
    'name' => 'edit any playlist content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any question content'.
  $permissions['edit any question content'] = array(
    'name' => 'edit any question content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
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
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own playlist content'.
  $permissions['edit own playlist content'] = array(
    'name' => 'edit own playlist content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own question content'.
  $permissions['edit own question content'] = array(
    'name' => 'edit own question content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own youtube content'.
  $permissions['edit own youtube content'] = array(
    'name' => 'edit own youtube content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'flag like'.
  $permissions['flag like'] = array(
    'name' => 'flag like',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag like_comments'.
  $permissions['flag like_comments'] = array(
    'name' => 'flag like_comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag subscribe_node'.
  $permissions['flag subscribe_node'] = array(
    'name' => 'flag subscribe_node',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag like'.
  $permissions['unflag like'] = array(
    'name' => 'unflag like',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag like_comments'.
  $permissions['unflag like_comments'] = array(
    'name' => 'unflag like_comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
