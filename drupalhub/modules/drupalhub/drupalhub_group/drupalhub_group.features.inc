<?php
/**
 * @file
 * drupalhub_group.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drupalhub_group_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels" && $api == "pipelines") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function drupalhub_group_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function drupalhub_group_node_info() {
  $items = array(
    'group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('A content type to hold all group kinds of the site: Drupal service providers, companies, work groups etc.
Provides A group page to hold logo, contact info etc.
Later will provide group score based on sum of part of members individual score, and group activity.'),
      'has_title' => '1',
      'title_label' => t('Group name'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('News. Group content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A project is a group content that allows description, status, image gallery, related links, people involved and their positions in the specific projects.'),
      'has_title' => '1',
      'title_label' => t('Project name'),
      'help' => '',
    ),
  );
  return $items;
}
