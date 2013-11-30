<?php

/**
 * @file
 * Preprocess functions for page elements.
 */

/**
 * Implements hook_preprocess_page().
 */
function omega_music_blog_preprocess_page(&$vars) {
  // Set site name.
  $vars['site_name'] = '<span>µ</span>sic';
  // Create top bar expand button.
  if (user_is_logged_in()) {
    $vars['top_bar_expand'] = '<i class="fa fa-arrow-circle-down"></i>';
  }
}
