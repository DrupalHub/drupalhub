<?php
/**
 * @file
 * drupalhub_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drupalhub_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function drupalhub_pages_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function drupalhub_pages_image_default_styles() {
  $styles = array();

  // Exported image style: top_users.
  $styles['top_users'] = array(
    'name' => 'top_users',
    'label' => 'Top users',
    'effects' => array(
      10 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'retina_images_image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 40,
          'height' => 40,
          'retinafy' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
