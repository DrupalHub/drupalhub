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
    $pane->pid = 'new-de35b5a0-66b7-4533-a771-0cd7f917863c';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
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
    $pane->uuid = 'de35b5a0-66b7-4533-a771-0cd7f917863c';
    $display->content['new-de35b5a0-66b7-4533-a771-0cd7f917863c'] = $pane;
    $display->panels['bottom'][0] = 'new-de35b5a0-66b7-4533-a771-0cd7f917863c';
    $pane = new stdClass();
    $pane->pid = 'new-d16b577d-8d6d-4317-adf0-308ee8c59a38';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
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
    $pane->uuid = 'd16b577d-8d6d-4317-adf0-308ee8c59a38';
    $display->content['new-d16b577d-8d6d-4317-adf0-308ee8c59a38'] = $pane;
    $display->panels['bottom'][1] = 'new-d16b577d-8d6d-4317-adf0-308ee8c59a38';
    $pane = new stdClass();
    $pane->pid = 'new-0707b89e-b7a0-4c24-b057-10c767067fbf';
    $pane->panel = 'bottom';
    $pane->type = 'get_involve';
    $pane->subtype = 'get_involve';
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
    $pane->uuid = '0707b89e-b7a0-4c24-b057-10c767067fbf';
    $display->content['new-0707b89e-b7a0-4c24-b057-10c767067fbf'] = $pane;
    $display->panels['bottom'][2] = 'new-0707b89e-b7a0-4c24-b057-10c767067fbf';
    $pane = new stdClass();
    $pane->pid = 'new-e74a46dc-4d15-473d-a850-aa8a838a057a';
    $pane->panel = 'left';
    $pane->type = 'popular_tags';
    $pane->subtype = 'popular_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-TptvpjMG-WmLRy-ED0L_3Tb4ZIZepK8gbbcy4EePQw4',
      'form_token' => 'Vjs1iCPGV-bg9Luq9-8_PCCi1wPBUapJpIj41-sKaeA',
      'form_id' => 'drupalhub_questions_new_question_content_type_edit_form',
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
    $pane->uuid = 'e74a46dc-4d15-473d-a850-aa8a838a057a';
    $display->content['new-e74a46dc-4d15-473d-a850-aa8a838a057a'] = $pane;
    $display->panels['left'][0] = 'new-e74a46dc-4d15-473d-a850-aa8a838a057a';
    $pane = new stdClass();
    $pane->pid = 'new-2dd3bedb-c73c-4bd2-b4be-4204a6267d86';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
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
    $pane->uuid = '2dd3bedb-c73c-4bd2-b4be-4204a6267d86';
    $display->content['new-2dd3bedb-c73c-4bd2-b4be-4204a6267d86'] = $pane;
    $display->panels['left'][1] = 'new-2dd3bedb-c73c-4bd2-b4be-4204a6267d86';
    $pane = new stdClass();
    $pane->pid = 'new-c51e31d0-2f07-4a18-abff-79b78fa58ac6';
    $pane->panel = 'right';
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
    $pane->uuid = 'c51e31d0-2f07-4a18-abff-79b78fa58ac6';
    $display->content['new-c51e31d0-2f07-4a18-abff-79b78fa58ac6'] = $pane;
    $display->panels['right'][0] = 'new-c51e31d0-2f07-4a18-abff-79b78fa58ac6';
    $pane = new stdClass();
    $pane->pid = 'new-b3050dad-8e88-4025-8c3f-7f6c3e3c42d2';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'main_page_questions-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'title' => 'asdasdasd',
      'form_build_id' => 'form-fzAk4tVjGEQcpyD11QhmYKoZXgdHMwLKCTmWXhzEJMg',
      'form_token' => '7-TeL-g2QZf428Zt8y-GdYMolwDrfFU8KN3JbkFyNdU',
      'form_id' => 'drupalhub_pages_drupal_of_the_month_content_type_edit_form',
      'op' => 'Finish',
      'node_id' => NULL,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b3050dad-8e88-4025-8c3f-7f6c3e3c42d2';
    $display->content['new-b3050dad-8e88-4025-8c3f-7f6c3e3c42d2'] = $pane;
    $display->panels['right'][1] = 'new-b3050dad-8e88-4025-8c3f-7f6c3e3c42d2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}
