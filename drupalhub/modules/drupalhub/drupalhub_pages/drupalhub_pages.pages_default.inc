<?php
/**
 * @file
 * drupalhub_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function drupalhub_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Blog page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'User from Node (on node.node_author)',
        'keyword' => 'user',
        'name' => 'entity_from_schema:uid-node-user',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'blog' => 'blog',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'drupalhub_blog';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'bottom' => NULL,
      'top_first' => NULL,
      'top_second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cc9925f9-79bc-471b-ab4b-436e2df2ff2d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d795f590-ca63-43a6-af05-a8747b8a80a8';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'idea_comments-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd795f590-ca63-43a6-af05-a8747b8a80a8';
    $display->content['new-d795f590-ca63-43a6-af05-a8747b8a80a8'] = $pane;
    $display->panels['bottom'][0] = 'new-d795f590-ca63-43a6-af05-a8747b8a80a8';
    $pane = new stdClass();
    $pane->pid = 'new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $pane->panel = 'bottom';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $display->content['new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8'] = $pane;
    $display->panels['bottom'][1] = 'new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $pane = new stdClass();
    $pane->pid = 'new-0e9720c7-e43d-4a05-8505-0f24be46c250';
    $pane->panel = 'top_first';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0e9720c7-e43d-4a05-8505-0f24be46c250';
    $display->content['new-0e9720c7-e43d-4a05-8505-0f24be46c250'] = $pane;
    $display->panels['top_first'][0] = 'new-0e9720c7-e43d-4a05-8505-0f24be46c250';
    $pane = new stdClass();
    $pane->pid = 'new-5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $pane->panel = 'top_first';
    $pane->type = 'node_metatags';
    $pane->subtype = 'node_metatags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'form_build_id' => 'form-03YJIQhPNIizsGdR2g_JT20XAoOywSIz8wna44HgA6k',
      'form_token' => 'yjPS_pCxPKq-MJ45c1h8ssdKtacY4PX1bi8yxrLmtgM',
      'form_id' => 'drupalhub_core_node_metatags_content_type_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $display->content['new-5a225a5e-c342-49f4-86e9-87edc792ecb8'] = $pane;
    $display->panels['top_first'][1] = 'new-5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $pane = new stdClass();
    $pane->pid = 'new-a69beb2d-1387-43da-8673-d3850142d632';
    $pane->panel = 'top_first';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a69beb2d-1387-43da-8673-d3850142d632';
    $display->content['new-a69beb2d-1387-43da-8673-d3850142d632'] = $pane;
    $display->panels['top_first'][2] = 'new-a69beb2d-1387-43da-8673-d3850142d632';
    $pane = new stdClass();
    $pane->pid = 'new-100fdcfb-4e76-4b9f-be0e-997bd235790e';
    $pane->panel = 'top_first';
    $pane->type = 'increase_count';
    $pane->subtype = 'increase_count';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '100fdcfb-4e76-4b9f-be0e-997bd235790e';
    $display->content['new-100fdcfb-4e76-4b9f-be0e-997bd235790e'] = $pane;
    $display->panels['top_first'][3] = 'new-100fdcfb-4e76-4b9f-be0e-997bd235790e';
    $pane = new stdClass();
    $pane->pid = 'new-36ddeffb-4d5a-424f-a0bf-c414a33eca77';
    $pane->panel = 'top_second';
    $pane->type = 'user_picture';
    $pane->subtype = 'user_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'relationship_entity_from_schema:uid-node-user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-OkUyV8PXezkuNEmm3xxIhPiENH8s1K27TLLplxQAC-s',
      'form_token' => '_ePfOZb6PxOzqb1nZeIUJaydQ3Ad2y3hqndGtOmxcMg',
      'form_id' => 'drupalhub_users_user_picture_content_type_edit_form',
      'op' => 'Finish',
      'image_styles' => 'thumbnail_retina',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '36ddeffb-4d5a-424f-a0bf-c414a33eca77';
    $display->content['new-36ddeffb-4d5a-424f-a0bf-c414a33eca77'] = $pane;
    $display->panels['top_second'][0] = 'new-36ddeffb-4d5a-424f-a0bf-c414a33eca77';
    $pane = new stdClass();
    $pane->pid = 'new-3a1f8f78-053e-488a-a8da-02ae53f725f7';
    $pane->panel = 'top_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_about';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_entity_from_schema:uid-node-user_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3a1f8f78-053e-488a-a8da-02ae53f725f7';
    $display->content['new-3a1f8f78-053e-488a-a8da-02ae53f725f7'] = $pane;
    $display->panels['top_second'][1] = 'new-3a1f8f78-053e-488a-a8da-02ae53f725f7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_5'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function drupalhub_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front_page';
  $page->task = 'page';
  $page->admin_title = 'Front page';
  $page->admin_description = '';
  $page->path = 'front';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_front_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '#block-system-main {
  width: 100% !important;
}',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'drupalhub_homepage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => array(
        'column_type' => 'col-lg',
        'column_size' => '3',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-lg',
        'column_size' => '8',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '1',
      ),
      'bottom' => NULL,
      'second' => array(
        'column_type' => 'col-sm',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'first' => array(
        'column_type' => 'col-sm',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'second-top' => NULL,
      'second-middle' => NULL,
      'first_left' => NULL,
      'fist_right' => NULL,
      'second-last' => NULL,
      'second_left' => NULL,
      'second_right' => NULL,
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'first' => array(
      'style' => 'drupalhub_region',
    ),
    'first_left' => array(
      'style' => '-1',
    ),
    'fist_right' => array(
      'style' => '-1',
    ),
    'second' => array(
      'style' => 'drupalhub_region',
    ),
    'second_left' => array(
      'style' => 'default',
    ),
    'second_right' => array(
      'style' => 'default',
    ),
    'second-last' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9002d792-6777-4fde-b083-3455d65e83e1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c08be55b-8548-4bc1-9628-572536a43b2e';
    $pane->panel = 'first_left';
    $pane->type = 'new_question';
    $pane->subtype = 'new_question';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 1,
      'override_title_text' => 'Help and support',
      'form_build_id' => 'form-QLeYSyBRhNF3xIuXqXJSK8Xfvl-YGh04mCQsrEUIB8o',
      'form_token' => '8_yse4_FfeeGyL5X8uPMYtr2sfl9Ygk-3nrHOrCDUVs',
      'form_id' => 'drupalhub_questions_new_question_content_type_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'clearfix',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c08be55b-8548-4bc1-9628-572536a43b2e';
    $display->content['new-c08be55b-8548-4bc1-9628-572536a43b2e'] = $pane;
    $display->panels['first_left'][0] = 'new-c08be55b-8548-4bc1-9628-572536a43b2e';
    $pane = new stdClass();
    $pane->pid = 'new-45565fc7-bff8-4186-b408-5b2de3de4c2e';
    $pane->panel = 'first_left';
    $pane->type = 'popular_tags';
    $pane->subtype = 'popular_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 1,
      'override_title_text' => 'Popular tags: ',
      'form_build_id' => 'form-vl9c7IKhYsqRoUoCLC4s5GEImPTcD6514KQQMWr6vWY',
      'form_token' => 'ALSupKa_8bpKXADDd45pPPxgB8r63z-lrY575QrakxQ',
      'form_id' => 'drupalhub_pages_popular_tags_content_type_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'clearfix',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '45565fc7-bff8-4186-b408-5b2de3de4c2e';
    $display->content['new-45565fc7-bff8-4186-b408-5b2de3de4c2e'] = $pane;
    $display->panels['first_left'][1] = 'new-45565fc7-bff8-4186-b408-5b2de3de4c2e';
    $pane = new stdClass();
    $pane->pid = 'new-aff4e697-4747-4475-bd7e-96bd2e0df875';
    $pane->panel = 'first_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'main_page_questions-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'aff4e697-4747-4475-bd7e-96bd2e0df875';
    $display->content['new-aff4e697-4747-4475-bd7e-96bd2e0df875'] = $pane;
    $display->panels['first_left'][2] = 'new-aff4e697-4747-4475-bd7e-96bd2e0df875';
    $pane = new stdClass();
    $pane->pid = 'new-c511cc13-0f70-45a0-b12c-544947a45b5a';
    $pane->panel = 'first_left';
    $pane->type = 'more';
    $pane->subtype = 'more';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'page' => 'questions',
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-rSiqk8ghUF3HHyuCdoqVSxNXkqrItZx1hk1p6ngN2aE',
      'form_token' => 'L3fzLQmKQ-hVpm7TXyT47ttHEtMVNKVpDE0UJJXyH20',
      'form_id' => 'drupalhub_core_more_content_type_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'c511cc13-0f70-45a0-b12c-544947a45b5a';
    $display->content['new-c511cc13-0f70-45a0-b12c-544947a45b5a'] = $pane;
    $display->panels['first_left'][3] = 'new-c511cc13-0f70-45a0-b12c-544947a45b5a';
    $pane = new stdClass();
    $pane->pid = 'new-7535806c-7fcb-4ea9-8c40-7c00fe95f7ec';
    $pane->panel = 'fist_right';
    $pane->type = 'views_panes';
    $pane->subtype = 'top_users-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'hidden-phone',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7535806c-7fcb-4ea9-8c40-7c00fe95f7ec';
    $display->content['new-7535806c-7fcb-4ea9-8c40-7c00fe95f7ec'] = $pane;
    $display->panels['fist_right'][0] = 'new-7535806c-7fcb-4ea9-8c40-7c00fe95f7ec';
    $pane = new stdClass();
    $pane->pid = 'new-f0566537-3a92-4e2e-93e5-84c56526807f';
    $pane->panel = 'second-last';
    $pane->type = 'service_provider';
    $pane->subtype = 'service_provider';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'hidden-xs',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f0566537-3a92-4e2e-93e5-84c56526807f';
    $display->content['new-f0566537-3a92-4e2e-93e5-84c56526807f'] = $pane;
    $display->panels['second-last'][0] = 'new-f0566537-3a92-4e2e-93e5-84c56526807f';
    $pane = new stdClass();
    $pane->pid = 'new-89bc83fa-12b3-4930-94df-c21443cf8ef0';
    $pane->panel = 'second-top';
    $pane->type = 'views_panes';
    $pane->subtype = 'front_page_blogs-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '89bc83fa-12b3-4930-94df-c21443cf8ef0';
    $display->content['new-89bc83fa-12b3-4930-94df-c21443cf8ef0'] = $pane;
    $display->panels['second-top'][0] = 'new-89bc83fa-12b3-4930-94df-c21443cf8ef0';
    $pane = new stdClass();
    $pane->pid = 'new-62dd70be-40b1-4a18-91eb-3cba3ff3b0fd';
    $pane->panel = 'second-top';
    $pane->type = 'more';
    $pane->subtype = 'more';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'page' => 'blogs',
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-TVAQIQnwBLRtmb-rk8FxibVOC1Bd5BkNku0GYC1oeDc',
      'form_token' => 'L3fzLQmKQ-hVpm7TXyT47ttHEtMVNKVpDE0UJJXyH20',
      'form_id' => 'drupalhub_core_more_content_type_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '62dd70be-40b1-4a18-91eb-3cba3ff3b0fd';
    $display->content['new-62dd70be-40b1-4a18-91eb-3cba3ff3b0fd'] = $pane;
    $display->panels['second-top'][1] = 'new-62dd70be-40b1-4a18-91eb-3cba3ff3b0fd';
    $pane = new stdClass();
    $pane->pid = 'new-0606616b-f496-4afa-8d0f-f41302317fe1';
    $pane->panel = 'second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'recommendation-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0606616b-f496-4afa-8d0f-f41302317fe1';
    $display->content['new-0606616b-f496-4afa-8d0f-f41302317fe1'] = $pane;
    $display->panels['second_left'][0] = 'new-0606616b-f496-4afa-8d0f-f41302317fe1';
    $pane = new stdClass();
    $pane->pid = 'new-b2093d4b-5cb2-4da3-9b33-4f797b5cb532';
    $pane->panel = 'second_right';
    $pane->type = 'drupal_of_the_month';
    $pane->subtype = 'drupal_of_the_month';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'node_id' => NULL,
      'form_build_id' => 'form-wRdOSddCpkxQ03f9Xmj0vXYL1DQioJaqJuGHxNK93TU',
      'form_token' => 'MI69j11nIJ_A288BsplGcDsCIGJQbgR7IWrwL9Ud2YU',
      'form_id' => 'drupalhub_pages_drupal_of_the_month_content_type_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b2093d4b-5cb2-4da3-9b33-4f797b5cb532';
    $display->content['new-b2093d4b-5cb2-4da3-9b33-4f797b5cb532'] = $pane;
    $display->panels['second_right'][0] = 'new-b2093d4b-5cb2-4da3-9b33-4f797b5cb532';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}
