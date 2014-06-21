<div id="service-provider-carousel" class="carousel" data-ride="">
  <div class="col-xs-12 no-padding clearfix">
    <div class="col-xs-1 relative">
      <a class="carousel-control" href="#service-provider-carousel" data-slide="prev">
        <?php if ($navigation): ?>
         <div class="arrow first_arrow"></div>
        <? endif; ?>
      </a>
    </div>

    <div class="col-xs-10 no-padding">
      <div id="service-provider-carousel" class="carousel slide">
        <div class="carousel-inner">
          <?php print $providers; ?>
        </div>
      </div>
    </div>

    <div class="col-xs-1 clearfix">
      <a class="carousel-control" href="#service-provider-carousel" data-slide="next">
        <?php if ($navigation): ?>
        <div class="arrow second_arrow"></div>
        <? endif; ?>
      </a>
    </div>
  </div>
</div>