<?php

/**
 * @file
 * Views alters for the music_extras module.
 */

/**
 * Implements hook_preprocess_views_view_field().
 */
function music_extras_preprocess_views_view_field(&$vars) {
  $view = $vars['view'];
  $field = $vars['field'];
  if ($view->name == 'status_updates' && $view->current_display == 'block') {
    switch ($field->options['id']) {
      case 'field_body_1':
        music_extras_render_media($vars['output']);
        break;
    }
  }
}
