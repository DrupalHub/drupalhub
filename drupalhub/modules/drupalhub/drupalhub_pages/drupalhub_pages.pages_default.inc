<?php
/**
 * @file
 * drupalhub_pages.pages_default.inc
 */

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
      'first_left' => array(
        'column_type' => 'col-lg',
        'column_size' => '6',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'fist_right' => array(
        'column_type' => 'col-lg',
        'column_size' => '6',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'second' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'second_left' => array(
        'column_type' => 'col-lg',
        'column_size' => '6',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'second_right' => array(
        'column_type' => 'col-lg',
        'column_size' => '6',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'first' => array(
        'column_type' => 'col-lg',
        'column_size' => '12',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
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
      'style' => 'drupalhub_region',
    ),
    'fist_right' => array(
      'style' => 'drupalhub_region',
    ),
    'second' => array(
      'style' => 'drupalhub_region',
    ),
    'second_left' => array(
      'style' => 'drupalhub_region',
    ),
    'second_right' => array(
      'style' => 'drupalhub_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9002d792-6777-4fde-b083-3455d65e83e1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-03462688-14d9-4eb8-b9be-56efac88ab3c';
    $pane->panel = 'first';
    $pane->type = 'views_panes';
    $pane->subtype = 'front_page_gallery-panel_pane_1';
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
    $pane->uuid = '03462688-14d9-4eb8-b9be-56efac88ab3c';
    $display->content['new-03462688-14d9-4eb8-b9be-56efac88ab3c'] = $pane;
    $display->panels['first'][0] = 'new-03462688-14d9-4eb8-b9be-56efac88ab3c';
    $pane = new stdClass();
    $pane->pid = 'new-7535806c-7fcb-4ea9-8c40-7c00fe95f7ec';
    $pane->panel = 'first_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'top_users-panel_pane_1';
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
    $pane->uuid = '7535806c-7fcb-4ea9-8c40-7c00fe95f7ec';
    $display->content['new-7535806c-7fcb-4ea9-8c40-7c00fe95f7ec'] = $pane;
    $display->panels['first_left'][0] = 'new-7535806c-7fcb-4ea9-8c40-7c00fe95f7ec';
    $pane = new stdClass();
    $pane->pid = 'new-89bc83fa-12b3-4930-94df-c21443cf8ef0';
    $pane->panel = 'first_left';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '89bc83fa-12b3-4930-94df-c21443cf8ef0';
    $display->content['new-89bc83fa-12b3-4930-94df-c21443cf8ef0'] = $pane;
    $display->panels['first_left'][1] = 'new-89bc83fa-12b3-4930-94df-c21443cf8ef0';
    $pane = new stdClass();
    $pane->pid = 'new-c08be55b-8548-4bc1-9628-572536a43b2e';
    $pane->panel = 'fist_right';
    $pane->type = 'new_question';
    $pane->subtype = 'new_question';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-FCm5Aaa2mKY7BBz_GUfGi5XYn0u3kKUN0mpcs946s00',
      'form_token' => '-6P4dfQdr9xdAN92E4IBF4GbMHt7opSPYQm_GgoVDSw',
      'form_id' => 'drupalhub_questions_new_question_content_type_edit_form',
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
    $pane->uuid = 'c08be55b-8548-4bc1-9628-572536a43b2e';
    $display->content['new-c08be55b-8548-4bc1-9628-572536a43b2e'] = $pane;
    $display->panels['fist_right'][0] = 'new-c08be55b-8548-4bc1-9628-572536a43b2e';
    $pane = new stdClass();
    $pane->pid = 'new-45565fc7-bff8-4186-b408-5b2de3de4c2e';
    $pane->panel = 'fist_right';
    $pane->type = 'popular_tags';
    $pane->subtype = 'popular_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '45565fc7-bff8-4186-b408-5b2de3de4c2e';
    $display->content['new-45565fc7-bff8-4186-b408-5b2de3de4c2e'] = $pane;
    $display->panels['fist_right'][1] = 'new-45565fc7-bff8-4186-b408-5b2de3de4c2e';
    $pane = new stdClass();
    $pane->pid = 'new-aff4e697-4747-4475-bd7e-96bd2e0df875';
    $pane->panel = 'fist_right';
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
    $display->panels['fist_right'][2] = 'new-aff4e697-4747-4475-bd7e-96bd2e0df875';
    $pane = new stdClass();
    $pane->pid = 'new-477f3a22-8662-484c-921a-48d11be1f560';
    $pane->panel = 'second';
    $pane->type = 'views_panes';
    $pane->subtype = 'service_providers-panel_pane_1';
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
    $pane->uuid = '477f3a22-8662-484c-921a-48d11be1f560';
    $display->content['new-477f3a22-8662-484c-921a-48d11be1f560'] = $pane;
    $display->panels['second'][0] = 'new-477f3a22-8662-484c-921a-48d11be1f560';
    $pane = new stdClass();
    $pane->pid = 'new-b2093d4b-5cb2-4da3-9b33-4f797b5cb532';
    $pane->panel = 'second_left';
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
    $display->panels['second_left'][0] = 'new-b2093d4b-5cb2-4da3-9b33-4f797b5cb532';
    $pane = new stdClass();
    $pane->pid = 'new-d3a38bbe-11a0-46f5-a087-e21775d99ed7';
    $pane->panel = 'second_right';
    $pane->type = 'views_panes';
    $pane->subtype = 'recommandation-panel_pane_1';
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
    $pane->uuid = 'd3a38bbe-11a0-46f5-a087-e21775d99ed7';
    $display->content['new-d3a38bbe-11a0-46f5-a087-e21775d99ed7'] = $pane;
    $display->panels['second_right'][0] = 'new-d3a38bbe-11a0-46f5-a087-e21775d99ed7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}
