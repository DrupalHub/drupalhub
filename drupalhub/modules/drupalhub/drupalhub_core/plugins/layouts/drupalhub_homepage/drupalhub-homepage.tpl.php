<div class="<?php print $classes ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <div class="col-md-12">
      <?php print $content['first']; ?>
    </div>
  </div>

  <div class="row">
    <div class="col-md-9 col-xs-12">
      <?php print $content['first_left']; ?>
    </div>
    <div class="col-md-3 col-xs-12">
      <?php print $content['fist_right']; ?>
    </div>
  </div>

  <div class="row">
    <div class="col-md-12">
      <?php print $content['second-top']; ?>
    </div>
  </div>

  <div class="row">
    <div class="col-md-12">
      <?php print $content['second-middle']; ?>
    </div>
  </div>

  <div class="row">
    <div class="col-md-12">
      <?php print $content['second-last']; ?>
    </div>
  </div>

  <div class="second-left-right row">
    <div class="col-md-6 col-xs-12">
      <?php print $content['second_left']; ?>
    </div>
    <div class="col-md-6 col-xs-12">
      <?php print $content['second_right']; ?>
    </div>
  </div>
</div>