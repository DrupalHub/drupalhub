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
      ->setProperty('name')
      ->addCallback('validateSingle');

    FieldsInfo::setFieldInfo($public_fields['mail'], $this)
      ->setProperty('mail')
      ->addCallback('validateSingle');

    unset($public_fields['field_entity_view_count']);

    return $public_fields;
  }

  public function getPublicFields() {
    $fields = parent::getPublicFields();
    $fields['label']['property'] = 'name';
    return $fields;
  }

  public function validateSingle($field, $value) {
    $query = new EntityFieldQuery();
    $number = $query
      ->entityCondition('entity_type', 'user')
      ->propertyCondition($field, $value)
      ->count()
      ->execute();

    if ($number) {
      $message = array(
        'name' => 'A user with that name already exists.',
        'mail' => 'A user with that mail address already exists.',
      );
      $this->setError($field, $message[$field]);
    }
  }

}
