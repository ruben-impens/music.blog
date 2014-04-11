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

  $form['google'] = array(
    '#title' => t('Google'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['google']['google_oauth_client_id'] = array(
    '#title' => t('Google OAuth client ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('google_oauth_client_id', ''),
  );

  $form['google']['google_app_api_key'] = array(
    '#title' => t('Google app API key'),
    '#type' => 'textfield',
    '#default_value' => variable_get('google_app_api_key', ''),
  );

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
