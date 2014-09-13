<div class="<?php print $classes ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <div class="video col-md-8 col-xs-12">
      <?php print $content['video']; ?>
    </div>
    <div class="others col-md-4 col-xs-12">
      <?php print $content['others']; ?>
    </div>
  </div>

  <div class="row">
    <div class="bottom col-md-12">
      <?php print $content['bottom']; ?>
    </div>
  </div>
</div>
