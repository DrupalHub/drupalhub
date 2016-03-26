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
      'process_callbacks' => array(
        array($this, 'processImage'),
      ),
    );

    $public_fields['addresses'] = array(
      'property' => 'field_addresses',
      'process_callbacks' => array(
        array($this, 'processAddresses'),
      ),
    );

    $public_fields['social_links'] = array(
      'property' => 'field_social_networks',
    );

    $public_fields['members'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'getCompanyMembers'),
      ),
    );

    return $public_fields;
  }

  /**
   * Display only the lng and lat of the offices.
   */
  protected function processAddresses($value) {
    array_walk($value, function(&$value) {
      $value = array(
        'lat' => $value['lat'],
        'lng' => $value['lat'],
      );
    });

    return $value;
  }

  /**
   * Get the logo of the group.
   */
  protected function processImage($value) {
    // todo use image style.
    return file_create_url($value['uri']);
  }

  /**
   * Get the company employees in the site.
   *
   * @param $nid
   *   The company nid.
   *
   * @return array
   *   List of employees.
   */
  public function getCompanyMembers($nid) {
    $query = new \EntityFieldQuery();
    $results = $query
      ->entityCondition('entity_type', 'og_membership')
      ->propertyCondition('type', 'company_membership')
      ->propertyCondition('gid', $nid)
      ->execute();

    if (empty($results['og_membership'])) {
      return array();
    }

    /** @var DrupalHubCompanyMembership $handler */
    $handler = restful_get_restful_handler('companies_membership');

    $members = array();

    foreach (array_keys($results['og_membership']) as $mid) {
      $members[] = $handler->viewEntity($mid);
    }

    return $members;
  }

}
