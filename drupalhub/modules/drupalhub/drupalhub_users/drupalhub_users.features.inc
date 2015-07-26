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
 * Implements hook_image_default_styles().
 */
function drupalhub_users_image_default_styles() {
  $styles = array();

  // Exported image style: small.
  $styles['small'] = array(
    'name' => 'small',
    'label' => 'Small',
    'effects' => array(
      1 => array(
        'label' => 'Resize',
        'help' => 'Resizing will make images an exact set of dimensions. This may cause images to be stretched or shrunk disproportionately.',
        'effect callback' => 'retina_images_image_resize_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'retina_images_image_resize_form',
        'summary theme' => 'retina_images_image_resize_summary',
        'module' => 'image',
        'name' => 'image_resize',
        'data' => array(
          'width' => 32,
          'height' => 32,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
    "language" : "he",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022@{message:field-comment:url}\\u0022\\u003ECommented\\u003C\\/a\\u003E to the @{message:field-comment:node:content-type:name}\\u0026nbsp;\\u003Ca href=\\u0022@{message:field-comment:node:decouple-url}\\u0022\\u003E@{message:field-comment:node:title}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022@{message:field-comment:url}\\u0022\\u003ECommented\\u003C\\/a\\u003E to the @{message:field-comment:node:content-type:name}\\u00a0\\u003Ca href=\\u0022@{message:field-comment:node:decouple-url}\\u0022\\u003E@{message:field-comment:node:title}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
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
    "language" : "he",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003ECreated the @{message:field-node:content-type:name}\\u0026nbsp;\\u003Ca href=\\u0022@{message:field-node:decouple-url}\\u0022\\u003E@{message:field-node:title}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003ECreated the @{message:field-node:content-type:name}\\u00a0\\u003Ca href=\\u0022@{message:field-node:decouple-url}\\u0022\\u003E@{message:field-node:title}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
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
    "language" : "he",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "Joined DrupalHub",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EJoined DrupalHub\\u003C\\/p\\u003E\\n"
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
    "language" : "he",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E@action\\u0026nbsp;for the @type\\u0026nbsp;\\u003Ca href=\\u0022@uri\\u0022\\u003E@label\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E@action\\u00a0for the @type\\u00a0\\u003Ca href=\\u0022@uri\\u0022\\u003E@label\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
