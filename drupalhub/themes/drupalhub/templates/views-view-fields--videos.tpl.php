<div class="video-wrapper">
  <div class="video">
    <?php print $fields['field_address']->content; ?>
  </div>
  <div class="information">
    <div class="title"><?php print $fields['title']->content; ?></div>
    <div class="user"><i class="fa fa-user"></i> <?php print $fields['name']->content; ?></div>
    <div class="length"><i class="fa fa-clock-o"></i> <?php print $fields['youtube_data']->content; ?></div>
    <div class="vote"><?php print $fields['field_vote']->content; ?></div>
  </div>
</div>