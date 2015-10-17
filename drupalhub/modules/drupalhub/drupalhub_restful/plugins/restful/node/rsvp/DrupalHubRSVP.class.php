<?php

class DrupalHubRSVP extends \DrupalHubRestfulNode {

  /**
   * Overrides RestfulExampleArticlesResource::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['rsvp_status'] = array(
      'property' => 'field_status',
    );

    $public_fields['event'] = array(
      'property' => 'field_node_reference',
      'process_callbacks' => array(
        array($this, 'labelEvent'),
        array($this, 'processAuthor'),
      ),
    );

    return $public_fields;
  }

  public function labelEvent($node) {
    return $node->title;
  }

  public function queryForListFilter(\EntityFieldQuery $query) {
    parent::queryForListFilter($query);

    if ($this->getMethod() == RestfulBase::GET) {
      $query->propertyCondition('uid', $this->getAccount()->uid);
    }

  }

}
