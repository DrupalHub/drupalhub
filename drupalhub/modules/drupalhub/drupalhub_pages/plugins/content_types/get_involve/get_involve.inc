<?php
/**
 * @file
 * Ctools plugin file for getting involve with the community.
 */

$plugin = array(
  'title' => t('Get involve'),
  'description' => t('Get involve with Drupal Israel community.'),
  'category' => t('DrupalHub pages'),
);

function drupalhub_pages_get_involve_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = '';

  $places = array(
    'facebook' => array('title' => t('Facebook'), 'href' => 'https://www.facebook.com/groups/drupalil'),
    'gplus' => array('title' => t('Google plus'), 'href' => 'https://plus.google.com/101605691320645002342'),
    'twitter' => array('title' => t('Twitter'), 'href' => 'http://twitter.com/Drupalil'),
    'github' => array('title' => t('Github'), 'href' => 'http://github.com/roysegall/drupalhub'),
    'instagram' => array('title' => t('Instagram'), 'href' => 'http://instagram.com//drupalhub'),
    'youtube' => array('title' => t('Yotube'), 'href' => 'http://www.youtube.com/channel/UCJe3SCokovJBxxe-etjWhtA'),
  );

  $items = array();
  $path = drupal_get_path('module', 'drupalhub_pages') . '/plugins/content_types/get_involve/pictures/';

  foreach ($places as $type => $info) {
    $items[] = theme('image', array('path' => $path . $type .'.png')) . l($info['title'], $info['href']);
  }

  $block->content = theme('item_list', array('items' => $items, 'attributes' => array('class' => 'social-links')));

  return $block;
}

/**
 * Implementation of a content_type edit form
 */
function drupalhub_pages_get_involve_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Implementation of a content_type edit form submit callback
 */
function drupalhub_pages_get_involve_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}
