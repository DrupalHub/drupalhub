<div class="<?php print $classes ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['first']): ?>
    <div class="first row">
      <?php print $content['first']; ?>
    </div>
  <?php endif ?>

  <?php if ($content['first_left'] || $content['fist_right']): ?>
    <div class="first-left-rigjt row">
      <?php print $content['first_left']; ?>
      <?php print $content['fist_right']; ?>
    </div>
  <?php endif ?>

  <?php if ($content['second-top']): ?>
    <div class="second-top row">
      <?php print $content['second-top']; ?>
    </div>
  <?php endif ?>
  <?php if ($content['second-middle']): ?>
    <div class="second-middle row">
      <?php print $content['second-middle']; ?>
    </div>
  <?php endif ?>

  <?php if ($content['second-last']): ?>
    <div class="second-last row">
      <?php print $content['second-last']; ?>
    </div>
  <?php endif ?>

  <?php if ($content['second_left'] || $content['second_right']): ?>
    <div class="second-left-right row">
      <?php print $content['second_left']; ?>
      <?php print $content['second_right']; ?>
    </div>
  <?php endif ?>
</div>
