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
        array($this, 'processPoint'),
      ),
    );

    $public_fields['text'] = $public_fields['label'];
    unset($public_fields['label']);

    return $public_fields;
  }

}
