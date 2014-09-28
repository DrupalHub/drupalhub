<div class="<?php print $classes ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <div class="col-md-10 first">
      <div class="row">
        <div class="col-md-12"><?php print $content['main_top']; ?></div>
        <div class="col-md-3"><?php print $content['category_1']; ?></div>
        <div class="col-md-3"><?php print $content['category_2']; ?></div>
        <div class="col-md-3"><?php print $content['category_3']; ?></div>
      </div>
    </div>
    <div class="col-md-2 second">
      <?php print $content['second']; ?>
    </div>
  </div>
</div>
