<?php

/**
 * @file
 * Helper functions for the music_extras module.
 */

/**
 * Calculate the number of posts a user has.
 *
 * @param object $account
 *   A fully loaded user object.
 *
 * @return int $count
 *   The number of posts the user has submitted.
 */
function music_extras_number_of_posts($account = NULL) {
  // Use the current user when no user object is provided.
  if (!$account) {
    global $user;
    $account = $user;
  }
  $count = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.uid', $account->uid)
    ->execute()
    ->rowCount();
  return $count;
}

/**
 * Get random placeholder text for the status body field.
 */
function music_extras_body_placeholder() {
  $placeholder = db_select('music_extras_placeholders', 'mep')
    ->fields('mep', array('placeholder'))
    ->range(0, 1)
    ->orderRandom()
    ->execute()
    ->fetchField();
  return $placeholder;
}
