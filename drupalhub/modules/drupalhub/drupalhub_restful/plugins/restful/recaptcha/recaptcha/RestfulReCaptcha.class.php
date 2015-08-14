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
    // Build the process.
    $postdata = http_build_query(
      array(
        'secret' => variable_get('recaptcha_secret'),
        'response' => $this->request['response'],
        'remoteip' => $_SERVER['REMOTE_ADDR']
      )
    );

    $opts = array('http' =>
      array(
        'method'  => 'POST',
        'header'  => 'Content-type: application/x-www-form-urlencoded',
        'content' => $postdata
      )
    );

    // Verify the response.
    $context  = stream_context_create($opts);
    $response = file_get_contents("https://www.google.com/recaptcha/api/siteverify",false,$context);
    $response = json_decode($response, true);
    return array('passed' => $response['success']);
  }
}
