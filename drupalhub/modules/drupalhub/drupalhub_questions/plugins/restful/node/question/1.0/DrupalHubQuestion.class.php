<?php

/**
 * @file
 * Contains DrupalHubPlayList.
 */

class DrupalHubQuestion extends \RestfulEntityBase {
  protected $controllers = array(
    '' => array(
      \RestfulInterface::GET => 'getList',
      \RestfulInterface::POST => 'createEntity',
    ),
  );

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['body'] = array(
      'property' => 'body',
    );

    $public_fields['tags'] = array(
      'property' => 'field_tags',
    );

    return $public_fields;
  }

  /**
   * Set the the current user as the owner of the new question.
   */
  public function entityPreSave(\EntityMetadataWrapper $wrapper) {
    $wrapper->author->set($this->getAccount());
  }

  /**
   * Return the object of the new question.
   */
  public function createEntity() {
    // Get the request.
    $request = $this->getRequest();
    static::cleanRequest($request);

    // Load the vocabulary and get the terms ID.
    $vocab = taxonomy_vocabulary_machine_name_load('tags');
    $names = explode(",", $request['tags']);

    $tids = array();
    foreach ($names as $name) {
      $name = trim($name);
      if (empty($name)) {
        continue;
      }
      $tids[] = $this->getTermID($name, $vocab->vid)->tid;
    }

    $request['tags'] = $tids;
    $this->setRequest($request);
    $results = parent::createEntity();
    $item = reset($results);
    drupal_json_output($item);
  }

  /**
   * Return the term ID according to the name. If the term name was not found in
   * the vocabulary a new one will be created and return as well.
   *
   * @param $name
   *   The term name.
   * @param $vid
   *   The vocabulary ID.
   *
   * @return stdClass
   *   The term object.
   */
  private function getTermID($name, $vid) {
    $query = new EntityFieldQuery();

    $result = $query
      ->entityCondition('entity_type', 'taxonomy_term')
      ->propertyCondition('name', $name)
      ->propertyCondition('vid', $vid)
      ->execute();

    if (empty($result['taxonomy_term'])) {
      $term = new stdClass();
      $term->name = $name;
      $term->vid = $vid;
      taxonomy_term_save($term);
    }
    else {
      $tid = reset(array_keys($result['taxonomy_term']));
      $term = taxonomy_term_load($tid);
    }

    return $term;
  }
}
