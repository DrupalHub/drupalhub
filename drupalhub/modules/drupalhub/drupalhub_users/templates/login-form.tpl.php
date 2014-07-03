<div class="login-form-wrapper">

  <div class="standard-login">
    <div class="input-group login-input user">
      <span class="input-group-addon"><i class="fa fa-user"></i></span>
      <?php print render($form['name']); ?>
    </div>

    <div class="input-group login-input pass">
      <span class="input-group-addon"><i class="fa fa-lock"></i></span>
      <?php print render($form['pass']); ?>
    </div>
    <?php print render($form['form_id']); ?>
  </div>

  <div class="social-login-buttons">

    <div class="social-login">
      <div class="element twitter clearfix"><?php print render($form['twitter_signin']); ?></div>
      <div class="element facebook clearfix"><?php print render($form['facebook_signin']); ?></div>
      <div class="element github clearfix">
        <?php print render($form['github_signin']); ?>
        <?php print render($form['github_connect.return_to']); ?>
      </div>

    </div>

    <div class="buttons clearfix">
      <?php print render($form['actions']); ?>
    </div>
  </div>

</div>
