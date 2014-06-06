<div id="carousel-example-generic" class="carousel" data-ride="">
  <div class="col-xs-12 no-padding clearfix">
    <div class="col-xs-1 relative">
      <!--    <div class="arrow first_arrow disabled"></div>-->
      <a class="left carousel-control" href="#carousel-example-generic" data-slide="prev">
        <span class="glyphicon glyphicon-chevron-left"></span>
      </a>
    </div>

    <div class="col-xs-10 no-padding">
      <div class="carousel-inner">
        <?php print $providers; ?>
      </div>
    </div>

    <div class="col-xs-1 clearfix">
      <!--    <div class="arrow second_arrow"></div>-->
      <a class="right carousel-control" href="#carousel-example-generic" data-slide="next">
        <span class="glyphicon glyphicon-chevron-right"></span>
      </a>
    </div>
  </div>
</div>