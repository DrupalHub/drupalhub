<?php

/**
 * @file
 * Contains DrupalHubPlayList.
 */

class DrupalHubQuestion extends \DrupalHubRestfulNode {

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['tags'] = array(
      'property' => 'field_tags',
      'process_callbacks' => array(
        array($this, 'processTags'),
      ),
    );

    $public_fields['vote'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'processVotes'),
      ),
    );

    return $public_fields;
  }

  /**
   * {@inheritdoc}
   */
  public function entityPreSave(\EntityMetadataWrapper $wrapper) {
    parent::entityPreSave($wrapper);

    $request = $this->getRequest();

    // Tear down the string.
    $vocabulary = taxonomy_vocabulary_machine_name_load('tags');

    // Look for terms object with that name.
    $tids = array();

    foreach ($request['tags'] as $term) {
      if ($tid = taxonomy_get_term_by_name(trim($term), 'tags')) {
        $tids[] = reset($tid)->tid;
      }
      else {
        $taxonomy = new stdClass();
        $taxonomy->name = trim($term);
        $taxonomy->vid = $vocabulary->vid;
        taxonomy_term_save($taxonomy);
        $tids[] = $taxonomy->tid;
      }
    }

    $wrapper->field_tags->set($tids);
  }
}
