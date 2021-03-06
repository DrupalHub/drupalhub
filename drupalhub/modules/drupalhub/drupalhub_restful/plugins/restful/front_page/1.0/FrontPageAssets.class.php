<?php

class FrontPageAssets extends \RestfulBase implements RestfulDataProviderInterface {

  /**
   * Overrides \RestfulEntityBase::controllers.
   */
  protected $controllers = array(
    '' => array(
      \RestfulInterface::GET => 'frontPageAsset',
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
  public function frontPageAsset() {
    $this->getAccount();
    return array(
      'question' => $this->getContent('question'),
      'blog' => $this->getContent('blog'),
      'videos' => $this->getContent('video'),
      'events' => $this->getContent('event'),
    );
  }

  private function getContent($bundle) {
    $handler = restful_get_restful_handler($bundle);
    $handler->setRange(5);
    $list = $handler->getList();
    return array(($list));
  }
}