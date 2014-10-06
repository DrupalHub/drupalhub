<div class="<?php print $classes ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <div class="col-md-9 first">
      <div class="row">
        <div class="col-md-12"><?php print $content['main_top']; ?></div>
      </div>
    </div>
    <div class="col-md-3 second">
      <?php print $content['second']; ?>
    </div>
  </div>
  <div class="row">
    <div class="col-md-4"><?php print $content['category_1']; ?></div>
    <div class="col-md-4"><?php print $content['category_2']; ?></div>
    <div class="col-md-4"><?php print $content['category_3']; ?></div>
  </div>
</div>
