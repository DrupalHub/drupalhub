<?php
/**
 * @file
 * drupalhub_responsive.default_breakpoints.inc
 */

/**
 * Implements hook_default_breakpoints().
 */
function drupalhub_responsive_default_breakpoints() {
  $export = array();

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.bootstrap_drupalhub.mobile';
  $breakpoint->name = 'mobile';
  $breakpoint->breakpoint = '(min-width: 0px)';
  $breakpoint->source = 'bootstrap_drupalhub';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.bootstrap_drupalhub.mobile'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.bootstrap_drupalhub.narrow';
  $breakpoint->name = 'narrow';
  $breakpoint->breakpoint = '(min-width: 560px)';
  $breakpoint->source = 'bootstrap_drupalhub';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 1;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.bootstrap_drupalhub.narrow'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.bootstrap_drupalhub.tv';
  $breakpoint->name = 'tv';
  $breakpoint->breakpoint = 'only screen and (min-width: 3456px)';
  $breakpoint->source = 'bootstrap_drupalhub';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 3;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.bootstrap_drupalhub.tv'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.bootstrap_drupalhub.wide';
  $breakpoint->name = 'wide';
  $breakpoint->breakpoint = '(min-width: 851px)';
  $breakpoint->source = 'bootstrap_drupalhub';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 2;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.bootstrap_drupalhub.wide'] = $breakpoint;

  return $export;
}
