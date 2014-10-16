<?php

/**
 * @file
 * Search class for DrupalHub search.
 */

class DrupalHubSearch {

  /**
   * @var SearchApiQuery
   *
   * Holds the search index machine name.
   */
  protected $query;

  /**
   * @var String
   *
   * The entity type.
   */
  protected $EntityType;

  /**
   * @var array
   *
   * Holds the fields we need iterate when searching.
   */
  protected $fields = array(
    'user' => array('name'),
    'node' => array('title', 'body:value'),
    'taxonomy_term' => array('name'),
    'comment' => array('comment_body:value'),
  );

  /**
   * @var SearchApiQueryFilterInterface
   */
  protected $filter;

  /**
   * Init the class.
   *
   * @param $EntityType
   *   The index name.
   */
  function __construct($EntityType) {
    $this->EntityType = $EntityType;
    $indexes = array(
      'node' => 'nodes',
      'user' => 'users',
      'taxonomy_term' => 'tags',
      'comment' => 'comments',
    );

    $index = search_api_index_load($indexes[$EntityType]);
    $this->query = new SearchApiQuery($index);
    $this->filter = $this->query->createFilter('OR');
  }

  /**
   * Adds a new ($field $operator $value) condition filter.
   *
   * @param string $field
   *   The field to filter on, e.g. 'title'.
   * @param mixed $value
   *   The value the field should have (or be related to by the operator).
   * @param string $operator
   *   The operator to use for checking the constraint. The following operators
   *   are supported for primitive types: "=", "<>", "<", "<=", ">=", ">". They
   *   have the same semantics as the corresponding SQL operators.
   *   If $field is a fulltext field, $operator can only be "=" or "<>", which
   *   are in this case interpreted as "contains" or "doesn't contain",
   *   respectively.
   *   If $value is NULL, $operator also can only be "=" or "<>", meaning the
   *   field must have no or some value, respectively.
   *
   * @return $this
   *
   * @see SearchApiQueryInterface::condition().
   */
  public function OrCondition($field, $value, $operator = '=') {
    $this->filter->condition($field, $value, $operator);
    return $this;
  }

  /**
   * Adds a new ($field $operator $value) condition filter.
   *
   * @param string $field
   *   The field to filter on, e.g. 'title'.
   * @param mixed $value
   *   The value the field should have (or be related to by the operator).
   * @param string $operator
   *   The operator to use for checking the constraint. The following operators
   *   are supported for primitive types: "=", "<>", "<", "<=", ">=", ">". They
   *   have the same semantics as the corresponding SQL operators.
   *   If $field is a fulltext field, $operator can only be "=" or "<>", which
   *   are in this case interpreted as "contains" or "doesn't contain",
   *   respectively.
   *   If $value is NULL, $operator also can only be "=" or "<>", meaning the
   *   field must have no or some value, respectively.
   *
   * @return $this
   *
   * @see SearchApiQueryInterface::condition().
   */
  public function Condition($field, $value, $operator = '=') {
    $this->query->condition($field, $value, $operator);
    return $this;
  }

  /**
   * Executing the query and return the loaded entity.
   */
  public function execute() {
    $this->query->filter($this->filter);
    $data = $this->query->execute();
    $results = $data['results'];

    if (!$results) {
      return;
    }

    return entity_load($this->EntityType, array_keys($results));
  }

  /**
   * @return String
   *   The entity type.
   */
  public function getEntityType() {
    return $this->EntityType;
  }

  public function getFields() {
    return $this->fields[$this->EntityType];
  }
}
