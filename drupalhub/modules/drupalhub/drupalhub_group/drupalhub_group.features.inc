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
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
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
 * Implements hook_image_default_styles().
 */
function drupalhub_group_image_default_styles() {
  $styles = array();

  // Exported image style: sidebar_right.
  $styles['sidebar_right'] = array(
    'name' => 'sidebar_right',
    'label' => 'Sidebar right',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: wide_galleryformatter_for_project_pages__700x250_.
  $styles['wide_galleryformatter_for_project_pages__700x250_'] = array(
    'name' => 'wide_galleryformatter_for_project_pages__700x250_',
    'label' => 'wide galleryformatter for project pages (700x250)',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 700,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function drupalhub_group_node_info() {
  $items = array(
    'drupalhub_group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Group name'),
      'help' => '',
    ),
    'group_banner' => array(
      'name' => t('Group banner'),
      'base' => 'node_content',
      'description' => t('A content type for the group\'s page. Image and text. Presented by views_bootstrap module.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('A group content type for group news.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A group content type to display projects.'),
      'has_title' => '1',
      'title_label' => t('Project name'),
      'help' => '',
    ),
    'recommendation' => array(
      'name' => t('Recommendation'),
      'base' => 'node_content',
      'description' => t('recommend a project or a service provider!'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
