<?php

if (variable_get('drupalhub_files_available', FALSE)) {
  $plugin = array(
    'label' => t('Drupalhub file upload'),
    'description' => t('A file upload wrapped with RESTful.'),
    'resource' => 'drupalhub_file',
    'name' => 'drupalhub_file__1_0',
    'class' => 'DrupalHubRestfulFilesUpload',
    'entity_type' => 'file',
    'authentication_types' => TRUE,
    'authentication_optional' => variable_get('restful_file_upload_allow_anonymous_user', FALSE),
    // We will implement hook_menu() with custom settings.
    'menu_item' => variable_get('restful_hook_menu_base_path', 'api') . '/drupalhub-file-upload',
  );
}
