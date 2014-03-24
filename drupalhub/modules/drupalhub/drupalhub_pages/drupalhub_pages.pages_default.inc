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
  $display->layout = 'bootstrap_twocol_stacked';
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
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '18b2e656-3154-41da-9ac7-ece39f5e9510';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c99cd545-99bd-40cf-89ff-51523a75dbf2';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h3>Recent friends activity</h3>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c99cd545-99bd-40cf-89ff-51523a75dbf2';
    $display->content['new-c99cd545-99bd-40cf-89ff-51523a75dbf2'] = $pane;
    $display->panels['bottom'][0] = 'new-c99cd545-99bd-40cf-89ff-51523a75dbf2';
    $pane = new stdClass();
    $pane->pid = 'new-ad5baec9-8edd-4bb1-9bc5-81c203898614';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h1>Starred media</h1>

photos, youtube movies.',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ad5baec9-8edd-4bb1-9bc5-81c203898614';
    $display->content['new-ad5baec9-8edd-4bb1-9bc5-81c203898614'] = $pane;
    $display->panels['bottom'][1] = 'new-ad5baec9-8edd-4bb1-9bc5-81c203898614';
    $pane = new stdClass();
    $pane->pid = 'new-345bf5c2-12a0-4680-bb93-256fbddd7abd';
    $pane->panel = 'bottom';
    $pane->type = 'get_involve';
    $pane->subtype = 'get_involve';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 1,
      'override_title_text' => '',
      'form_build_id' => 'form-cdQg-WeOSeeM1GMyTeNYiSja91Pb0AfINjJn9W6k_Z4',
      'form_token' => 'OpoRS5ZIH1qRxRhwaYcC-_qfMN5YVm-a5ltRugT75cQ',
      'form_id' => 'drupalhub_pages_get_involve_content_type_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '345bf5c2-12a0-4680-bb93-256fbddd7abd';
    $display->content['new-345bf5c2-12a0-4680-bb93-256fbddd7abd'] = $pane;
    $display->panels['bottom'][2] = 'new-345bf5c2-12a0-4680-bb93-256fbddd7abd';
    $pane = new stdClass();
    $pane->pid = 'new-835bdca1-f894-4664-a40b-77dd5490a085';
    $pane->panel = 'left';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '835bdca1-f894-4664-a40b-77dd5490a085';
    $display->content['new-835bdca1-f894-4664-a40b-77dd5490a085'] = $pane;
    $display->panels['left'][0] = 'new-835bdca1-f894-4664-a40b-77dd5490a085';
    $pane = new stdClass();
    $pane->pid = 'new-cb19f2d7-a162-4218-8e1e-f67cd156b779';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h3>System messages</h3>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cb19f2d7-a162-4218-8e1e-f67cd156b779';
    $display->content['new-cb19f2d7-a162-4218-8e1e-f67cd156b779'] = $pane;
    $display->panels['left'][1] = 'new-cb19f2d7-a162-4218-8e1e-f67cd156b779';
    $pane = new stdClass();
    $pane->pid = 'new-4ddf9eb3-2bd0-4b09-8177-3b4d09cf97c9';
    $pane->panel = 'right';
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
    $pane->uuid = '4ddf9eb3-2bd0-4b09-8177-3b4d09cf97c9';
    $display->content['new-4ddf9eb3-2bd0-4b09-8177-3b4d09cf97c9'] = $pane;
    $display->panels['right'][0] = 'new-4ddf9eb3-2bd0-4b09-8177-3b4d09cf97c9';
    $pane = new stdClass();
    $pane->pid = 'new-a0f8b6fb-670a-4bdd-b91c-b4e56e5467f5';
    $pane->panel = 'right';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a0f8b6fb-670a-4bdd-b91c-b4e56e5467f5';
    $display->content['new-a0f8b6fb-670a-4bdd-b91c-b4e56e5467f5'] = $pane;
    $display->panels['right'][1] = 'new-a0f8b6fb-670a-4bdd-b91c-b4e56e5467f5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}
