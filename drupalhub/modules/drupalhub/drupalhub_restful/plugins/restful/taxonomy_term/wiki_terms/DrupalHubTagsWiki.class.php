<?php

class DrupalHubTagsWiki extends RestfulEntityBaseTaxonomyTerm {

  /**
   * {@inheritdoc}
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['url'] = array(
      'property' => 'tid',
      'process_callbacks' => array(
        array($this, 'processUrl'),
      ),
    );

    return $public_fields;
  }

  /**
   * Render the item.
   */
  public function processUrl($tid) {
    return 'tags.html/#' . $tid;
  }

}