<?php

/**
 * @file
 * Up Down Widget.
 */

/**
 * Plugin decleration.
 */
$plugin = array(
  'title' => t('DrupalHub vote up down'),
  'description' => t('Drupalhub widget for up an down.'),
  'class' => 'DrupalHubVUD',
);

class DrupalHubVUD extends voteUpDownBase {

  /**
   * {@inheritdoc}
   */
  public function preprocess(&$variables) {
    parent::preprocess($variables);

    if ($variables['show_up_as_link']) {
      $variables['show_down_as_link'] = FALSE;
    }
  }
}