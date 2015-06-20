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
          $return[$permission] = $this->userAccess($permission, $account);
        }

        return $return;
      }

      return array('access' => $this->userAccess($permission, $account));
    }

    return parent::viewEntity($account->uid);
  }

  /**
   * Check user access for special cases.
   *
   * @param $permission
   *   The permission string.
   * @param $account
   *   The account of the user.
   *
   * @return bool
   */
  private function userAccess($permission, $account) {
    $id = 0;

    if (strpos($permission, ':') !== FALSE) {
      list($permission, $id) = explode(':', $permission);
    }

    if ($permission == 'edit user') {
      return user_edit_access($id ? user_load($id) : $account);
    }

    return user_access($permission, $account);
  }
}