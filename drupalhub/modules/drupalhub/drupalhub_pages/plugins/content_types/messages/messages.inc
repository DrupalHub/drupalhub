<?php

$plugin = array(
  'title' => t('Messages'),
  'description' => t('Display facebook statuses or tweets in a block.'),
  'category' => t('DrupalHub pages'),
);

function drupalhub_pages_messages_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = '';
  $block->content = '
  <div class="panel panel-default">
              <div class="panel-heading">Title here</div>
              <div class="panel-body">
                Content here.
              </div>
            </div>
  ';

  return $block;
}

/**
 * Implementation of a content_type edit form
 */
function drupalhub_pages_messages_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['address'] = array(
    '#type' => 'textfield',
    '#title' => t('Address'),
    '#description' => t('Specify the address which the statuses are supplied via JSON .'),
    '#default_value' => $conf['address'],
  );

  return $form;
}

/**
 * Implementation of a content_type edit form submit callback
 */
function drupalhub_pages_messages_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
