<?php

$plugin = array(
  'title' => t('Recent'),
  'description' => t('Retrieve recent information.'),
  'category' => t('DrupalHub users'),
  'required context' => new ctools_context_required(t('User'), 'user'),
);

function drupalhub_users_recent_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  $query = new EntityFieldQuery();
  $results = $query
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', $conf['bundle'])
    ->propertyCondition('uid', $context->data->uid)
    ->propertyOrderBy('created',  'DESC')
    ->execute();

  if (empty($results['node'])) {
    return $block;
  }

  $node = node_load(reset($results['node'])->nid);
  $uri = entity_uri('node', $node);
  $params = array(
    '@bundle' => $conf['bundle'],
    '@href' => $uri['path'],
    '@label' => $node->title,
  );
  $block->content = t('Recent @bundle: <a href="@href">@label</a>',$params);

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_users_recent_content_type_edit_form($form, &$form_state) {
  $image_styles = image_styles();

  $options = array();

  foreach ($image_styles as $image_style) {
    $options[$image_style['name']] = $image_style['label'];
  }

  $form['bundle'] = array(
    '#type' => 'select',
    '#title' => t('Recent bundle'),
    '#options' => array('blog' => t('Blog'), 'question' => t('Question')),
    '#description' => t("Select the bundle of node you'ld like to retrieve the last entry of the user."),
    '#default_value' => $form_state['conf']['bundle'] ? $form_state['conf']['bundle'] : '',
  );

  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_users_recent_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

