<?php

$plugin = array(
  'label' => t('Blog'),
  'description' => t('Restuling event blog.'),
  'resource' => 'blog',
  'class' => 'DrupalHubBlog',
  'name' => 'blog__1_0',
  'entity_type' => 'node',
  'bundle' => 'blog',
  'hook_menu' => TRUE,
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
