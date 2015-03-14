<?php

class DrupalHubBlog extends \DrupalHubRestfulNode {

  /**
   * {@inheritdoc}
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['date'] = array(
      'property' => 'created',
      'process_callbacks' => array(
        array($this, 'processDate'),
      ),
    );

    $public_fields['author'] = array(
      'property' => 'author',
      'process_callbacks' => array(
        array($this, 'processAuthor'),
      ),
    );

    $public_fields['viewed'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'countViewed'),
      ),
    );

    $public_fields['like'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'countLiked'),
      ),
    );

    $public_fields['url'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'generatePath'),
      ),
    );

    $public_fields['intro'] = array(
      'property' => 'body',
      'process_callbacks' => array(
        array($this, 'bodyIntro'),
      ),
    );

    $public_fields['text'] = array(
      'property' => 'body',
      'process_callbacks' => array(
        array($this, 'body'),
      ),
    );

    return $public_fields;
  }

  /**
   * Return the intro of the blog.
   *
   * @param $body
   *   The body field.
   * @return string
   *   250 characters of the body.
   */
  protected function bodyIntro($body) {
    return views_trim_text(array('max_length' => 250, 'html' => TRUE), $body['value']);
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
    return $body['safe_value'];
  }

}
