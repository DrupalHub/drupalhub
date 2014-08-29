<?php

$plugin = array(
  'title' => t('About'),
  'description' => t('Smart about plugins with inline editing.'),
  'category' => t('DrupalHub users'),
  'required context' => new ctools_context_required(t('User'), 'user'),
);

function drupalhub_users_about_content_type_render($subtype, $conf, $args, $context) {
  global $user;

  $wrapper = entity_metadata_wrapper('user', $context->data);
  if ($wrapper->field_about->value()) {
    $value = $wrapper->field_about->value->value();
  }
  elseif ($wrapper->getIdentifier() == $user->uid) {
    $link = array(
      'text' => t('add some info'),
      'href' => 'drupalhub_users/update_about/' . $wrapper->getIdentifier(),
      'class' => 'update-about',
      'modal_settings' => array(
        'modalSize' => array(
          'type' => 'scale',
        ),
        'modalOptions' => array('opacity' => .6),
        'animation' => 'fadeIn',
      ),
    );

    $link = drupalhub_core_modal_window($link);

    $value = t("Whoops! it seems that you don't have any description about your self. Why don't you !link?", array('!link' => $link));
  }
  else {
    $value = '';
  }

  $block = new stdClass();
  $block->content = $value;

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_users_about_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_users_about_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

