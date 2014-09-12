<?php

$plugin = array(
  'title' => t('Upcoming events'),
  'category' => t('DrupalHub events'),
  'hook theme' => 'drupalhub_events_upcoming_events_content_type_theme',
);

function drupalhub_events_upcoming_events_content_type_render($subtype, $conf, $args, $context) {
  $query = new EntityFieldQuery();
  $results = $query
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'events')
    ->fieldCondition('field_date', 'value', time(), '>=')
    ->execute();

  if (empty($results['node'])) {
    $events = t('There are no upcoming events');
  }
  else {
    $items = array();
    $nodes = node_load_multiple(array_keys($results['node']));

    foreach ($nodes as $node) {
      $wrapper = entity_metadata_wrapper('node', $node);
      $uri = entity_uri('node', $node);
      $items[] =
        '<div class="event-title">' . l($wrapper->label(), $uri['path']) . '<div>' .
        '<div class="date">' . format_date($wrapper->field_date->value->value()) . '</div>' .
        '<div class="body">' . $wrapper->body->value->value() . '</div>';
    }

    $events = theme('item_list', array('items' => $items));
  }

  $block = new stdClass();
  $block->content = theme('drupalhub_events_upcoming_events', array('events' => $events));
  return $block;
}

/**
 * Delegating ctools_theme().
 */
function drupalhub_events_upcoming_events_content_type_theme(&$theme, $plugin) {
  $theme['drupalhub_events_upcoming_events'] = array(
    'path' => $plugin['path'],
    'template' => 'upcoming-events',
  );
}