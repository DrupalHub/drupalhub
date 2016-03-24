<?php

class DrupalHubCompany extends \DrupalHubRestfulNode {

  /**
   * Overrides RestfulExampleArticlesResource::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['telephone'] = array(
      'property' => 'field_telephone',
    );

    $public_fields['technologies'] = array(
      'property' => 'field_technologies',
      'resource' => array(
        'technlogies' => 'technologies',
      ),
    );

    $public_fields['site_address'] = array(
      'property' => 'field_site_address',
      'sub_property' => 'url',
    );

    $public_fields['email'] = array(
      'property' => 'field_email',
    );

    $public_fields['hiring'] = array(
      'property' => 'field_hiring',
    );

    $public_fields['hiring_mail'] = array(
      'property' => 'field_email_hiring_field',
    );

    $public_fields['logo'] = array(
      'property' => 'field_logo',
    );

    $public_fields['addresses'] = array(
      'property' => 'field_addresses',
      'process_callbacks' => array(
        array($this, 'processAddresses'),
      ),
    );

    return $public_fields;
  }

  protected function processAddresses($value) {
    array_walk($value, function(&$value) {
      $value = array(
        'lat' => $value['lat'],
        'lng' => $value['lat'],
      );
    });

    return $value;
  }

}
