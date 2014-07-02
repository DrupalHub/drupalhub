<div class="regular-login clearfix">
  <?php print render($form['name']); ?>
  <?php print render($form['pass']); ?>
  <?php print render($form['form_id']); ?>

</div>

<div class="social clearfix">
  <?php print render($form['github_signin']); ?>
  <?php print render($form['github_connect.return_to']); ?>
  <?php print render($form['twitter_signin']); ?>
  <?php print render($form['facebook_signin']); ?>

</div>

<div class="actions">
  <?php print render($form['actions']); ?>
</div>
