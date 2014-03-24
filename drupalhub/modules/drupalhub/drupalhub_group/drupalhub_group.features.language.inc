<?php
/**
 * @file
 * drupalhub_group.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function drupalhub_group_locale_default_languages() {
  $languages = array();

  // Exported language: en.
  $languages['en'] = array(
    'language' => 'en',
    'name' => 'English',
    'native' => 'English',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => '',
    'weight' => 0,
  );
  // Exported language: he.
  $languages['he'] = array(
    'language' => 'he',
    'name' => 'Hebrew',
    'native' => 'עברית',
    'direction' => 1,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'he',
    'weight' => 0,
  );
  return $languages;
}
