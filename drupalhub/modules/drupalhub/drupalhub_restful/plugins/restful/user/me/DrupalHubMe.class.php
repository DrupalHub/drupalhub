<?php

/**
 * @file
 * Contains DrupalHubMe.
 */
class DrupalHubMe extends \DrupalHubUsers {
  /**
   * Overrides \RestfulEntityBase::controllers.
   */
  protected $controllers = array(
    '' => array(
      \RestfulInterface::GET => 'viewEntity',
    ),
  );

  /**
   * Overrides \RestfulEntityBase::viewEntity().
   *
   * Always return the current user.
   */
  public function viewEntity($entity_id) {
    $account = $this->getAccount();

    if ($permission = \RestfulManager::getRequestHttpHeader('permission')) {

      // Check if we need to iterate over couple of permissions.
      $permissions = explode(',', $permission);
      if (count($permissions) > 1) {
        $return = array();

        foreach ($permissions as $permission) {
          $return[$permission] = user_access($permission, $account);
        }

        return $return;
      }

      return array('access' => user_access($permission, $account));
    }

    return parent::viewEntity($account->uid);
  }
}