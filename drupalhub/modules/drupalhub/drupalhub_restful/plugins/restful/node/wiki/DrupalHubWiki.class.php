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

}
