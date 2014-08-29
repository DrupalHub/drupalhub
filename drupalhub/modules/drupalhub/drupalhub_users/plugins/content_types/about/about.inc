<?php

$plugin = array(
  'title' => t('About'),
  'description' => t('Smart about plugins with inline editing.'),
  'category' => t('DrupalHub users'),
  'required context' => new ctools_context_required(t('User'), 'user'),
);

function drupalhub_users_about_content_type_render($subtype, $conf, $args, $context) {
  $wrapper = entity_metadata_wrapper('user', $context->data);
  if ($wrapper->field_about->value()) {
    $value = $wrapper->field_about->value->value();
  }
  else {
    // todo: add access limitation.
    $value = t("Whoops! it seems that you don't have any description about your self. Why don't you <span class='add-info'>add some info</span>?");

    // Get the form widgets.
    $form = drupal_get_form('user_profile_form', $wrapper->value());
    hide($form['field_about'][LANGUAGE_NONE][0]['format']);
    $form['field_about'][LANGUAGE_NONE][]['#title'] = 'a';
    $value .= "<div class='field-about-wrapper disabled'>" . render($form['field_about']) . "</div>";
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

