<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_page_preprocess().
 */
function drupalhub_preprocess_page(&$variables) {
  $variables['social'] = array(
    'youtube' => url('https://www.youtube.com/channel/UCJe3SCokovJBxxe-etjWhtA'),
    'twitter' => url('https://twitter.com/DrupalIsrael'),
    'google' => url('https://plus.google.com/communities/116473259616645148688'),
    'facebook' => url('https://www.facebook.com/groups/drupalil'),
    'github' => url('http://github.com/drupalhub/drupalhub'),
  );

  $variables['loggin_button'] = l(t('Login'), 'user/login', array('attributes' => array('class' => array('login'))));

  // Adding slide show.
  $variables['slide_show'] = '';
  if (variable_get('front_page_slideshow', FALSE) && drupal_is_front_page()) {
    $variables['slide_show'] = views_embed_view('gallery');
  }
}

/**
 * Implements hook_css_alter().
 */
function drupalhub_css_alter(&$css) {
  $theme_path = drupal_get_path('theme', 'drupalhub');
  // Exclude specified CSS files from theme.
  $excludes = bootstrap_get_theme_info(NULL, 'exclude][css');
  // Add Bootstrap CDN file and overrides.
  $bootstrap_cdn = theme_get_setting('bootstrap_cdn');
  if ($bootstrap_cdn) {
    // Add CDN.
    if (theme_get_setting('bootstrap_bootswatch')) {
      $cdn = '//netdna.bootstrapcdn.com/bootswatch/' . $bootstrap_cdn  . '/' . theme_get_setting('bootstrap_bootswatch') . '/bootstrap.min.css';
    }
    else {
      $cdn = '//netdna.bootstrapcdn.com/bootstrap/' . $bootstrap_cdn  . '/css/bootstrap.min.css';
    }
    $css[$cdn] = array(
      'data' => $cdn,
      'type' => 'external',
      'every_page' => TRUE,
      'media' => 'all',
      'preprocess' => FALSE,
      'group' => CSS_THEME,
      'browsers' => array('IE' => TRUE, '!IE' => TRUE),
      'weight' => -2,
    );
    // Add overrides.
    $override = $theme_path . '/css/overrides.css';
    $css[$override] = array(
      'data' => $override,
      'type' => 'file',
      'every_page' => TRUE,
      'media' => 'all',
      'preprocess' => TRUE,
      'group' => CSS_THEME,
      'browsers' => array('IE' => TRUE, '!IE' => TRUE),
      'weight' => -1,
    );
  }
  if (!empty($excludes)) {
    $css = array_diff_key($css, drupal_map_assoc($excludes));
  }
}

function drupalhub_form_required_marker($variables) {
  $variables['element'] += array(
    '#show-required' => TRUE,
  );

  if (!$variables['element']['#show-required']) {
    return;
  }

  // This is also used in the installer, pre-database setup.
  $t = get_t();
  $attributes = array(
    'class' => 'form-required',
    'title' => $t('This field is required.'),
  );
  return '<span' . drupal_attributes($attributes) . '>*</span>';
}