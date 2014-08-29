<?php
/**
 * @file
 * drupalhub_users.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function drupalhub_users_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
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
  $display->layout = 'drupalhub_user';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'first' => NULL,
      'second' => NULL,
      'top-first' => NULL,
      'top-second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '20ff8520-8afe-432d-9afc-57bed76b0834';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c8047f3d-6823-44cb-8294-51e3426d3efe';
    $pane->panel = 'first';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_reputation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'number_integer',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
      ),
      'context' => 'argument_entity_id:user_1',
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
    $pane->uuid = 'c8047f3d-6823-44cb-8294-51e3426d3efe';
    $display->content['new-c8047f3d-6823-44cb-8294-51e3426d3efe'] = $pane;
    $display->panels['first'][0] = 'new-c8047f3d-6823-44cb-8294-51e3426d3efe';
    $pane = new stdClass();
    $pane->pid = 'new-8d0240da-002e-42bf-b38b-79c1b22427a6';
    $pane->panel = 'first';
    $pane->type = 'about';
    $pane->subtype = 'about';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-wqlAfDnp2Lbs9yhz-IluuDyMGzvHfcQ2nNnn6qSMZQU',
      'form_token' => 'qiEhn6CJAjDdbBNyUf6Bg2t4cBDeCz4HFWssBQvSZkQ',
      'form_id' => 'drupalhub_users_about_content_type_edit_form',
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
    $pane->uuid = '8d0240da-002e-42bf-b38b-79c1b22427a6';
    $display->content['new-8d0240da-002e-42bf-b38b-79c1b22427a6'] = $pane;
    $display->panels['first'][1] = 'new-8d0240da-002e-42bf-b38b-79c1b22427a6';
    $pane = new stdClass();
    $pane->pid = 'new-d09ca2ed-334d-45aa-b0e1-41b4bff491fe';
    $pane->panel = 'first';
    $pane->type = 'recent';
    $pane->subtype = 'recent';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
      'bundle' => 'blog',
      'form_build_id' => 'form-IHytDbFZQsVVDEF7VTYHxEGQzgGvvTld00__3OF2zQI',
      'form_token' => 'IdLhxWWGD39rz_3E-pDpCHInd91s0DN9v1xFm1Fu3j4',
      'form_id' => 'drupalhub_users_recent_content_type_edit_form',
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
    $pane->uuid = 'd09ca2ed-334d-45aa-b0e1-41b4bff491fe';
    $display->content['new-d09ca2ed-334d-45aa-b0e1-41b4bff491fe'] = $pane;
    $display->panels['first'][2] = 'new-d09ca2ed-334d-45aa-b0e1-41b4bff491fe';
    $pane = new stdClass();
    $pane->pid = 'new-0a27dc91-b018-46e6-a74f-a4c3a469222d';
    $pane->panel = 'first';
    $pane->type = 'recent';
    $pane->subtype = 'recent';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'bundle' => 'question',
      'form_build_id' => 'form-TtIHV2k22JP9hNegMkvx_h7j83-5qqMPsAOKlTmO3dg',
      'form_token' => 'IdLhxWWGD39rz_3E-pDpCHInd91s0DN9v1xFm1Fu3j4',
      'form_id' => 'drupalhub_users_recent_content_type_edit_form',
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
    $pane->uuid = '0a27dc91-b018-46e6-a74f-a4c3a469222d';
    $display->content['new-0a27dc91-b018-46e6-a74f-a4c3a469222d'] = $pane;
    $display->panels['first'][3] = 'new-0a27dc91-b018-46e6-a74f-a4c3a469222d';
    $pane = new stdClass();
    $pane->pid = 'new-bb2ad759-bdc0-41f0-9cb5-852b3d606b45';
    $pane->panel = 'second';
    $pane->type = 'views_panes';
    $pane->subtype = 'activity_stram-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:user_1',
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
    $pane->uuid = 'bb2ad759-bdc0-41f0-9cb5-852b3d606b45';
    $display->content['new-bb2ad759-bdc0-41f0-9cb5-852b3d606b45'] = $pane;
    $display->panels['second'][0] = 'new-bb2ad759-bdc0-41f0-9cb5-852b3d606b45';
    $pane = new stdClass();
    $pane->pid = 'new-b229ac26-2dc7-4d27-9915-645ca7089916';
    $pane->panel = 'top-first';
    $pane->type = 'user_picture';
    $pane->subtype = 'user_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'image_styles' => 'medium_retina',
      'form_build_id' => 'form-oyZ_NfwJU_n4vmOD-VNLNhSFtzreMmuPqu2CaVrW_D8',
      'form_token' => 'fTiKI6akQ9QE7r4lqB_ffX6V7AkD17OOb6kMQqMvxk8',
      'form_id' => 'drupalhub_users_user_picture_content_type_edit_form',
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
    $pane->uuid = 'b229ac26-2dc7-4d27-9915-645ca7089916';
    $display->content['new-b229ac26-2dc7-4d27-9915-645ca7089916'] = $pane;
    $display->panels['top-first'][0] = 'new-b229ac26-2dc7-4d27-9915-645ca7089916';
    $pane = new stdClass();
    $pane->pid = 'new-53064821-b9ca-48dd-a53d-d100ae26b426';
    $pane->panel = 'top-second';
    $pane->type = 'token';
    $pane->subtype = 'user:name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:user_1',
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
    $pane->uuid = '53064821-b9ca-48dd-a53d-d100ae26b426';
    $display->content['new-53064821-b9ca-48dd-a53d-d100ae26b426'] = $pane;
    $display->panels['top-second'][0] = 'new-53064821-b9ca-48dd-a53d-d100ae26b426';
    $pane = new stdClass();
    $pane->pid = 'new-20f5506a-d42f-48b0-b459-3c2d03b05eb2';
    $pane->panel = 'top-second';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_first_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
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
    $pane->uuid = '20f5506a-d42f-48b0-b459-3c2d03b05eb2';
    $display->content['new-20f5506a-d42f-48b0-b459-3c2d03b05eb2'] = $pane;
    $display->panels['top-second'][1] = 'new-20f5506a-d42f-48b0-b459-3c2d03b05eb2';
    $pane = new stdClass();
    $pane->pid = 'new-89eb0524-03a4-4cb8-8148-0225221e6469';
    $pane->panel = 'top-second';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_last_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
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
    $pane->uuid = '89eb0524-03a4-4cb8-8148-0225221e6469';
    $display->content['new-89eb0524-03a4-4cb8-8148-0225221e6469'] = $pane;
    $display->panels['top-second'][2] = 'new-89eb0524-03a4-4cb8-8148-0225221e6469';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function drupalhub_users_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'questions';
  $page->task = 'page';
  $page->admin_title = 'Questions';
  $page->admin_description = '';
  $page->path = 'questions';
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
  $handler->name = 'page_questions_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'questions';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9101a6d3-933a-4231-b457-bf0921f9a56f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a5cdd4b1-171c-488a-a3d2-95bf2b93efda';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'question-panel_pane_1';
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
    $pane->uuid = 'a5cdd4b1-171c-488a-a3d2-95bf2b93efda';
    $display->content['new-a5cdd4b1-171c-488a-a3d2-95bf2b93efda'] = $pane;
    $display->panels['middle'][0] = 'new-a5cdd4b1-171c-488a-a3d2-95bf2b93efda';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['questions'] = $page;

  return $pages;

}
