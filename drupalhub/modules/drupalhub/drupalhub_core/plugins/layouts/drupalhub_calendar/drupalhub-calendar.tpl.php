<div class="<?php print $classes ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <div class="top col-md-12">
      <?php print $content['calendar']; ?>
    </div>
  </div>

  <div class="row">
    <div class="bottom col-md-4">
      <?php print $content['bottom-first']; ?>
    </div>
  </div>
</div>