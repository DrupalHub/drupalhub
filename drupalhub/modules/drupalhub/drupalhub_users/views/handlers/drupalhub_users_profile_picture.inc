<?php

/**
 * Drupalhub user profile picture.
 */
class drupalhub_users_profile_picture extends views_handler_field_entity {

  function render($values) {
    $user = user_load($values->uid);
    return drupalhub_users_user_picture($user, $this->options['image_style']);
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['image_style'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $styles = image_styles();
    $style_options = array('' => t('Default'));
    foreach ($styles as $style) {
      $style_options[$style['name']] = $style['name'];
    }

    $form['image_style'] = array(
      '#title' => t('Image style'),
      '#description' => t('Using <em>Default</em> will use the site-wide image style for user pictures set in the <a href="!account-settings">Account settings</a>.', array('!account-settings' => url('admin/config/people/accounts', array('fragment' => 'edit-personalization')))),
      '#type' => 'select',
      '#options' => $style_options,
      '#default_value' => $this->options['image_style'],
    );
  }
}
