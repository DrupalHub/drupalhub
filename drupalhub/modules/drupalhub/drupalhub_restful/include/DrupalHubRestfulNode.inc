<?php


class DrupalHubRestfulNode extends \DrupalHubEntityBase {

  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['url'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'generatePath'),
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

    $public_fields['intro'] = array(
      'property' => 'body',
      'process_callbacks' => array(
        array($this, 'bodyIntro'),
        array($this, 'filterXss'),
      ),
    );

    $public_fields['text'] = array(
      'property' => 'body',
      'process_callbacks' => array(
        array($this, 'body'),
        array($this, 'filterXss'),
      ),
    );

    return $public_fields;
  }

  /**
   * Sort the query for list.
   *
   * @param \EntityFieldQuery $query
   *   The query object.
   *
   * @throws \RestfulBadRequestException
   *
   * @see \RestfulEntityBase::getQueryForList
   */
  protected function queryForListSort(\EntityFieldQuery $query) {
    $query->propertyOrderBy('created', 'DESC');
  }

  /**
   * Get the path of the element. i.e: question => question.html#30.
   *
   * @param $nid
   *   The nid of the node.
   * @return string
   *   The path of the entry.
   */
  protected function generatePath($nid) {
    switch ($this->getBundle()) {
      case 'blog':
        return '#/blog/' . $nid;

      case 'wiki':
        return '#/documentation/' . $nid;

      case 'events':
        return '#/event/' . $nid;

      case 'question':
        return '#/question/' . $nid;

      case 'youtube':
        if (!empty($this->playlist)) {
          return '#/playlist/' . $this->playlist['nid'] . '/' . $this->playlist['delta'];
        }
        return '#/video/' . $nid;

      case 'playlist':
        return '#/playlist/' . $nid . '/1';
    }
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
    return $body['value'];
  }

  /**
   * Return the tags in a specific format.
   */
  protected function processTags($terms) {
    $tags = array();

    if (!is_array($terms)) {
      return array(array('label' => $terms->name, 'id' => $terms->tid));
    }

    foreach ($terms as $term) {
      $tags[] = array(
        'label' => $term->name,
        'url' => 'tags.html#' . $term->tid,
      );
    }
    return $tags;
  }

  /**
   * Overrides RestfulEntityBase::getQueryForList().
   *
   * Expose only published nodes.
   */
  public function getQueryForList() {
    $query = parent::getQueryForList();
    $query->propertyCondition('status', NODE_PUBLISHED);
    return $query;
  }

  /**
   * Overrides RestfulEntityBase::entityPreSave().
   *
   * Set the node author and other defaults.
   */
  public function entityPreSave(\EntityMetadataWrapper $wrapper) {
    $node = $wrapper->value();
    if (!empty($node->nid)) {
      // Node is already saved.
      return;
    }
    node_object_prepare($node);
    $node->uid = $this->getAccount()->uid;
  }
}