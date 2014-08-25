<div class="row activity-stream-instance <?php print $fields['type']->raw; ?>">
  <div class="icons hidden-xs">
    <i class="fa fa-thumbs-up disabled"></i>
    <i class="fa fa-drupal disabled"></i>
    <i class="fa fa-comment disabled"></i>
    <i class="fa fa-pencil disabled"></i>
  </div>
  <div class="activity-header">
      <div class="picture col-xs-12"><?php print $fields['picture']->content; ?></div>

      <div class="info col-xs-12">
        <?php print $fields['name']->content; ?><Br /><br />
        <?php print $fields['timestamp']->content; ?>
    </div>
  </div>

  <div class="activity-body">
    <?php print $fields['message_render']->content; ?>
  </div>

  <div class="activity-footer">
  </div>
</div>