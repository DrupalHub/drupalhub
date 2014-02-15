<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Video navigation'),
  'description' => t('Display navigation arrows to the next and last video.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'navigation_type' => '',
  ),
  'category' => t('DrupalHub videos'),
);

/**
 * Render callback.
 */
function drupalhub_videos_video_navigation_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return FALSE;
  }

  $nid_operator = $conf['navigation_type'] == 'next' ? '<' : '>';
  $order_type = $conf['navigation_type'] == 'next' ? 'DESC' : 'ASC';

  $query = new EntityFieldQuery();
  $results = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'youtube')
    ->propertyCondition('nid', $context->data->nid, $nid_operator)
    ->propertyOrderBy('created', $order_type)
    ->range(0, 1)
    ->execute();

  if (empty($results['node'])) {
    return;
  }


  $block = new stdClass();
  $block->module = 'drupalhub_videos';
  $block->title = '';
  // Temp for now. Until the deseing is finished.
  $block->content = l($conf['navigation_type'], 'node/' . reset($results['node'])->nid);
  return $block;
}

/**
 * Edit form.
 */
function drupalhub_videos_video_navigation_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['navigation_type'] = array(
    '#type' => 'select',
    '#title' => t('Navigation type.'),
    '#description' => t('Select the navigation type.'),
    '#options' => array(
      'next' => t('Next'),
      'back' => t('Back'),
    ),
    '#default_value' => $conf['navigation_type'],
  );
  return $form;
}

/**
 * Submit form.
 */
function drupalhub_videos_video_navigation_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
