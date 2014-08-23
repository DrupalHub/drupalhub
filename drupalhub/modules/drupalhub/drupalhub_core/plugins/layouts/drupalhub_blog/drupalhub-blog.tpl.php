<div class="<?php print $classes ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <div class="col-md-7 top-first">
      <?php print $content['top_first']; ?>
    </div>
    <div class="col-md-5 top-second">
      <?php print $content['top_second']; ?>
    </div>
  </div>
  <div class="row">
    <div class="col-md-12 bottom">
      <?php print $content['bottom']; ?>
    </div>
  </div>
</div>