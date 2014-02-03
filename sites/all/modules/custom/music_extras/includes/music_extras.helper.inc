<?php

/**
 * @file
 * Helper functions for the music_extras module.
 */

/**
 * Render any media found in an input string.
 *
 * @param string $input
 *   The input string in which to search for media.
 */
function music_extras_render_media(&$input) {
  // Check if any link in the input string is media.
  $dom = new DOMDocument();
  $dom->loadHTML($input);
  $links = $dom->getElementsByTagName('a');
  foreach ($links as $link) {
    $href = $link->getAttribute('href');
    if (_is_youtube($href)) {
      // Render youtube player.
      $options = array(
        'width' => '100%',
        'height' => '400',
      );
      $input = theme('youtube_player', array('uri' => $href, 'options' => $options));
    }
    elseif (_is_soundcloud($href)) {
      // Render soundcloud player.
      $options = array();
      $input = theme('soundcloud_player', array('uri' => $href, 'options' => $options));
    }
    elseif (_is_vimeo($href)) {
      // Render vimeo player.
      $input = 'VIMEO';
    }
  }
}

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

/**
 * Fetch SoundCloud embed code from URI.
 *
 * @param string $uri
 *   The URI to the original page.
 *
 * @return string|bool
 *   SoundCloud embed code or FALSE if no code is available.
 */
function music_extras_fetch_soundcloud_embed_url($uri) {
  $curl_url = 'http://soundcloud.com/oembed?format=json&url=' . urlencode($uri) . '&iframe=true';
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, $curl_url);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  $result = curl_exec($ch);
  curl_close($ch);
  if (!empty($result)) {
    $result = json_decode($result);
    return $result->html;
  }
  return FALSE;
}

/**
 * Checks if a URL is YouTube.
 *
 * @param string $url
 *   The URL to check.
 *
 * @return bool
 */
function _is_youtube($url) {
  return (preg_match('/youtu\.be/i', $url) || preg_match('/youtube\.com\/watch/i', $url));
}

/**
 * Checks if a URL is SoundCloud.
 *
 * @param string $url
 *   The URL to check.
 *
 * @return bool
 */
function _is_soundcloud($url) {
  return (preg_match('/soundcloud\.com/i', $url) || preg_match('/snd\.sc/i', $url));
}

/**
 * Checks if a URL is Vimeo.
 *
 * @param string $url
 *   The URL to check.
 *
 * @return bool
 */
function _is_vimeo($url) {
  return (preg_match('/vimeo\.com/i', $url));
}
