<?php

$plugin = array(
  'title' => t('Wiki from category'),
  'description' => t('DDisplay a list of nodes from a given category.'),
  'category' => t('DrupalHub wiki'),
  'required context' => new ctools_context_optional(t('Taxonomy term'), 'taxonomy_term'),
);

function drupalhub_wiki_wiki_from_category_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  if ($conf['location'] == 'wiki_home') {
    if (!$data = _drupalhub_wiki_nodes_front_page($conf)) {
      return $block;
    }

    $pane = 'default';
  }
  else {
    if (!$data = _drupalhub_wiki_get_nodes_term_page($context->data->tid)) {
      return $block;
    }

    $pane = 'panel_pane_2';
  }

  $block->title = "";
  $block->content = "<h2>" . $data['term']->name . "</h2>";
  $block->content .= views_embed_view('last_wiki_nodes', $pane, $data['nodes']);
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

  $form['location'] = array(
    '#type' => 'select',
    '#title' => t('Location'),
    '#options' => array(
      'wiki_home' => t('Documentation home page'),
      'wiki_category' => t('Documentation term page'),
    ),
  );
  return $form;
}

/**
 * Get the nodes for the documentation home page.
 *
 * @param $conf
 *   The plugin configuration.
 *
 * @return array
 *   - term: The current term object.
 *   - nodes: List of 3 node ids after imploded with comma.
 */
function _drupalhub_wiki_nodes_front_page($conf) {
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

  if (empty($tids[$position])) {
    return;
  }

  $term = taxonomy_term_load($tids[$position]);

  return array('term' => $term, 'nodes' => implode(",", array_slice($nodes[$term->tid], 0, 3)));
}

/**
 * Get the nodes for the documentation term page.
 *
 * @param $tid
 *   The term ID.
 *
 * @return array
 *   - term: The current term object.
 *   - nodes: List of node IDs after imploded with comma.
 */
function _drupalhub_wiki_get_nodes_term_page($tid) {
  $query = new EntityFieldQuery();
  $results = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_category', 'tid', $tid)
    ->propertyCondition('type', 'wiki')
    ->propertyOrderBy('created', 'DESC')
    ->execute();


  if (empty($results['node'])) {
    return;
  }

  return array('term' => taxonomy_term_load($tid), 'nodes' => implode(",", array_keys($results['node'])));
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_wiki_wiki_from_category_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
