<?php
/**
 * @file
 * drupalhub_company.features.inc
 */

/**
 * Implements hook_node_info().
 */
function drupalhub_company_node_info() {
  $items = array(
    'company' => array(
      'name' => t('Company'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
