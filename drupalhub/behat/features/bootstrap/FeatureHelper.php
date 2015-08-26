<?php

class FeatureHelper {

  /**
   * @var FeatureContext
   */
  private $context;

  public function __construct(FeatureContext $context) {
    $this->context = $context;
  }

  public function ClearLocalStorage() {
    $this->context->visit($this->context->getMinkParameter('base_url'));
    $this->context->getSession()->evaluateScript('localStorage.clear();');
  }
}
