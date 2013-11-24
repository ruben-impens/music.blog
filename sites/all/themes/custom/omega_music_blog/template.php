<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

require_once 'preprocess/preprocess.forms.php';
require_once 'preprocess/preprocess.page.php';

/**
 * Returns HTML for a feed icon.
 */
function omega_music_blog_feed_icon($variables) {
  $text = t('Subscribe to !feed-title', array('!feed-title' => $variables['title']));
  return l('', $variables['url'], array('attributes' => array('class' => array('fa', 'fa-rss'), 'title' => $text)));
}

/**
 * Returns HTML for a form element label and required marker.
 */
function omega_music_blog_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  $attributes['class'] = '';
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }

  // Add fontawesome icons.
  $icon = '';
  if ($element['#type'] == 'checkbox') {
    $class = $element['#checked'] ? 'fa-check-square-o' : 'fa-square-o';
    $icon = '<i class="fa ' . $class . '"></i>';
  }
  elseif ($element['#type'] == 'radio') {
    $radio_checked = $element['#return_value'] == $element['#default_value'];
    $class = $radio_checked ? ' fa-dot-circle-o' : ' fa-circle-o';
    $icon = '<i class="fa ' . $class . '"></i>';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $icon . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</label>\n";
}

/**
 * Returns HTML for a textfield form element.
 */
function omega_music_blog_textfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
  _form_set_class($element, array('form-text'));

  $extra = '';
  if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
    $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }
  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  // Change markup for autocomplete textfields.
  if (isset($element['#autocomplete_path']) && $element['#autocomplete_path']) {
    $icon = '<i class="fa fa-refresh"></i>';
    $output = '<div class="autocomplete-wrapper">' . $output . $icon . '</div>';
  }

  return $output . $extra;
}
