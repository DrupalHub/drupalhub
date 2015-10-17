<?php

class DrupalHubEvent extends \DrupalHubRestfulNode {

  /**
   * Overrides RestfulExampleArticlesResource::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

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
      'process_callbacks' => array(
        array($this, 'filterXss'),
      ),
    );

    $public_fields['latitude'] = array(
      'property' => 'field_location',
      'sub_property' => 'lat',
    );

    $public_fields['longitude'] = array(
      'property' => 'field_location',
      'sub_property' => 'lng',
    );

    $public_fields['rsvp'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'processRSVP'),
      ),
    );

    return $public_fields;
  }

  public function propertyValuesPreprocess($property_name, $value, $public_field_name) {
    switch ($public_field_name) {
      case 'start':
        return array($this->dateProcessing($value));

      case 'latitude':
      case 'longitude':
        return array($value);
    }

    return parent::propertyValuesPreprocess($property_name, $value, $public_field_name);
  }

  /**
   * Process the date send via the REST request and re-format it to the matching
   * format.
   *
   * @param $value
   *   The date value.
   * @return string
   *   The date after the processing.
   */
  private function dateProcessing($value) {
    list($date, $time) = explode(' ', $value);
    list($day, $month, $year) = explode('/', $date);

    return ($year . '-' . $month . '-' . $day . ' ' . $time);
  }

  /**
   * Handle the date field properly.
   */
  public function entityPresave(\EntityMetadataWrapper $wrapper) {
    parent::entityPreSave($wrapper);
    $request = $this->getRequest();
    $wrapper->field_date->set(array(
      'value' => $this->dateProcessing($request['start']),
//      'value2' => $this->dateProcessing($request['end']),
    ));

    $wrapper->field_location->set(array(
      'lat' => $request['latitude'],
      'lng' => $request['longitude']
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

      $users[] = array(
        'name' => $wrapper->author->label(),
        'image' => $this->authorImage($wrapper->author->value()),
      );
    }

    return $users;
  }

  /**
   * Override parent::queryForListFilter().
   */
  public function queryForListFilter(\EntityFieldQuery $query) {
    parent::queryForListFilter($query);

    $operator = '<';
    if (!empty($this->request['type']) && $this->request['type'] == 'past') {
      $operator = '>';
    }

    $query->fieldCondition('field_date', 'value', date('Y-m-D H:i:s'), $operator);

  }
}
