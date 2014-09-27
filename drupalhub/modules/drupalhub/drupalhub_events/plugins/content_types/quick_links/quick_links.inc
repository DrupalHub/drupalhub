<?php

$plugin = array(
  'title' => t('Events links'),
  'description' => t('Links for the drupalhub calendar'),
  'category' => t('DrupalHub events'),
  'hook theme' => 'drupalhub_events_quick_links_theme',
);

function drupalhub_events_quick_links_content_type_render($subtype, $conf, $args, $context) {
  $datepicker = libraries_get_path('datepicker');
  $path = '/plugins/content_types/quick_links';
  drupal_add_js(drupal_get_path('module', 'drupalhub_events') . $path . '/new_events.js');
  drupal_add_js($datepicker . '/js/bootstrap-datepicker.js');
  drupal_add_css($datepicker . '/css/datepicker.css');

  $block = new stdClass();
  $block->content = '';

  $block->content .=
    '<div class="new-event hidden-xs">' .
      '<a href="#" data-toggle="modal" data-target="#NewEvent">' .
        t('Ask event') .
      '</a>' .
    '</div>';
  $block->content .= theme('new_event');
  return $block;
}

/**
 * Delegate hook_theme().
 */
function drupalhub_events_quick_links_theme(&$theme, $plugin) {
  $theme['new_event'] = array(
    'path' => $plugin['path'],
    'template' => 'new-event',
  );
}
