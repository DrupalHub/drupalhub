<?php

/**
 * @file
 * Contains DrupalHubEntityAccess.
 */
class DrupalHubEntityAccess extends \RestfulBase implements RestfulDataProviderInterface {
  /**
   * Overrides \RestfulEntityBase::controllers.
   */
  protected $controllers = array(
    '' => array(
      \RestfulInterface::GET => 'entityAccess',
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
      'access' => array(),
    );
  }

  /**
   * Check access operation for a given entity.
   */
  public function entityAccess() {
    $account = $this->getAccount();
    list($op, $entity_type, $entity_id) = array($this->request['op'], $this->request['type'], $this->request['id']);
    $entity = entity_load($entity_type, array($entity_id));
    return array(entity_access($op, $entity_type, reset($entity), $account));
  }
}