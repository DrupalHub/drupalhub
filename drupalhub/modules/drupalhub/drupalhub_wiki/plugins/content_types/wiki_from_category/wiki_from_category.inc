<?php

$plugin = array(
  'title' => t('Wiki from category'),
  'description' => t('DDisplay a list of nodes from a given category.'),
  'category' => t('DrupalHub wiki'),
);

function drupalhub_wiki_wiki_from_category_content_type_render($subtype, $conf, $args, $context) {
  static $nodes, $tids;

  if (!$tids) {
    $tids = array();
  }

  if (!$nodes) {
    $query = new EntityFieldQuery();
    $results = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'wiki')
      ->propertyOrderBy('created', 'DESC')
      ->fieldOrderBy('field_category', 'tid')
      ->execute();

    if (!empty($results['node'])) {
      $nids = (array_keys($results['node']));

      $tids = array();
      foreach ($nids as $nid) {
        $wrapper = entity_metadata_wrapper('node', $nid);
        $tid = $wrapper->field_category->getIdentifier();

        if (!in_array($tid, $tids)) {
          $tids[] = $tid;
        }

        $nodes[$tid][] = $nid;
      }
    }
  }

  $tids = array_unique($tids);

  $position = $conf['position'];
  $block = new stdClass();

  if (empty($tids[$position])) {
    return $block;
  }

  $term = taxonomy_term_load($tids[$position]);

  $block->title = "";
  $block->content = "<h2>" . $term->name . "</h2>";
  $block->content .= views_embed_view('last_wiki_nodes', 'default', implode(",", $nodes[$term->tid]));
  return $block;
}

/**
 * Form settings.
 */
function drupalhub_wiki_wiki_from_category_content_type_edit_form($form, &$form_state) {
  $form['position'] = array(
    '#type' => 'select',
    '#title' => t('Position'),
    '#description' => t('Select the position: first, second or third'),
    '#options' => array(
      0 => t('First'),
      1 => t('Second'),
      2 => t('Third'),
    ),
    '#default_value' => $form_state['conf']['position'],
  );
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_wiki_wiki_from_category_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

