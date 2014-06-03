<div class="drupal-of-the-month">
  <div class="row header">
    <h2 class="white no-margin no-padding text-center"><?php print t('Drupal of the month'); ?></h2>
  </div>
  <div class="row grey-bg month_overlay">
    <div class="col-xs-12">
      <div class="text-center title large"><?php print $title; ?></div>
      <ul class="stars">
        <li class="star"></li>
        <li class="star"></li>
        <li class="star"></li>
        <li class="star"></li>
        <li class="star"></li>
      </div>
      <div class="image" style="padding:0 12px">
        <?php print $image; ?>
        <?php print $strip; ?>
      </div>
      <div class="row text-center ratings">
        <div class="col-xs-3"></div>
        <div class="col-xs-6">
          <div class="row">
            <div class="col-xs-4"><i class="fa fa-heart"></i> 39</div>
          </div>
        </div>
        <div class="col-xs-3"></div>
      </div>
      <div class="text-center">
        <?php print $body; ?>
      </div>
      <div class="group"><?php print t('From the portfolio of: '); ?> <?php print $group_link; ?></div>
    </div>
  </div>
</div>
