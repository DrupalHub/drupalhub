<?php

class DrupalHubWiki extends DrupalHubRestfulNode {

  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['tags'] = array(
      'property' => 'field_category',
      'process_callbacks' => array(
        array($this, 'processTags'),
      ),
    );

    return $public_fields;
  }

  /**
   * {@inheritdoc}
   */
  public function propertyValuesPreprocess($property_name, $value, $public_field_name) {
    if ($public_field_name == 'tags') {
      $query = new EntityFieldQuery();

      $vocabulary = taxonomy_vocabulary_machine_name_load('wiki_category');

      $results = $query
        ->entityCondition('entity_type', 'taxonomy_term')
        ->propertyCondition('name', $value)
        ->propertyCondition('vid', $vocabulary->vid)
        ->execute();

      if (empty($results['taxonomy_term'])) {
        // Create new term.
        $term = new stdClass();
        $term->name = $value;
        $term->vid = $vocabulary->vid;
        $term = entity_create('taxonomy_term', array('name' => $value, 'vid' => $vocabulary->vid));
        entity_save('taxonomy_term', $term);
      }
      else {
        $term = reset(array_keys($results['taxonomy_term']));
      }

      return $term->tid;
    }
    return parent::propertyValuesPreprocess($property_name, $value, $public_field_name);
  }

}
