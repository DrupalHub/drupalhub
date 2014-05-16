<div class="<?php print $classes ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['first']): ?>
    <div class="row">
      <?php print $content['first']; ?>
    </div>
  <?php endif ?>

  <?php if ($content['first_left'] || $content['fist_right']): ?>
    <div class="row">
      <?php print $content['first_left']; ?>
      <?php print $content['fist_right']; ?>
    </div>
  <?php endif ?>

  <?php if ($content['second']): ?>
    <div class="row">
      <?php print $content['second']; ?>
    </div>
  <?php endif ?>

  <?php if ($content['second_left'] || $content['second_right']): ?>
    <div class="row">
      <?php print $content['second_left']; ?>
      <?php print $content['second_right']; ?>
    </div>
  <?php endif ?>
</div>
