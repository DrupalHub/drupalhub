<?php

$plugin = array(
  'title' => t('Wikipedia terns'),
  'description' => t('Display all the terms.'),
  'category' => t('DrupalHub wiki'),
  'required context' => new ctools_context_optional(t('Taxonomy term'), 'taxonomy_term'),
);

function drupalhub_wiki_wikipedia_terms_content_type_render($subtype, $conf, $args, $context) {

  $tid = !empty($context->data->tid) ? $context->data->tid : 0;
  $block = new stdClass();
  $block->title = '';

  $vid = taxonomy_vocabulary_machine_name_load('wiki_category');
  $terms = taxonomy_get_tree($vid->vid, 0, NULL, TRUE);

  $items = array();
  foreach ($terms as $term) {
    $items[] = $tid == $term->tid ? $term->name : l($term->name, 'documentation/term/' . $term->tid);
  }

  $block->content = theme('item_list', array('items' => $items));

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_wiki_wikipedia_terms_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_wiki_wikipedia_terms_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
