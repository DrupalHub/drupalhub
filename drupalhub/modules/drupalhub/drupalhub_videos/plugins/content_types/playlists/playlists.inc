<?php

$plugin = array(
  'title' => t('User playlists'),
  'category' => t('DrupalHub youtube'),
  'required context' => new ctools_context_required(t('User'), 'user'),
  'hook theme' => 'drupalhub_videos_playlists_content_type_theme',
);

function drupalhub_videos_playlists_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $settings['plyalist'] = array(
    'basePath' => url('', array('absolute' => TRUE)),
    'csrfToken' => drupal_get_token(\RestfulInterface::TOKEN_VALUE),
  );
  drupal_add_js($settings, 'setting');
  drupal_add_js(drupal_get_path('module', 'drupalhub_videos') . '/plugins/content_types/playlists/playlists_manage.js');

  $query = new EntityFieldQuery();
  $results = $query
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'playlists')
    ->propertyCondition('uid', $context->data->uid)
    ->execute();

  $rows = array();
  if (!empty($results['node'])) {
    $nodes = node_load_multiple(array_keys($results['node']));

    foreach ($nodes as $node) {
      $wrapper = entity_metadata_wrapper('node', $node);

      $rows[] = array($wrapper->label());
    }
  }
  else {
    $rows[] = array(
      array(
        'data' => t('You did not created any playlist. <a href="#" class="show-playlist-form">Create a new playlist</a>'),
        'colspan' => 3,
      ),
    );
  }
  $params = array(
    'header' => array(t('Title'), t('Number of videos'), t('Options')),
    'rows' => $rows,
  );

  $block->content = theme('table', $params) . theme('playlist_form');

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_videos_playlists_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_videos_playlists_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function drupalhub_videos_playlists_content_type_theme(&$theme, $plugin) {
  $theme['playlist_form'] = array(
    'path' => $plugin['path'],
    'template' => 'playlist-form',
  );
}