<?php
/**
 * @file
 * feature_status.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_status_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_status_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_status_node_info() {
  $items = array(
    'status' => array(
      'name' => t('Status'),
      'base' => 'node_content',
      'description' => t('The multifunctional status content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
