<?php
/**
 * @file
 * drupalhub_group.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function drupalhub_group_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Project page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'project-page',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'project' => 'project',
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
  $display->layout = 'bootstrap_threecol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => array(
        'corner_location' => 'panel',
      ),
      'left' => array(
        'column_type' => 'col-lg',
        'column_size' => '4',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'middle' => array(
        'column_type' => 'col-lg',
        'column_size' => '4',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-lg',
        'column_size' => '4',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'bottom' => NULL,
    ),
    'top' => array(
      'style' => 'rounded_corners',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'd5b74a56-5ecb-468c-931f-d239d58fc148';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a2397f8a-44dd-4228-a5f0-e35b1a083b1d';
    $pane->panel = 'left';
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
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a2397f8a-44dd-4228-a5f0-e35b1a083b1d';
    $display->content['new-a2397f8a-44dd-4228-a5f0-e35b1a083b1d'] = $pane;
    $display->panels['left'][0] = 'new-a2397f8a-44dd-4228-a5f0-e35b1a083b1d';
    $pane = new stdClass();
    $pane->pid = 'new-403b9acd-3d93-443c-9eb7-b370148dc5a0';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_rating';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'vud',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '403b9acd-3d93-443c-9eb7-b370148dc5a0';
    $display->content['new-403b9acd-3d93-443c-9eb7-b370148dc5a0'] = $pane;
    $display->panels['left'][1] = 'new-403b9acd-3d93-443c-9eb7-b370148dc5a0';
    $pane = new stdClass();
    $pane->pid = 'new-3d11beea-e895-40da-9916-af0322e5ae01';
    $pane->panel = 'left';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'long',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3d11beea-e895-40da-9916-af0322e5ae01';
    $display->content['new-3d11beea-e895-40da-9916-af0322e5ae01'] = $pane;
    $display->panels['left'][2] = 'new-3d11beea-e895-40da-9916-af0322e5ae01';
    $pane = new stdClass();
    $pane->pid = 'new-dd1d2a35-43fe-4976-a5e9-d21ff6d0ceab';
    $pane->panel = 'left';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Published by:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'dd1d2a35-43fe-4976-a5e9-d21ff6d0ceab';
    $display->content['new-dd1d2a35-43fe-4976-a5e9-d21ff6d0ceab'] = $pane;
    $display->panels['left'][3] = 'new-dd1d2a35-43fe-4976-a5e9-d21ff6d0ceab';
    $pane = new stdClass();
    $pane->pid = 'new-c0bd80c4-a9dc-40a9-afef-8649ac09f7f6';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:og_group_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Author is in groups:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'c0bd80c4-a9dc-40a9-afef-8649ac09f7f6';
    $display->content['new-c0bd80c4-a9dc-40a9-afef-8649ac09f7f6'] = $pane;
    $display->panels['left'][4] = 'new-c0bd80c4-a9dc-40a9-afef-8649ac09f7f6';
    $pane = new stdClass();
    $pane->pid = 'new-e4d42ff5-ffd1-44bc-a898-9b169e9ad04d';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'link_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => 'Related links',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'e4d42ff5-ffd1-44bc-a898-9b169e9ad04d';
    $display->content['new-e4d42ff5-ffd1-44bc-a898-9b169e9ad04d'] = $pane;
    $display->panels['left'][5] = 'new-e4d42ff5-ffd1-44bc-a898-9b169e9ad04d';
    $pane = new stdClass();
    $pane->pid = 'new-422b0f9c-7995-4c95-8234-4e32edf731cc';
    $pane->panel = 'middle';
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
      'override_title_text' => 'Details',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '422b0f9c-7995-4c95-8234-4e32edf731cc';
    $display->content['new-422b0f9c-7995-4c95-8234-4e32edf731cc'] = $pane;
    $display->panels['middle'][0] = 'new-422b0f9c-7995-4c95-8234-4e32edf731cc';
    $pane = new stdClass();
    $pane->pid = 'new-36702ef7-33f4-4f16-bb4e-05f609c408c2';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_gallery_cropimage';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'galleryformatter_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'slide_style' => 'sidebar_right',
        'thumb_style' => 'thumbnail_retina',
        'style' => 'Greenarrows',
        'linking_method' => 'show_full_link',
        'link_to_full' => 1,
        'link_to_full_style' => '0',
        'modal' => 'colorbox',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '36702ef7-33f4-4f16-bb4e-05f609c408c2';
    $display->content['new-36702ef7-33f4-4f16-bb4e-05f609c408c2'] = $pane;
    $display->panels['right'][0] = 'new-36702ef7-33f4-4f16-bb4e-05f609c408c2';
    $pane = new stdClass();
    $pane->pid = 'new-b72330cd-8103-4f0d-b869-1cf056e68f15';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_videos';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'video_embed_field',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'video_style' => 'right_sidebar',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b72330cd-8103-4f0d-b869-1cf056e68f15';
    $display->content['new-b72330cd-8103-4f0d-b869-1cf056e68f15'] = $pane;
    $display->panels['right'][1] = 'new-b72330cd-8103-4f0d-b869-1cf056e68f15';
    $pane = new stdClass();
    $pane->pid = 'new-1692301a-5d80-491d-bc09-49b3a27518f8';
    $pane->panel = 'top';
    $pane->type = 'views_panes';
    $pane->subtype = 'group_banners-panel_pane_3';
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
    $pane->uuid = '1692301a-5d80-491d-bc09-49b3a27518f8';
    $display->content['new-1692301a-5d80-491d-bc09-49b3a27518f8'] = $pane;
    $display->panels['top'][0] = 'new-1692301a-5d80-491d-bc09-49b3a27518f8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Group page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'group-page',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'drupalhub_group' => 'drupalhub_group',
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
  $display->layout = 'drupalhub_9_3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'left' => array(
        'column_type' => 'col-lg',
        'column_size' => '4',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'middle' => array(
        'column_type' => 'col-lg',
        'column_size' => '4',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'right' => array(
        'column_type' => 'col-lg',
        'column_size' => '4',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'bottom' => NULL,
      'first' => NULL,
      'second' => NULL,
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'middle' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
    'top' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '96bd3b77-8434-4832-9998-724f95610b9f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-17493b67-9307-4050-8382-1b753b4f2f9b';
    $pane->panel = 'first';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_of_group-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '17493b67-9307-4050-8382-1b753b4f2f9b';
    $display->content['new-17493b67-9307-4050-8382-1b753b4f2f9b'] = $pane;
    $display->panels['first'][0] = 'new-17493b67-9307-4050-8382-1b753b4f2f9b';
    $pane = new stdClass();
    $pane->pid = 'new-bb0f6f4b-af55-4081-98b4-38fe0be52153';
    $pane->panel = 'first';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_of_group-panel_pane_4';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bb0f6f4b-af55-4081-98b4-38fe0be52153';
    $display->content['new-bb0f6f4b-af55-4081-98b4-38fe0be52153'] = $pane;
    $display->panels['first'][1] = 'new-bb0f6f4b-af55-4081-98b4-38fe0be52153';
    $pane = new stdClass();
    $pane->pid = 'new-e27c78d7-1a66-4964-a21c-2c00cb720756';
    $pane->panel = 'first';
    $pane->type = 'views_panes';
    $pane->subtype = 'group_banners-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e27c78d7-1a66-4964-a21c-2c00cb720756';
    $display->content['new-e27c78d7-1a66-4964-a21c-2c00cb720756'] = $pane;
    $display->panels['first'][2] = 'new-e27c78d7-1a66-4964-a21c-2c00cb720756';
    $pane = new stdClass();
    $pane->pid = 'new-64cb3180-8f80-4dfc-a5e0-629d1d8375f7';
    $pane->panel = 'second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_group_score';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'vud',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '64cb3180-8f80-4dfc-a5e0-629d1d8375f7';
    $display->content['new-64cb3180-8f80-4dfc-a5e0-629d1d8375f7'] = $pane;
    $display->panels['second'][0] = 'new-64cb3180-8f80-4dfc-a5e0-629d1d8375f7';
    $pane = new stdClass();
    $pane->pid = 'new-76ba1f26-aaca-40b3-a0e5-22961e280ab9';
    $pane->panel = 'second';
    $pane->type = 'views';
    $pane->subtype = 'og_members';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'context' => array(
        0 => 'argument_entity_id:node_1.nid',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '76ba1f26-aaca-40b3-a0e5-22961e280ab9';
    $display->content['new-76ba1f26-aaca-40b3-a0e5-22961e280ab9'] = $pane;
    $display->panels['second'][1] = 'new-76ba1f26-aaca-40b3-a0e5-22961e280ab9';
    $pane = new stdClass();
    $pane->pid = 'new-7832d8d7-9f9d-4081-a099-7815375b4f7a';
    $pane->panel = 'second';
    $pane->type = 'views_panes';
    $pane->subtype = 'group_banners-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7832d8d7-9f9d-4081-a099-7815375b4f7a';
    $display->content['new-7832d8d7-9f9d-4081-a099-7815375b4f7a'] = $pane;
    $display->panels['second'][2] = 'new-7832d8d7-9f9d-4081-a099-7815375b4f7a';
    $pane = new stdClass();
    $pane->pid = 'new-013c0a58-005f-4e55-8dc9-99703e7bd08f';
    $pane->panel = 'second';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '013c0a58-005f-4e55-8dc9-99703e7bd08f';
    $display->content['new-013c0a58-005f-4e55-8dc9-99703e7bd08f'] = $pane;
    $display->panels['second'][3] = 'new-013c0a58-005f-4e55-8dc9-99703e7bd08f';
    $pane = new stdClass();
    $pane->pid = 'new-9d6e9dac-13a1-452d-a11c-9a136d93de81';
    $pane->panel = 'second';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_of_group-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'rounded_corners',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '9d6e9dac-13a1-452d-a11c-9a136d93de81';
    $display->content['new-9d6e9dac-13a1-452d-a11c-9a136d93de81'] = $pane;
    $display->panels['second'][4] = 'new-9d6e9dac-13a1-452d-a11c-9a136d93de81';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  return $export;
}
