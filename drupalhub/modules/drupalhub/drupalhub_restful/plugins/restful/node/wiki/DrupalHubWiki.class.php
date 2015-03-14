<?php

class DrupalHubWiki extends DrupalHubRestfulBase {

  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['category'] = array(
      'property' => 'field_category',
      'sub_property' => 'name',
    );

    return $public_fields;
  }

  /**
   * Overriding the self method.
   */
  public function getEntitySelf(\EntityMetadataWrapper $wrapper) {
    return url('node/' . $wrapper->getIdentifier());
  }
}
