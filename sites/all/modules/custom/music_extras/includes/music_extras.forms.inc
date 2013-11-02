<?php

/**
 * @file
 * Forms for the music_extras module.
 */

/**
 * Music extras configuration form.
 */
function music_extras_config_form() {
  $form = array();

  return system_settings_form($form);
}
