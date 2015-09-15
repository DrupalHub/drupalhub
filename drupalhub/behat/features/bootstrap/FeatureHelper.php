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
    $query = new EntityFieldQuery();
    $results = $query
      ->entityCondition('entity_type', 'restful_token_auth')
      ->execute();

    if (empty($results['restful_token_auth'])) {
      return;
    }

    entity_delete_multiple('restful_token_auth', array_keys($results['restful_token_auth']));
    
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

  /**
   * Get the node info: ID and label.
   *
   * @param $nodeLabel
   *   The node label.
   * @return Array
   *   containing the type of the node and the ID.
   * @throws Exception
   */
  public function getNodeInfo($nodeLabel) {
    $query = new EntityFieldQuery();

    $results = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('title', $nodeLabel)
      ->execute();

    if (empty($results['node'])) {
      throw new \Exception(sprintf('A node with the title %s was not found', $nodeLabel));
    }

    $node = node_load(key($results['node']));

    return [
      'type' => $node->type,
      'nid' => $node->nid,
    ];
  }
}
