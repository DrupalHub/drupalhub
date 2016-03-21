<?php
/**
 * @file
 * drupalhub_company_projects.features.inc
 */

/**
 * Implements hook_node_info().
 */
function drupalhub_company_projects_node_info() {
  $items = array(
    'company_projects' => array(
      'name' => t('Company projects'),
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
