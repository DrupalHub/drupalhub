<?php

class DrupalHubWiki extends DrupalHubRestfulNode {

  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['tags'] = array(
      'property' => 'field_category',
      'process_callbacks' => array(
        array($this, 'processTags'),
      ),
    );

    return $public_fields;
  }

  /**
   * Return the tags in a specific format.
   */
  protected function processTags($terms) {
    $tags = array();

    foreach ($terms as $term) {
      $tags[] = array(
        'title' => $term->name,
        'url' => 'tags.html#' . $term->tid,
      );
    }
    return $tags;
  }
}
