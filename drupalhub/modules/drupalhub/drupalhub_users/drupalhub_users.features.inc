<?php
/**
 * @file
 * drupalhub_users.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drupalhub_users_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function drupalhub_users_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function drupalhub_users_default_message_type() {
  $items = array();
  $items['commented_to_node'] = entity_import('message_type', '{
    "name" : "commented_to_node",
    "description" : "Commented to node",
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
          "value" : "\\u003Cp\\u003ECommented to the node @{message:field-node:title}\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003ECommented to the node @{message:field-node:title}\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['created_node'] = entity_import('message_type', '{
    "name" : "created_node",
    "description" : "Created node",
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
          "value" : "\\u003Cp\\u003ECreated the node @{message:field-node:title}\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003ECreated the node @{message:field-node:title}\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['new_user'] = entity_import('message_type', '{
    "name" : "new_user",
    "description" : "New user",
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
          "value" : "The user \\u003Ca href=\\u0027@user-link\\u0027\\u003E@username\\u003C\\/a\\u003E joined DrupalHub",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EThe user \\u003Ca href=\\u0022@user-link\\u0022\\u003E@username\\u003C\\/a\\u003E joined DrupalHub\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['user_down_up_voted'] = entity_import('message_type', '{
    "name" : "user_down_up_voted",
    "description" : "User down\\/up voted",
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
          "value" : "\\u003Cp\\u003E@action\\u0026nbsp;for the @type\\u0026nbsp;@label\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E@action\\u00a0for the @type\\u00a0@label\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
