<?php
/**
 * @file
 * drupalhub_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drupalhub_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "atjs" && $api == "default_atjs_listener") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
