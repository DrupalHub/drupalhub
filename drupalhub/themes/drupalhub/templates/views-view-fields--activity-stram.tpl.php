<div class="row activity-stream-instance">
  <div class="activity-header">
    <div class="picture-name"><?php print $fields['picture']->content; ?> <?php print $fields['name']->content; ?></div>
    <?php print $fields['timestamp']->content; ?>
  </div>

  <div class="activity-body">
    <?php print $fields['message_render']->content; ?>
  </div>

  <div class="activity-footer">
  </div>
</div>