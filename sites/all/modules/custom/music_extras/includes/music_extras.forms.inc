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

  $form['soundcloud'] = array(
    '#title' => t('Soundcloud'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['soundcloud']['soundcloud_client_id'] = array(
    '#title' => t('Soundcloud Client ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('soundcloud_client_id', ''),
  );

  return system_settings_form($form);
}
