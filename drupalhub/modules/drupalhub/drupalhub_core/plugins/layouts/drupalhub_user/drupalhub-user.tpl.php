<div class='sticky-container'>
  <div class="container"><?php print $image; ?> <span class="username"><?php print $name; ?></span></div>
</div>
<div class="<?php print $classes ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <div class="top col-md-12">
      <?php print $content['top']; ?>
    </div>
  </div>

  <div class="row">
    <div class="first-bottom col-md-3 col-xs-12">
      <?php print $content['first']; ?>
    </div>
    <div class="second-bottom col-md-9 col-xs-12">
      <?php print $content['second']; ?>
    </div>
  </div>
</div>