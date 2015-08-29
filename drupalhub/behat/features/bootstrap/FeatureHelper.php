<?php

class FeatureHelper {

  /**
   * @var FeatureContext
   */
  private $context;

  /**
   * @var Array
   */
  private $accessToken;

  public function __construct(FeatureContext $context) {
    $this->context = $context;
  }

  public function ClearLocalStorage() {
    $this->context->visit($this->context->getMinkParameter('base_url'));
    $this->context->getSession()->evaluateScript('localStorage.clear();');
  }

  /**
   * Get/generate access token for user.
   *
   * @param $username
   */
  public function getAccessToken($username) {
    if (isset($this->accessToken[$username])) {
      return $this->accessToken[$username]['access_token'];
    }

    $handler = new RestfulAccessTokenAuthentication(['entity_type' => 'restful_token_auth','bundle' => 'access_token']);

    $handler->setAccount(user_load_by_name($username));
    $data = $handler->getOrCreateToken();
    $this->accessToken[$username] = $data;

    return $data['access_token'];
  }

  /**
   * Removing screen shots from old tests.
   */
  public function wipeScreenShots() {
    $files = glob(getcwd() . '/screenshots/*.png');

    foreach ($files as $file) {
      unlink($file);
    }
  }
}
