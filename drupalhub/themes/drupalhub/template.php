<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_page_preprocess().
 */
function drupalhub_preprocess_page(&$variables) {
  $socials = array(
    'fa-youtube-play' => 'https://www.youtube.com/channel/UCJe3SCokovJBxxe-etjWhtA',
    'fa-twitter' => 'https://twitter.com/DrupalIsrael',
    'fa-google-plus' => 'https://plus.google.com/communities/116473259616645148688',
    'fa-facebook-square' => 'https://www.facebook.com/groups/drupalil',
    'fa-github-alt' => 'http://github.com/drupalhub/drupalhub',
  );

  $items = array();
  foreach ($socials as $fa => $link) {
    $items[] = "<a href='{$link}'><i class='fa {$fa}'></i></a>";
  }

  $variables['social'] = theme('item_list', array(
    'items' => $items,
    'attributes' => array('class' => 'social nav navbar-nav'),
  ));

  $inners = array(
    'calendar' => array(
      'url' => 'calendar',
      'text' => t('Calendar'),
      'fa' => 'fa-calendar',
    ),
    'video' => array(
      'url' => 'video',
      'text' => t('Video library'),
      'fa' => 'fa-youtube-square',
    ),
    'documentation' => array(
      'url' => 'documentation',
      'text' => t('Documentation'),
      'fa' => 'fa-book',
    ),
  );

  $items = array();
  foreach ($inners as $inner) {
    $items[] = "<i class='fa {$inner['fa']}'></i> " . l($inner['text'], $inner['url']);
  }

  $variables['loggin_button'] = l(t('Login'), 'user/login', array('attributes' => array('class' => array('login'))));

  // Adding slide show.
  $variables['slide_show'] = '';
  if (variable_get('front_page_slideshow', FALSE) && drupal_is_front_page()) {
    $variables['slide_show'] = views_embed_view('gallery');
  }

  if (user_is_logged_in()) {
    global $user;
    $variables['dropdown_label'] = drupalhub_users_user_picture(user_load($user->uid), 'small') . ' ' . $user->name . ' ';
    $variables['dropdown_items'] = theme('item_list', array(
      'items' => array(
        l(t('Profile page'), 'user'),
        l(t('Manage playlist'), 'video/playlists'),
        l(t('Logout'), 'user/logout'),
      ),
      'attributes' => array(
        'class' => 'dropdown-menu',
        'role' => 'menu',
        'aria-labelledby' => 'UserLinks',
      )
    ));
  }

  $variables['links'] = theme('item_list', array(
    'items' => $items,
    'attributes' => array('class' => 'inner-links'),
  ));

  drupal_add_js(libraries_get_path('typeahead') . '/typeahead.bundle.js');
  drupal_add_js(drupal_get_path('theme', 'drupalhub') . '/js/search.js');

  $menu = menu_get_item();
  $variables['search'] = '';
  if ($menu['path'] == 'search_results/%') {
    $variables['search'] = $menu['map'][1];
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

/**
 * Remove the required marker from the label.
 */
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
