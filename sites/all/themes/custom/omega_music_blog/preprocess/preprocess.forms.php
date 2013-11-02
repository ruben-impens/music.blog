<?php

/**
 * @file
 * Preprocess functions for form elements.
 */

/**
 * Implements hook_preprocess_textarea().
 */
function omega_music_blog_preprocess_textarea(&$variables) {
  $element = $variables['element'];
  // We don't want resizable textareas.
  $variables['element']['#resizable'] = FALSE;

  // Add a placeholder to the status node field.
  if (isset($element['#bundle']) && $element['#bundle'] == 'status' && $element['#field_name'] == 'body') {
    $variables['element']['#attributes']['placeholder'] = music_extras_body_placeholder();
  }
}
