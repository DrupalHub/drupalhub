<?php
/**
 * @file
 * drupalhub_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function drupalhub_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_results';
  $page->task = 'page';
  $page->admin_title = 'Search results';
  $page->admin_description = '';
  $page->path = 'search_results/%type/%input';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'type' => array(
      'id' => 2,
      'identifier' => 'String 2',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'input' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_results_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search_results';
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
  $display->layout = 'drupalhub_9_3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'first' => NULL,
      'second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a1b15144-d340-4d93-af88-8e6b71d710f7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2aff602e-42e8-468e-b95b-f7e629dbe3bb';
    $pane->panel = 'first';
    $pane->type = 'search_results';
    $pane->subtype = 'search_results';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-w_EAu6ydV2LP5lfjdjgyukMR7CfDggwYe8a0EPEVz4s',
      'form_token' => 'Dn3YBda5KUm8A-wAcSkFzKNfjTXDPsNGnnZ82UAkzcA',
      'form_id' => 'drupalhub_search_search_results_content_type_edit_form',
      'op' => 'Finish',
      'context' => array(
        0 => 'argument_string_2',
        1 => 'argument_string_1',
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
    $pane->uuid = '2aff602e-42e8-468e-b95b-f7e629dbe3bb';
    $display->content['new-2aff602e-42e8-468e-b95b-f7e629dbe3bb'] = $pane;
    $display->panels['first'][0] = 'new-2aff602e-42e8-468e-b95b-f7e629dbe3bb';
    $pane = new stdClass();
    $pane->pid = 'new-56f6039f-36f4-4da6-82b2-1f51046f9fc1';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-1Xdz7Hzif3zsT0Ci1WHON0ybM6shM9BI';
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
    $pane->uuid = '56f6039f-36f4-4da6-82b2-1f51046f9fc1';
    $display->content['new-56f6039f-36f4-4da6-82b2-1f51046f9fc1'] = $pane;
    $display->panels['second'][0] = 'new-56f6039f-36f4-4da6-82b2-1f51046f9fc1';
    $pane = new stdClass();
    $pane->pid = 'new-36b7eaf5-64d1-4136-b70e-76d99c0dd0c2';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-hgpfKHcnFK4kkcAT02ie13K5fYeRqEzY';
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
    $pane->uuid = '36b7eaf5-64d1-4136-b70e-76d99c0dd0c2';
    $display->content['new-36b7eaf5-64d1-4136-b70e-76d99c0dd0c2'] = $pane;
    $display->panels['second'][1] = 'new-36b7eaf5-64d1-4136-b70e-76d99c0dd0c2';
    $pane = new stdClass();
    $pane->pid = 'new-094b40f7-6e6e-45c5-aa6f-96d896c6ebba';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-bEI7sfj0GE5kGkDqVUF1lL0c1U7dQXVq';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '094b40f7-6e6e-45c5-aa6f-96d896c6ebba';
    $display->content['new-094b40f7-6e6e-45c5-aa6f-96d896c6ebba'] = $pane;
    $display->panels['second'][2] = 'new-094b40f7-6e6e-45c5-aa6f-96d896c6ebba';
    $pane = new stdClass();
    $pane->pid = 'new-e35c3fb9-6222-4a8f-bf36-f848382d9e58';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-XEslSIMRWHTzc3JmEEyJ61aKYrz5YAz1';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e35c3fb9-6222-4a8f-bf36-f848382d9e58';
    $display->content['new-e35c3fb9-6222-4a8f-bf36-f848382d9e58'] = $pane;
    $display->panels['second'][3] = 'new-e35c3fb9-6222-4a8f-bf36-f848382d9e58';
    $pane = new stdClass();
    $pane->pid = 'new-fc8a3983-6011-484f-8245-0fc42aa067a6';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-Rwb0hjdMUW04UYg0sNerTyDLT5xkFjyf';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'fc8a3983-6011-484f-8245-0fc42aa067a6';
    $display->content['new-fc8a3983-6011-484f-8245-0fc42aa067a6'] = $pane;
    $display->panels['second'][4] = 'new-fc8a3983-6011-484f-8245-0fc42aa067a6';
    $pane = new stdClass();
    $pane->pid = 'new-df5537a4-310d-4b1a-b358-527f90805c2f';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-aA0XknnUHzDx1qX5Nb0sJh89FGwQy61j';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'df5537a4-310d-4b1a-b358-527f90805c2f';
    $display->content['new-df5537a4-310d-4b1a-b358-527f90805c2f'] = $pane;
    $display->panels['second'][5] = 'new-df5537a4-310d-4b1a-b358-527f90805c2f';
    $pane = new stdClass();
    $pane->pid = 'new-349c58f4-09ef-4481-8408-3b8a164451bb';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-Wh3KK6vGQs5BMyZaggYn7uCgtbyNgv6o';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '349c58f4-09ef-4481-8408-3b8a164451bb';
    $display->content['new-349c58f4-09ef-4481-8408-3b8a164451bb'] = $pane;
    $display->panels['second'][6] = 'new-349c58f4-09ef-4481-8408-3b8a164451bb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e35c3fb9-6222-4a8f-bf36-f848382d9e58';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_results'] = $page;

  return $pages;

}
