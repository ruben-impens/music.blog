<?php

/**
 * @file
 *
 * Theme and preprocess functions for music extras.
 */

/**
 * Preprocess function for theme('youtube_player').
 */
function music_extras_preprocess_youtube_player(&$variables) {
  $variables['width'] = $variables['options']['width'];
  $variables['height'] = $variables['options']['height'];
  // Build the iframe URL with options query string.
  preg_match('/youtu(?:.*\/v\/|.*v\=|\.be\/)([A-Za-z0-9_\-]{11})/', $variables['uri'], $matches);
  $variables['url'] = url('//www.youtube.com/embed/' . $matches[1], array('external' => TRUE));
}

/**
 * Preprocess function for theme('soundcloud_player').
 */
function music_extras_preprocess_soundcloud_player(&$variables) {
  // Try to get the soundcloud embed URL.
  if ($html = music_extras_fetch_soundcloud_embed_url($variables['uri'])) {
    $variables['html'] = $html;
  }
  else {
    $variables['html'] = t('No SoundCloud embed code could be found.');
  }
}
