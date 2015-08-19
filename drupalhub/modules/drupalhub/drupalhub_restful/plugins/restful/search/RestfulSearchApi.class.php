<?php

class RestfulSearchApi extends \RestfulBase implements RestfulDataProviderInterface {

  /**
   * Overrides \RestfulEntityBase::controllers.
   */
  protected $controllers = array(
    '' => array(
      \RestfulInterface::GET => 'getResult',
    ),
  );

  /**
   * Return the properties that should be public.
   *
   * @throws \RestfulEntityViewMode
   *
   * @return array
   */
  public function publicFieldsInfo() {
    return array(
      'results' => array(),
    );
  }

  /**
   * Get results for a query search.
   */
  public function getResult() {
    if (empty($this->request['entity_type']) || empty($this->request['value'])) {
      throw new \RestfulBadRequestException('You did not specify entity type or value.');
    }

    if (!$results = $this->getResults($this->request['entity_type'], $this->request['value'])) {
      throw new \RestfulBadRequestException('The search finished without any results.');
    }

    return array('results' => $results);
  }

  /**
   * Running search against a given query.
   *
   * @param $index
   *   The index which the query will run against.
   * @param $value
   *   The value to search.
   * @return array
   *   Array of results.
   */
  private function getResults($index, $value) {
    $search = new DrupalHubSearch($index);
    $results = array();

    foreach ($search->getFields() as $field) {
      $search->OrCondition($field, $value);
    }

    $entities = $search->execute();

    if (!$entities) {
      return array();
    }

    foreach ($entities as $entity) {
      $wrapper = entity_metadata_wrapper($search->getEntityType(), $entity);

      if (in_array($search->getEntityType(), array('comment', 'user'))) {
        $handler = $search->getEntityType();
      }
      elseif ($search->getEntityType() == 'node') {
        $handler = $wrapper->getBundle();
      }
      else {
        continue;
      }

      $restful_handler = restful_get_restful_handler($handler);
      $results[] = $restful_handler->viewEntity($wrapper->getIdentifier());
    }

    return $results;
  }
}
