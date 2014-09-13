<?php

$plugin = array(
  'title' => t('Video metadata'),
  'description' => t('Video metadata'),
  'category' => t('DrupalHub youtube'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'hook theme' => 'drupalhub_videos_video_metadata_content_type_theme',
);

function drupalhub_videos_video_metadata_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  // Basic setup.
  $wrapper = entity_metadata_wrapper('node', $context->data);
  $id = _video_embed_field_get_youtube_id($wrapper->field_address->video_url->value());
  $info = drupalhub_videos_get_metadata($id);

  // Calculate information.
  $user_uri = entity_uri('user', $wrapper->author->value());
  $description = preg_replace('@(?<!href="|src="|">)(https?:\/\/([-\w\.]+[-\w])+(:\d+)?(/([\w/_\.#-]*(\?\S+)?[^\.\s])?)?)@', '<a href="$1">$1</a>', $info['description']);
  $params = array(
    'title' => $wrapper->label(),
    'duration' => drupalhub_videos_youtube_metadata::durationToText($info),
    'description' => nl2br($description),
    'views' => $info['viewCount'],
    'uploader' => l($info['uploader'], 'http://youtube.com/' . $info['uploader']),
    'author' => l($wrapper->author->label(), $user_uri['path']),
  );

  $block->content = theme('video_information', $params);

  return $block;
}

/**
 * Form settings.
 */
function drupalhub_videos_video_metadata_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submitting the form and save the value of the form elements.
 */
function drupalhub_videos_video_metadata_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Delegating hook_theme().
 */
function drupalhub_videos_video_metadata_content_type_theme(&$theme, $plugin) {
  $theme['video_information'] = array(
    'path' => $plugin['path'],
    'template' => 'video-information',
  );
}
