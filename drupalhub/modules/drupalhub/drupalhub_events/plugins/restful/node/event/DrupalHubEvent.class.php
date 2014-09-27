<?php

class DrupalHubEvent extends \RestfulEntityBaseNode {

  /**
   * Overrides RestfulExampleArticlesResource::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
    );

    $public_fields['start'] = array(
      'property' => 'field_date',
      'sub_property' => 'value',
    );

    $public_fields['end'] = array(
      'property' => 'field_date',
      'sub_property' => 'value2',
    );

    return $public_fields;
  }

  /**
   * Handle the date field properly.
   */
  public function entityPresave(\EntityMetadataWrapper $wrapper) {
    parent::entityPreSave($wrapper);
    $request = $this->getRequest();
    $wrapper->field_date->set(array(
      'value' => $request['start']['value'],
      'value2' => $request['end']['value'],
    ));
  }
}
