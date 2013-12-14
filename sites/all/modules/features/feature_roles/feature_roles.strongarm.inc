<?php
/**
 * @file
 * feature_roles.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_roles_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'registration_role_roles';
  $strongarm->value = '3';
  $export['registration_role_roles'] = $strongarm;

  return $export;
}
