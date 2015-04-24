<?php

/**
 * @file
 * Contains EntityValidatorExampleArticleValidator.
 */

class DrupalHubUsersValidate extends EntityValidateBase {

  /**
   * Overrides EntityValidateBase::getFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    FieldsInfo::setFieldInfo($public_fields['label'], $this)
      ->setProperty('label')
      ->addCallback('validateSingle');

    return $public_fields;
  }

  public function validateSingle($field, $value) {
    $this->setError('label', 'foo');
  }

}
