<?php
/**
 * @file
 * feature_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_roles_user_default_roles() {
  $roles = array();

  // Exported role: homie.
  $roles['homie'] = array(
    'name' => 'homie',
    'weight' => 2,
  );

  return $roles;
}
