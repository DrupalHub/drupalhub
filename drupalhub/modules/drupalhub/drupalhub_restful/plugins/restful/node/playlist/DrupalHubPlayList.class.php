<?php

/**
 * @file
 * Contains DrupalHubPlayList.
 */

class DrupalHubPlayList extends \DrupalHubRestfulBase {
  protected $controllers = array(
    '' => array(
      // GET returns a list of entities.
      \RestfulInterface::GET => 'getList',
      // POST
      \RestfulInterface::POST => 'createEntity',
      \RestfulInterface::DELETE => 'entityDelete',
      \RestfulInterface::PATCH => 'entityUpdate',
    ),
  );

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['videos'] = array(
      'property' => 'field_videos',
      'process_callbacks' => array(
        array($this, 'videosProcess'),
      ),
    );

    $public_fields['access'] = array(
      'property' => 'field_access_level',
    );

    $public_fields['body'] = array(
      'property' => 'body',
    );

    return $public_fields;
  }


  /**
   * Overrides \RestfulEntityBase::getQueryForList().
   *
   * Return a specific playlist.
   */
  public function getQueryForList() {
    $query = parent::getQueryForList();

    if (!empty($_GET['id'])) {
      $query
        ->propertyCondition('nid', $_GET['id']);
    }

    return $query;
  }

  /**
   * Set the the current user as the owner of the new playlist.
   */
  public function entityPreSave(\EntityMetadataWrapper $wrapper) {
    $wrapper->author->set($this->getAccount());
  }

  /**
   * Return the ID of the new playlist.
   */
  public function createEntity() {
    $results = parent::createEntity();
    $item = reset($results);
    drupal_json_output($item);
  }

  /**
   * Delete the entity.
   */
  public function entityDelete() {
    $result = $this->getRequest();
    $this->deleteEntity($result['id']);
  }

  /**
   * Bring back only the ids of the videos.
   */
  public function videosProcess($values) {
    $handler = restful_get_restful_handler('youtube');

    $results = array();
    foreach ($values as $value) {
      $rendered = $handler->get($value->nid);
      $results[] = reset($rendered);
    }

    return $results;
  }

  /**
   * Update the entity.
   */
  public function entityUpdate() {
    $request = $this->getRequest();
    $id = $request['id'];
    unset($request['id']);
    $this->setRequest($request);

    $this->updateEntity($id);

    drupal_json_output(array('id' => $id) + $request);
  }

}
