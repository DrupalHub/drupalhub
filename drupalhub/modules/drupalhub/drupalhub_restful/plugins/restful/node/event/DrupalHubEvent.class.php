<?php

class DrupalHubEvent extends \DrupalHubRestfulNode {

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
      'process_callbacks' => array(
        array($this, 'processDate'),
      ),
    );

    $public_fields['end'] = array(
      'property' => 'field_date',
      'sub_property' => 'value2',
      'process_callbacks' => array(
        array($this, 'processDate'),
      ),
    );

    $public_fields['google_address'] = array(
      'property' => 'field_date',
      'sub_property' => 'value2',
      'process_callbacks' => array(
        array($this, 'processDate'),
      ),
    );

    $public_fields['human_address'] = array(
      'property' => 'field_date',
      'sub_property' => 'value2',
      'process_callbacks' => array(
        array($this, 'processDate'),
      ),
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

  /**
   * Processing a date.
   */
  protected function processDate($value) {
    return date('d/m/Y H:i', $value);
  }
}
