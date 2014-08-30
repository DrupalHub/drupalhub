<?php

/**
 * Views handler that will provide a unified strip of author name, published
 * date and tags.
 */
class drupalhub_core_time_name_tags extends views_handler_field_entity {

  public function render($values) {
    $wrapper = entity_metadata_wrapper('node', $this->get_value($values, 'nid'));
    $uri = entity_uri('user', $wrapper->author->value());

    $name = l($wrapper->author->label(), $uri['path']);

    $tags = array();
    if ($wrapper->field_tags) {
      foreach ($wrapper->field_tags as $tag) {
        $uri = entity_uri('taxonomy_term', $tag->value());
        $tags[] = l($tag->label(), $uri['path']);
      }
    }

    return theme('time_name_tags', array(
      'time' => format_date($wrapper->created->value()),
      'name' => $name,
      'tags' => implode(', ', $tags),
    ));
  }
}