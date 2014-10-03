<?php

$plugin = array(
  'title' => t('Links'),
  'description' => t('Links for the wiki page.'),
  'category' => t('DrupalHub wiki'),
);

function drupalhub_wiki_links_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = '';
  $items = array(
    l(t('Front page'), 'documentation'),
    l(t('FAQ'), 'documentation/FAQ'),
    l(t('Top rated'), 'documentation/top-rated'),
    l(t('Most viewed'), 'documentation/most-viewed'),
  );

  if (user_access('create wiki content')) {
    $items[] = l(t('Create documentation'), 'documentation/add');
  }
  $block->content = theme('item_list', array('items' => $items));
  return $block;
}

/**
 * Form settings.
 */
function drupalhub_wiki_links_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_wiki_links_box_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

