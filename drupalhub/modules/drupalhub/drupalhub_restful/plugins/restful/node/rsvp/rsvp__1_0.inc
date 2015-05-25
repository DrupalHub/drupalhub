<?php

$plugin = array(
  'label' => t('Event'),
  'description' => t('Restuling attendees bundle.'),
  'resource' => 'rsvp',
  'class' => 'DrupalHubRSVP',
  'name' => 'rsvp__1_0',
  'entity_type' => 'node',
  'bundle' => 'attendees',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
