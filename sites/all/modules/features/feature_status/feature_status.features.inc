<?php
/**
 * @file
 * feature_status.features.inc
 */

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
