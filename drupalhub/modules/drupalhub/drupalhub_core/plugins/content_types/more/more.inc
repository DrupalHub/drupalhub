<?php

$plugin = array(
  'title' => t('More plugin'),
  'description' => t('Small more link for other pages'),
  'category' => t('DrupalHub core'),
  'defaults' => array(
    'page' => 'questions',
  ),
);

function drupalhub_core_more_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  if ($conf['page'] == 'questions') {
    $block->content = l(t('More questions'), 'questions');
  }
  else {
    $block->content = l(t('More blogs'), 'blogs');
  }

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_core_more_content_type_edit_form($form, &$form_state) {
  $form['page'] = array(
    '#type' => 'select',
    '#title' => t('Select page'),
    '#options' => array(
      'questions' => t('Questions'),
      'blogs' => t('Blog'),
    ),
    '#default_value' => $form_state['conf']['page'],
  );
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_core_more_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

