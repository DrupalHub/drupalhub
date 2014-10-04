<?php
/**
 * @file
 * drupalhub_wiki.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function drupalhub_wiki_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Wiki page',
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
      1 => array(
        'identifier' => 'Taxonomy term from Node (on Node: Category [field_category])',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_category-node-taxonomy_term',
        'delta' => 0,
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
              'wiki' => 'wiki',
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
  $display->layout = 'drupalhub_wiki';
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
      'main_top' => NULL,
      'category_1' => NULL,
      'category_2' => NULL,
      'category_3' => NULL,
      'second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cc9925f9-79bc-471b-ab4b-436e2df2ff2d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-66e0d0f5-7a2b-4045-af1b-d039cff1912f';
    $pane->panel = 'main_top';
    $pane->type = 'links';
    $pane->subtype = 'links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
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
    $pane->uuid = '66e0d0f5-7a2b-4045-af1b-d039cff1912f';
    $display->content['new-66e0d0f5-7a2b-4045-af1b-d039cff1912f'] = $pane;
    $display->panels['main_top'][0] = 'new-66e0d0f5-7a2b-4045-af1b-d039cff1912f';
    $pane = new stdClass();
    $pane->pid = 'new-36ddeffb-4d5a-424f-a0bf-c414a33eca77';
    $pane->panel = 'main_top';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '36ddeffb-4d5a-424f-a0bf-c414a33eca77';
    $display->content['new-36ddeffb-4d5a-424f-a0bf-c414a33eca77'] = $pane;
    $display->panels['main_top'][1] = 'new-36ddeffb-4d5a-424f-a0bf-c414a33eca77';
    $pane = new stdClass();
    $pane->pid = 'new-0e9720c7-e43d-4a05-8505-0f24be46c250';
    $pane->panel = 'main_top';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0e9720c7-e43d-4a05-8505-0f24be46c250';
    $display->content['new-0e9720c7-e43d-4a05-8505-0f24be46c250'] = $pane;
    $display->panels['main_top'][2] = 'new-0e9720c7-e43d-4a05-8505-0f24be46c250';
    $pane = new stdClass();
    $pane->pid = 'new-5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $pane->panel = 'main_top';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $display->content['new-5a225a5e-c342-49f4-86e9-87edc792ecb8'] = $pane;
    $display->panels['main_top'][3] = 'new-5a225a5e-c342-49f4-86e9-87edc792ecb8';
    $pane = new stdClass();
    $pane->pid = 'new-a69beb2d-1387-43da-8673-d3850142d632';
    $pane->panel = 'main_top';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'clearfix',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'a69beb2d-1387-43da-8673-d3850142d632';
    $display->content['new-a69beb2d-1387-43da-8673-d3850142d632'] = $pane;
    $display->panels['main_top'][4] = 'new-a69beb2d-1387-43da-8673-d3850142d632';
    $pane = new stdClass();
    $pane->pid = 'new-100fdcfb-4e76-4b9f-be0e-997bd235790e';
    $pane->panel = 'main_top';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '100fdcfb-4e76-4b9f-be0e-997bd235790e';
    $display->content['new-100fdcfb-4e76-4b9f-be0e-997bd235790e'] = $pane;
    $display->panels['main_top'][5] = 'new-100fdcfb-4e76-4b9f-be0e-997bd235790e';
    $pane = new stdClass();
    $pane->pid = 'new-3a1f8f78-053e-488a-a8da-02ae53f725f7';
    $pane->panel = 'main_top';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '3a1f8f78-053e-488a-a8da-02ae53f725f7';
    $display->content['new-3a1f8f78-053e-488a-a8da-02ae53f725f7'] = $pane;
    $display->panels['main_top'][6] = 'new-3a1f8f78-053e-488a-a8da-02ae53f725f7';
    $pane = new stdClass();
    $pane->pid = 'new-d795f590-ca63-43a6-af05-a8747b8a80a8';
    $pane->panel = 'main_top';
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'd795f590-ca63-43a6-af05-a8747b8a80a8';
    $display->content['new-d795f590-ca63-43a6-af05-a8747b8a80a8'] = $pane;
    $display->panels['main_top'][7] = 'new-d795f590-ca63-43a6-af05-a8747b8a80a8';
    $pane = new stdClass();
    $pane->pid = 'new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $pane->panel = 'main_top';
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
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = 'f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $display->content['new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8'] = $pane;
    $display->panels['main_top'][8] = 'new-f2a6e3df-a0eb-4720-8c1c-2d93761c97b8';
    $pane = new stdClass();
    $pane->pid = 'new-ffc35975-02f7-404a-8155-f94e3ff158b5';
    $pane->panel = 'second';
    $pane->type = 'search_box';
    $pane->subtype = 'search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-PmCNkClmE5N8qep5BM9f2o17XyiCvlYfkryCZmevYgA',
      'form_token' => 'hSY7W6EPN3jrZw1NFTSFAQgK0NGB6iFy_AUhAFK6xok',
      'form_id' => 'drupalhub_wiki_search_box_content_type_edit_form',
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
    $pane->uuid = 'ffc35975-02f7-404a-8155-f94e3ff158b5';
    $display->content['new-ffc35975-02f7-404a-8155-f94e3ff158b5'] = $pane;
    $display->panels['second'][0] = 'new-ffc35975-02f7-404a-8155-f94e3ff158b5';
    $pane = new stdClass();
    $pane->pid = 'new-cd9e92af-f6b0-4800-81be-d81f834fc813';
    $pane->panel = 'second';
    $pane->type = 'wikipedia_terms';
    $pane->subtype = 'wikipedia_terms';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'relationship_entity_from_field:field_category-node-taxonomy_term_1',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-OdbghHBdZeQ98-aSgL2lERW1FseiDhPnH1PV395M3ho',
      'form_token' => '7AW2aE6Em8M85TT6hZMbiJ-VxZfUcbkJiEa9hpxRBU8',
      'form_id' => 'drupalhub_wiki_wikipedia_terms_content_type_edit_form',
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
    $pane->uuid = 'cd9e92af-f6b0-4800-81be-d81f834fc813';
    $display->content['new-cd9e92af-f6b0-4800-81be-d81f834fc813'] = $pane;
    $display->panels['second'][1] = 'new-cd9e92af-f6b0-4800-81be-d81f834fc813';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_6'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function drupalhub_wiki_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'drupalhub_wiki';
  $page->task = 'page';
  $page->admin_title = 'DrupalHub wiki';
  $page->admin_description = '';
  $page->path = 'documentation';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_drupalhub_wiki_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'drupalhub_wiki';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'drupalhub_wiki';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main_top' => NULL,
      'category_1' => NULL,
      'category_2' => NULL,
      'category_3' => NULL,
      'second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '08be3e0b-8ac3-4c73-9982-9e3cd64c2358';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-acb5b631-44f9-49a4-848c-0248bf158034';
    $pane->panel = 'category_1';
    $pane->type = 'wiki_from_category';
    $pane->subtype = 'wiki_from_category';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'position' => '0',
      'form_build_id' => 'form-RralD7K5I2tUricHMJkh0smmAVZQOfY1JuiOyibTdtg',
      'form_token' => 'NFJEVj0QFOowf_VfcONN4XM9HElUDwjmcY8K-qFKR1w',
      'form_id' => 'drupalhub_wiki_wiki_from_category_content_type_edit_form',
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
    $pane->uuid = 'acb5b631-44f9-49a4-848c-0248bf158034';
    $display->content['new-acb5b631-44f9-49a4-848c-0248bf158034'] = $pane;
    $display->panels['category_1'][0] = 'new-acb5b631-44f9-49a4-848c-0248bf158034';
    $pane = new stdClass();
    $pane->pid = 'new-e7f24484-9b57-40ac-9594-0b836c70a283';
    $pane->panel = 'category_2';
    $pane->type = 'wiki_from_category';
    $pane->subtype = 'wiki_from_category';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'position' => '1',
      'form_build_id' => 'form-160ymvypxbDbm4PizfuOIuEQKxoWSEn4fC5qMWdD8K4',
      'form_token' => 'NFJEVj0QFOowf_VfcONN4XM9HElUDwjmcY8K-qFKR1w',
      'form_id' => 'drupalhub_wiki_wiki_from_category_content_type_edit_form',
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
    $pane->uuid = 'e7f24484-9b57-40ac-9594-0b836c70a283';
    $display->content['new-e7f24484-9b57-40ac-9594-0b836c70a283'] = $pane;
    $display->panels['category_2'][0] = 'new-e7f24484-9b57-40ac-9594-0b836c70a283';
    $pane = new stdClass();
    $pane->pid = 'new-64f2a3ea-f104-421c-8548-5cf7bfe1ca1c';
    $pane->panel = 'category_3';
    $pane->type = 'wiki_from_category';
    $pane->subtype = 'wiki_from_category';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'position' => '2',
      'form_build_id' => 'form-pjCLXTbPl0K8Xdrk3v1H4S0klJo7e1VhCDulhXeu5Gk',
      'form_token' => 'NFJEVj0QFOowf_VfcONN4XM9HElUDwjmcY8K-qFKR1w',
      'form_id' => 'drupalhub_wiki_wiki_from_category_content_type_edit_form',
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
    $pane->uuid = '64f2a3ea-f104-421c-8548-5cf7bfe1ca1c';
    $display->content['new-64f2a3ea-f104-421c-8548-5cf7bfe1ca1c'] = $pane;
    $display->panels['category_3'][0] = 'new-64f2a3ea-f104-421c-8548-5cf7bfe1ca1c';
    $pane = new stdClass();
    $pane->pid = 'new-af2b47bf-980c-4ecc-bd7b-2a7308ae5367';
    $pane->panel = 'main_top';
    $pane->type = 'links';
    $pane->subtype = 'links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'tabs',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'af2b47bf-980c-4ecc-bd7b-2a7308ae5367';
    $display->content['new-af2b47bf-980c-4ecc-bd7b-2a7308ae5367'] = $pane;
    $display->panels['main_top'][0] = 'new-af2b47bf-980c-4ecc-bd7b-2a7308ae5367';
    $pane = new stdClass();
    $pane->pid = 'new-78b38779-ce03-4749-bc53-2bdefd857471';
    $pane->panel = 'main_top';
    $pane->type = 'wiki_description';
    $pane->subtype = 'wiki_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
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
    $pane->uuid = '78b38779-ce03-4749-bc53-2bdefd857471';
    $display->content['new-78b38779-ce03-4749-bc53-2bdefd857471'] = $pane;
    $display->panels['main_top'][1] = 'new-78b38779-ce03-4749-bc53-2bdefd857471';
    $pane = new stdClass();
    $pane->pid = 'new-076412e8-4bf9-4344-a1e2-2a96893060c9';
    $pane->panel = 'main_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'last_wiki_nodes-panel_pane_1';
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
    $pane->uuid = '076412e8-4bf9-4344-a1e2-2a96893060c9';
    $display->content['new-076412e8-4bf9-4344-a1e2-2a96893060c9'] = $pane;
    $display->panels['main_top'][2] = 'new-076412e8-4bf9-4344-a1e2-2a96893060c9';
    $pane = new stdClass();
    $pane->pid = 'new-9e27e616-f4b7-4ef8-b051-7f173e30abf1';
    $pane->panel = 'second';
    $pane->type = 'search_box';
    $pane->subtype = 'search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-jAbuzVp4453W4EyQiGT2C71z34TcnFzg0GpEcwPKmBo',
      'form_token' => '-A9G4zpYYH2LQ5ELFybMH7kAMThVvTZB9JOLI20Ee48',
      'form_id' => 'drupalhub_wiki_search_box_content_type_edit_form',
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
    $pane->uuid = '9e27e616-f4b7-4ef8-b051-7f173e30abf1';
    $display->content['new-9e27e616-f4b7-4ef8-b051-7f173e30abf1'] = $pane;
    $display->panels['second'][0] = 'new-9e27e616-f4b7-4ef8-b051-7f173e30abf1';
    $pane = new stdClass();
    $pane->pid = 'new-472fa41e-8cca-4814-a73c-abba383a3aec';
    $pane->panel = 'second';
    $pane->type = 'wikipedia_terms';
    $pane->subtype = 'wikipedia_terms';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-zligi4plCYqODEey49caKnQEUOxDmM4mkd-MFE5j04g',
      'form_token' => '7AW2aE6Em8M85TT6hZMbiJ-VxZfUcbkJiEa9hpxRBU8',
      'form_id' => 'drupalhub_wiki_wikipedia_terms_content_type_edit_form',
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
    $pane->uuid = '472fa41e-8cca-4814-a73c-abba383a3aec';
    $display->content['new-472fa41e-8cca-4814-a73c-abba383a3aec'] = $pane;
    $display->panels['second'][1] = 'new-472fa41e-8cca-4814-a73c-abba383a3aec';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['drupalhub_wiki'] = $page;

  return $pages;

}
