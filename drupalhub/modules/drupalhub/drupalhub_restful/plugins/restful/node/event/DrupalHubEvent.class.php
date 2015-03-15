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
      'property' => 'field_location',
      'process_callbacks' => array(
        array($this, 'processGoogleAddress'),
      ),
    );

    $public_fields['human_address'] = array(
      'property' => 'field_human_address',
    );

    $public_fields['latitude'] = array(
      'property' => 'field_location',
      'sub_property' => 'lat',
    );

    $public_fields['longitude'] = array(
      'property' => 'field_location',
      'sub_property' => 'lng',
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

  protected function processGoogleAddress($location) {
    $Maps = new DrupalHubGoogleMapsApi($location['lat'], $location['lng']);
    return $Maps->GetAddress('formatted_address');
  }

  /**
   * Get all the RSVP of the event.
   */
  protected function processRSVP($nid) {
    return array(
      'coming' => $this->queryEventRSVP('coming', $nid),
      'maybe' => $this->queryEventRSVP('maybe', $nid),
      'not' => $this->queryEventRSVP('not', $nid),
    );
  }

  /**
   * Get the RSVP users that their RSVP match to a given status.
   *
   * @param $status
   *   The status of the RSVP: yes, no or maybe.
   * @param $nid
   *   The event NID.
   *
   * @return array
   *   Array of users and their image.
   */
  private function queryEventRSVP($status, $nid) {
    $query = new EntityFieldQuery();

    $results = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'attendees')
      ->fieldCondition('field_node_reference', 'target_id', $nid)
      ->fieldCondition('field_status', 'value', $status)
      ->execute();

    if (empty($results['node'])) {
      return;
    }

    $nodes = node_load_multiple(array_keys($results['node']));

    $users = array();
    foreach ($nodes as $node) {
      $wrapper = entity_metadata_Wrapper('node', $node);

      $author = $wrapper->field_user_reference;
      $users[] = array(
        'name' => $author->label(),
        'image' => $this->authorImage($author->value()),
      );
    }

    return $users;
  }
}
