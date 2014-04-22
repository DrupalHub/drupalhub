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

  // Exported og permission: 'node:drupalhub_group:add user'
  $permissions['node:drupalhub_group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:drupalhub_group:administer group'
  $permissions['node:drupalhub_group:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:drupalhub_group:approve and deny subscription'
  $permissions['node:drupalhub_group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:drupalhub_group:create blog content'
  $permissions['node:drupalhub_group:create blog content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:create group_banner content'
  $permissions['node:drupalhub_group:create group_banner content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:create news content'
  $permissions['node:drupalhub_group:create news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:create project content'
  $permissions['node:drupalhub_group:create project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:create question content'
  $permissions['node:drupalhub_group:create question content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:create youtube content'
  $permissions['node:drupalhub_group:create youtube content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete any blog content'
  $permissions['node:drupalhub_group:delete any blog content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete any group_banner content'
  $permissions['node:drupalhub_group:delete any group_banner content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete any news content'
  $permissions['node:drupalhub_group:delete any news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete any project content'
  $permissions['node:drupalhub_group:delete any project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete any question content'
  $permissions['node:drupalhub_group:delete any question content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete any youtube content'
  $permissions['node:drupalhub_group:delete any youtube content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete own blog content'
  $permissions['node:drupalhub_group:delete own blog content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete own group_banner content'
  $permissions['node:drupalhub_group:delete own group_banner content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete own news content'
  $permissions['node:drupalhub_group:delete own news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete own project content'
  $permissions['node:drupalhub_group:delete own project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete own question content'
  $permissions['node:drupalhub_group:delete own question content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:delete own youtube content'
  $permissions['node:drupalhub_group:delete own youtube content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:manage members'
  $permissions['node:drupalhub_group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:drupalhub_group:manage permissions'
  $permissions['node:drupalhub_group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:drupalhub_group:manage roles'
  $permissions['node:drupalhub_group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:drupalhub_group:subscribe'
  $permissions['node:drupalhub_group:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:drupalhub_group:subscribe without approval'
  $permissions['node:drupalhub_group:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:unsubscribe'
  $permissions['node:drupalhub_group:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:drupalhub_group:update any blog content'
  $permissions['node:drupalhub_group:update any blog content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:update any group_banner content'
  $permissions['node:drupalhub_group:update any group_banner content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:update any news content'
  $permissions['node:drupalhub_group:update any news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:update any project content'
  $permissions['node:drupalhub_group:update any project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:update any question content'
  $permissions['node:drupalhub_group:update any question content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:update any youtube content'
  $permissions['node:drupalhub_group:update any youtube content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:update group'
  $permissions['node:drupalhub_group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:drupalhub_group:update own blog content'
  $permissions['node:drupalhub_group:update own blog content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:update own group_banner content'
  $permissions['node:drupalhub_group:update own group_banner content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:update own news content'
  $permissions['node:drupalhub_group:update own news content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:update own project content'
  $permissions['node:drupalhub_group:update own project content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:update own question content'
  $permissions['node:drupalhub_group:update own question content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:drupalhub_group:update own youtube content'
  $permissions['node:drupalhub_group:update own youtube content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
