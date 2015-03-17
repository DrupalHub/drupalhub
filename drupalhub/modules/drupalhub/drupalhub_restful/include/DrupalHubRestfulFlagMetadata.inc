<?php

class DrupalHubRestfulFlagMetadata extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['user'] = array(
      'label' => t("User"),
      'type' => 'user',
      'description' => t("The user for which to log the message."),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'schema field' => 'uid',
      'required' => TRUE,
    );

    return $properties;
  }
} 