<?php

$plugin = array(
  'title' => t('Node meta tags'),
  'description' => t('Display meta tags like created time and the owner with font awesome'),
  'category' => t('DrupalHub core'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'hook theme' => 'drupalhub_core_node_metatags_content_type_theme',
);

function drupalhub_core_node_metatags_content_type_render($subtype, $conf, $args, $context) {
  $wrapper = entity_metadata_wrapper('node', $context->data);

  $terms = array();

  if ($wrapper->field_tags) {
    foreach ($wrapper->field_tags as $tag) {
      $uri = entity_uri('taxonomy_term', $tag->value());
      $terms[] = l($tag->label(), $uri['path']);
    }
  }

  $uri = entity_uri('user', $wrapper->value());
  $block = new stdClass();

  $params = array(
    'author' => l($wrapper->author->label(), $uri['path']),
    'tags' => implode(" " , $terms),
    'time' => format_date($wrapper->created->value()),
    'vote' => '',
    'follow' => '',
  );

  if ($wrapper->getBundle() == 'question') {
    $params['vote'] = theme('vud_drupalhub_vud', array('entity_type' => 'node', 'entity_id' => $context->data->nid));
    $flag_link = flag_create_link('node_follow', $context->data->nid);

    $flag = flag_get_flag('node_follow');

    if ($flag->access($context->data->nid) && ($flag->is_flagged($context->data->nid) || $flag->access($context->data->nid, 'flag'))) {
      $symbol = !$flag->is_flagged($context->data->nid) ? '<i class="fa fa-square-o"></i>' : '<i class="fa fa-check-square-o"></i>';

      $params['follow'] = $symbol . $flag_link;
    }

  }

  $block->content = theme('node_metatags', $params);
  return $block;
}

/**
 * Form settings.
 */
function drupalhub_core_node_metatags_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_core_node_metatags_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

function drupalhub_core_node_metatags_content_type_theme(&$theme, $plugin) {
  $theme['node_metatags'] = array(
    'path' => $plugin['path'],
    'template' => 'node-metatags',
  );
}

