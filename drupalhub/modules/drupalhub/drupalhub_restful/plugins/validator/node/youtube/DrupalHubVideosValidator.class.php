<?php

/**
 * @file
 * Contains EntityValidatorExampleArticleValidator.
 */

class DrupalHubVideosValidator extends EntityValidateBase {

  /**
   * Overrides EntityValidateBase::getFieldsInfo().
   */
  public function publicFieldsInfo() {
    $fields = parent::publicFieldsInfo();

    $fields['field_address']['validators'][] = array($this, 'validateYouTubeAddress');

    return $fields;
  }

  /**
   * Validate that we don't have duplicate youtube files.
   */
  public function validateYouTubeAddress($field_name, $value) {
    $query = new EntityFieldQuery();
    $results = $query
      ->entityCondition('entity_type', 'node')
      ->fieldCondition('field_address', 'video_url', $value['video_url'])
      ->execute();

    if (empty($results['node'])) {
      return;
    }

    $nids = array_keys($results['node']);

    $node = node_load(reset($nids));

    $params = array(
      '@title' => $node->title,
      '@url' => url('node/' . $node->nid),
    );

    $this->setError($field_name, 'There is already a video with this youtube address: <a href="@url">@title</a>.', $params);
  }
}
