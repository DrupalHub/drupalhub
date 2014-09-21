<?php

/**
 * @file
 *
 * Plugin to provide a node context. A node context is a node wrapped in a
 * context object that can be utilized by anything that accepts contexts.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Playlist"),
  'description' => t('Playlist from URL'),
  'context' => 'ctools_context_create_playlist',
  'defaults' => array('nid' => ''),
  'keyword' => 'playlist',
  'context name' => 'playlist',
  'convert list' => 'ctools_context_playlist_convert_list',
  'convert' => 'ctools_context_playlist_convert',
  'superceded by' => 'entity:node',
);

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function ctools_context_create_playlist($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('node');
  $context->plugin = 'node';

  if ($empty) {
    return $context;
  }

  if (empty($_GET['playlist'])) {
    return;
  }

  $data = node_load($_GET['playlist']);

  if (!empty($data)) {
    $context->data     = $data;
    $context->title    = $data->title;
    $context->argument = $data->nid;

    $context->restrictions['type'] = array($data->type);
    return $context;
  }
}

/**
 * Provide a list of ways that this context can be converted to a string.
 */
function ctools_context_playlist_convert_list() {
  $tokens = token_info();
  foreach ($tokens['tokens']['node'] as $id => $info) {
    if (!isset($list[$id])) {
      $list[$id] = $info['name'];
    }
  }

  return $list;
}

/**
 * Convert a context into a string.
 */
function ctools_context_playlist_convert($context, $type) {
  $tokens = token_info();
  if (isset($tokens['tokens']['node'][$type])) {
    $values = token_generate('node', array($type => $type), array('node' => $context->data));
    if (isset($values[$type])) {
      return $values[$type];
    }
  }
}
