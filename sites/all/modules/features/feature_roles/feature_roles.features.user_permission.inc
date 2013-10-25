<?php
/**
 * @file
 * feature_roles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_roles_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'homie' => 'homie',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'homie' => 'homie',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create status content'.
  $permissions['create status content'] = array(
    'name' => 'create status content',
    'roles' => array(
      'homie' => 'homie',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own status content'.
  $permissions['delete own status content'] = array(
    'name' => 'delete own status content',
    'roles' => array(
      'homie' => 'homie',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'homie' => 'homie',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own status content'.
  $permissions['edit own status content'] = array(
    'name' => 'edit own status content',
    'roles' => array(
      'homie' => 'homie',
    ),
    'module' => 'node',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'homie' => 'homie',
    ),
    'module' => 'comment',
  );

  return $permissions;
}
