<?php
/**
 * @file
 * drupalhub_notify.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drupalhub_notify_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function drupalhub_notify_default_message_type() {
  $items = array();
  $items['comment_on_followed_node'] = entity_import('message_type', '{
    "name" : "comment_on_followed_node",
    "description" : "Comment on followed node",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : {
      "en" : [
        {
          "value" : "Hello [message:user:name] - new comment",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EHello [message:user:name] - new comment\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Hello [message:user:name],\\r\\n\\r\\n\\u003Ca href=\\u0022[message:field-user:url]\\u0022\\u003E[message:field-user:name]\\u003C\\/a\\u003E has made a comment on \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E.",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EHello [message:user:name],\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Ca href=\\u0022[message:field-user:url]\\u0022\\u003E[message:field-user:name]\\u003C\\/a\\u003E has made a comment on \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n"
        }
      ],
      "he" : [
        {
          "value" : "\\u05e9\\u05dc\\u05d5\\u05dd [message:user:name] - \\u05ea\\u05d2\\u05d5\\u05d1\\u05d4 \\u05d7\\u05d3\\u05e9\\u05d4",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E\\u05e9\\u05dc\\u05d5\\u05dd [message:user:name] - \\u05ea\\u05d2\\u05d5\\u05d1\\u05d4 \\u05d7\\u05d3\\u05e9\\u05d4\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u05e9\\u05dc\\u05d5\\u05dd [message:user:name],\\n\\n\\u003Ca href=\\u0022[message:field-user:url]\\u0022\\u003E[message:field-user:name]\\u003C\\/a\\u003E \\u05d4\\u05d2\\u05d9\\u05d1 \\u05e2\\u05dc \\u003Ca href=\\u0022[message:field-node:url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E.",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E\\u05e9\\u05dc\\u05d5\\u05dd [message:user:name],\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-user:name]\\u003C\\/a\\u003E \\u05d4\\u05d2\\u05d9\\u05d1 \\u05e2\\u05dc \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-node:title]\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_video'] = entity_import('message_type', '{
    "name" : "new_video",
    "description" : "New video",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003ENew video has submitted to [site:name]\\u003C\\/p\\u003E",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003ENew video has submitted to [site:name]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "the user [message:field_user] created a new video.\\r\\n\\r\\nThe site administrator define you can approve video. Please review this video and approve\\/decline the video.\\r\\n\\r\\n\\u003Ca href=\\u0022[message:field-node:edit-url]\\u0022\\u003EEdit the video\\u003C\\/a\\u003E \\u003Ca href=\\u0022[message:field-node:url:absolute]\\u0022\\u003EView the video\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003Ethe user [message:field_user] created a new video.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EThe site administrator define you can approve video. Please review this video and approve\\/decline the video.\\u003C\\/p\\u003E\\n\\u003Cp\\u003E\\u003Ca href=\\u0022[message:field-node:edit-url]\\u0022\\u003EEdit the video\\u003C\\/a\\u003E \\u003Ca href=\\u0022[message:field-node:url:absolute]\\u0022\\u003EView the video\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
