<?php
/**
 * @file
 * drupalhub_responsive.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function drupalhub_responsive_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'bootstrap_drupalhub';
  $picture_mapping->breakpoint_group = 'bootstrap_drupalhub';
  $picture_mapping->mapping = array(
    'breakpoints.theme.bootstrap_drupalhub.mobile' => array(
      '1x' => 'large_breakpoints_theme_bootstrap_drupalhub_mobile_1x',
    ),
    'breakpoints.theme.bootstrap_drupalhub.narrow' => array(
      '1x' => 'large_breakpoints_theme_bootstrap_drupalhub_narrow_1x',
    ),
    'breakpoints.theme.bootstrap_drupalhub.wide' => array(
      '1x' => 'large_breakpoints_theme_bootstrap_drupalhub_wide_1x',
    ),
    'breakpoints.theme.bootstrap_drupalhub.tv' => array(
      '1x' => 'large_breakpoints_theme_bootstrap_drupalhub_wide_1x',
    ),
  );
  $export['bootstrap_drupalhub'] = $picture_mapping;

  return $export;
}
