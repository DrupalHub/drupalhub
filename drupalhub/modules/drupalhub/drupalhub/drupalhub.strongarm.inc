<?php
/**
 * @file
 * drupalhub.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function drupalhub_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = 'question/[node:title]';
  $export['pathauto_node_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_pattern';
  $strongarm->value = 'tagged/[term:name]';
  $export['pathauto_taxonomy_term_pattern'] = $strongarm;

  return $export;
}
