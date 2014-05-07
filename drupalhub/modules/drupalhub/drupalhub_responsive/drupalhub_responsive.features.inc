<?php
/**
 * @file
 * drupalhub_responsive.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drupalhub_responsive_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function drupalhub_responsive_image_default_styles() {
  $styles = array();

  // Exported image style: large_breakpoints_theme_bootstrap_drupalhub_mobile_1x.
  $styles['large_breakpoints_theme_bootstrap_drupalhub_mobile_1x'] = array(
    'name' => 'large_breakpoints_theme_bootstrap_drupalhub_mobile_1x',
    'label' => 'large_breakpoints_theme_bootstrap_drupalhub_mobile_1x',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: large_breakpoints_theme_bootstrap_drupalhub_narrow_1x.
  $styles['large_breakpoints_theme_bootstrap_drupalhub_narrow_1x'] = array(
    'name' => 'large_breakpoints_theme_bootstrap_drupalhub_narrow_1x',
    'label' => 'large_breakpoints_theme_bootstrap_drupalhub_narrow_1x',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 200,
          'height' => 200,
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: large_breakpoints_theme_bootstrap_drupalhub_tv_1x.
  $styles['large_breakpoints_theme_bootstrap_drupalhub_tv_1x'] = array(
    'name' => 'large_breakpoints_theme_bootstrap_drupalhub_tv_1x',
    'label' => 'large_breakpoints_theme_bootstrap_drupalhub_tv_1x',
    'effects' => array(
      4 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => 480,
          'upscale' => 0,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: large_breakpoints_theme_bootstrap_drupalhub_wide_1x.
  $styles['large_breakpoints_theme_bootstrap_drupalhub_wide_1x'] = array(
    'name' => 'large_breakpoints_theme_bootstrap_drupalhub_wide_1x',
    'label' => 'large_breakpoints_theme_bootstrap_drupalhub_wide_1x',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'retina_images_image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'retina_images_image_scale_form',
        'summary theme' => 'retina_images_image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => 480,
          'upscale' => 0,
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}
