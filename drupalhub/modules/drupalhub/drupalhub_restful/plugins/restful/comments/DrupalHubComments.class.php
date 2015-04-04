<?php

class DrupalHubComments extends \DrupalHubEntityBase {

  /**
   * {@inheritdoc}
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['point'] = array(
      'property' => 'cid',
      'process_callbacks' => array(
        array($this, 'countLiked'),
      ),
    );

    $public_fields['nid'] = array(
      'property' => 'node',
    );

    $public_fields['text'] = array(
      'property' => 'comment_body',
      'process_callbacks' => array(
        array($this, 'body'),
      ),
    );

    return $public_fields;
  }

  /**
   * The full body value.
   *
   * @param $body
   *   The body field.
   * @return mixed
   *   The safe value.
   */
  protected function body($body) {
    return $body['value'];
  }

  protected function queryForListFilter(\EntityFieldQuery $query) {
    parent::queryForListFilter($query);

    if (!empty($this->request['nid'])) {
      $query->propertyCondition('nid', $this->request['nid']);
    }
  }

}
