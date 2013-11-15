<?php

/**
 * @file
 * Preprocess functions for page elements.
 */

/**
 * Implements hook_preprocess_page().
 */
function omega_music_blog_preprocess_page(&$vars) {
  $vars['site_name'] = '<span>µ</span>sic';
}
