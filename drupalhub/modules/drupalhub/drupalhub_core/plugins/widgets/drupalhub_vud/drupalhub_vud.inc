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
}