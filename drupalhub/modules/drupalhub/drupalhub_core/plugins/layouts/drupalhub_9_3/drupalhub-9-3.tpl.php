<div class="<?php print $classes ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <div class="col-md-9 first">
      <?php print $content['first']; ?>
    </div>
    <div class="col-md-3 second">
      <?php print $content['second']; ?>
    </div>
  </div>
</div>