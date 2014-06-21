
(function ($) {

  Drupal.behaviors.DrupalHubPagesSlideShow = {
    attach: function (context) {
      $('.pane-service-provider .carousel').carousel('pause');
    }
  };

})(jQuery);
