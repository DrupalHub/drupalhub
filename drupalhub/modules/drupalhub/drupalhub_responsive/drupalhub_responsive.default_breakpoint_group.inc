<?php
/**
 * @file
 * drupalhub_responsive.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function drupalhub_responsive_default_breakpoint_group() {
  $export = array();

  // Breakpoints.
  $breakpoints = array();
  $breakpoints[] = 'breakpoints.theme.bootstrap_drupalhub.mobile';
  $breakpoints[] = 'breakpoints.theme.bootstrap_drupalhub.narrow';
  $breakpoints[] = 'breakpoints.theme.bootstrap_drupalhub.wide';
  $breakpoints[] = 'breakpoints.theme.bootstrap_drupalhub.tv';

  // Breakpoint group.
  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'bootstrap_drupalhub';
  $breakpoint_group->name = 'DrupalHub Bootstrap Sub-theme';
  $breakpoint_group->breakpoints = $breakpoints;
  $breakpoint_group->type = 'theme';
  $breakpoint_group->overridden = 0;
  $export['bootstrap_drupalhub'] = $breakpoint_group;

  return $export;
}
