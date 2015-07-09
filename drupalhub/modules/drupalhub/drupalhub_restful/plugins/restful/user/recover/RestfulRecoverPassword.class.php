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
    $email = $this->request['email'];

    if (!$account = user_load_by_mail($email)) {
      throw new \RestfulBadRequestException('Email does\'t exists.');
    }

    drupalhub_send_token_to_user('reset_password', $account);

    throw new \DrupalHubRestfulEmptyResponse();
  }
}
