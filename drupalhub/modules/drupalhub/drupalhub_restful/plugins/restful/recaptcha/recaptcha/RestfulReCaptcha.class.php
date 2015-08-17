<?php

class RestfulReCaptcha extends \RestfulBase implements RestfulDataProviderInterface {

  /**
   * Overrides \RestfulEntityBase::controllers.
   */
  protected $controllers = array(
    '' => array(
      \RestfulInterface::POST => 'verifyCaptcha',
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
      'passed' => array(),
    );
  }

  /**
   * Verify the reCaptcha results.
   */
  public function verifyCaptcha() {

    $path = libraries_get_path('reCaptcha') . '/src/';
    require_once $path . 'autoload.php';

    $recaptcha = new \ReCaptcha\ReCaptcha(variable_get('recaptcha_secret'));
    $resp = $recaptcha->verify($this->request['response']);

    if (!$resp->isSuccess()) {
      doctor_create($resp->getErrorCodes())->save();
    }

    return array('passed' => $resp->isSuccess());
  }
}
