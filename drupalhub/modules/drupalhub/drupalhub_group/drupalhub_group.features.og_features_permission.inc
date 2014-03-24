<?php
/**
 * @file
 * drupalhub_group.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function drupalhub_group_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:create bootstrap_carousel content'
  $permissions['node:group:create bootstrap_carousel content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:create project content'
  $permissions['node:group:create project content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete any bootstrap_carousel content'
  $permissions['node:group:delete any bootstrap_carousel content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete any news content'
  $permissions['node:group:delete any news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any project content'
  $permissions['node:group:delete any project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete own bootstrap_carousel content'
  $permissions['node:group:delete own bootstrap_carousel content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete own news content'
  $permissions['node:group:delete own news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete own project content'
  $permissions['node:group:delete own project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any bootstrap_carousel content'
  $permissions['node:group:update any bootstrap_carousel content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update any news content'
  $permissions['node:group:update any news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any project content'
  $permissions['node:group:update any project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update own bootstrap_carousel content'
  $permissions['node:group:update own bootstrap_carousel content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update own news content'
  $permissions['node:group:update own news content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update own project content'
  $permissions['node:group:update own project content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  return $permissions;
}
