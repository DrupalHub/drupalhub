<?php

$plugin = array(
  'title' => t('User picture'),
  'description' => t('Display the user picture.'),
  'category' => t('DrupalHub users'),
  'required context' => new ctools_context_required(t('User'), 'user'),
);

function drupalhub_users_user_picture_content_type_render($subtype, $conf, $args, $context) {

  if (!$context->data->picture) {
    return;
  }

  $uri = $context->data->picture->uri;

  $block = new stdClass();
  $block->content = theme('image_style', array('path' => $uri, 'style_name' => $conf['image_styles']));

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_users_user_picture_content_type_edit_form($form, &$form_state) {
  $image_styles = image_styles();

  $options = array();

  foreach ($image_styles as $image_style) {
    $options[$image_style['name']] = $image_style['label'];
  }

  $form['image_styles'] = array(
    '#type' => 'select',
    '#title' => t('Image style type'),
    '#options' => $options,
    '#description' => t('Select the image style to apply on the user picture.'),
    '#default_value' => $form_state['conf']['image_styles'] ? $form_state['conf']['image_styles'] : '',
  );

  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_users_user_picture_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

