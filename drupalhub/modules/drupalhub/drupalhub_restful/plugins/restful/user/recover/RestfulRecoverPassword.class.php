<?php

class RestfulRecoverPassword extends \RestfulBase implements RestfulDataProviderInterface {

  /**
   * Overrides \RestfulEntityBase::controllers.
   */
  protected $controllers = array(
    '' => array(
      \RestfulInterface::POST => 'recoverPassword',
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
      'status' => array(),
    );
  }

  /**
   * Generate email for reset the user password.
   *
   * @return array
   * @throws RestfulBadRequestException
   *
   * @see user_pass_validate()
   * @see user_pass_submit()
   */
  public function recoverPassword() {
    if (empty($this->request['name'])) {
      throw new \RestfulBadRequestException('You need to provide email address or user name.');
    }

    // Validating the request.
    $name = $this->request['name'];

    $users = user_load_multiple(array(), array('mail' => $name, 'status' => '1'));
    $account = reset($users);
    if (!$account) {
      // No success, try to load by name.
      $users = user_load_multiple(array(), array('name' => $name, 'status' => '1'));
      $account = reset($users);
    }

    if (!isset($account->uid)) {
      throw new \RestfulBadRequestException(format_string('Sorry, @name is not recognized as a user name or an e-mail address.', array('@name' => $name)));
    }

    _user_mail_notify('password_reset', $account);
  }
}