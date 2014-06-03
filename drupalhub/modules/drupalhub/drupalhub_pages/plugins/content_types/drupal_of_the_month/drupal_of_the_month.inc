<?php

$plugin = array(
  'title' => t('Drupal of the month'),
  'description' => t('Display the drupal of the month.'),
  'category' => t('DrupalHub pages'),
  'hook theme' => 'drupalhub_pages_drupal_of_the_month_content_type_theme',
);

function drupalhub_pages_drupal_of_the_month_content_type_render($subtype, $conf, $args, $context) {
  $wrapper = entity_metadata_wrapper('node', variable_get('drupal_of_the_month'));

  $block = new stdClass();
  $block->title = '';

  if ($wrapper->value()) {
    $file = $wrapper->field_project_banner_cropimage->value();
    $group = $wrapper->{OG_AUDIENCE_FIELD}->get(0);
    $block->content = theme('drupal_of_the_month', array(
      'image' => theme('image_style', array(
        'path' => $file['uri'],
        'style_name' => 'drupal_of_the_month',
        'attributes' => array(
          'class' => array('logo'),
        ),
      )),
      'title' => $wrapper->label(),
      'body' => $wrapper->body->value->value(),
      'group_link' => l($group->label(), 'node/' . $group->getIdentifier()),
      'strip' => theme('image', array(
        'path' => drupal_get_path('theme', 'drupalhub') . '/images/month_screen_overlay.png',
        'attributes' => array(
          'class' => array('strip'),
        ),
      )),
    ));
  }


  return $block;
}

function drupalhub_pages_drupal_of_the_month_content_type_theme(&$theme, $plugin) {
  $theme['drupal_of_the_month'] = array(
    'path' => $plugin['path'],
    'template' => 'drupal-of-the-month',
  );
}


