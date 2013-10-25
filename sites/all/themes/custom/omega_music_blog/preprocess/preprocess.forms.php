<?php

/**
 * @file
 * Preprocess functions for form elements.
 */

/**
 * Implements hook_preprocess_textarea().
 */
function omega_music_blog_preprocess_textarea(&$variables) {
  // We don't want resizable textareas.
  $variables['element']['#resizable'] = FALSE;
}
