
(function ($) {

  Drupal.behaviors.DrupalHubPagesSlideShow = {
    attach: function (context) {
      $('.carousel').carousel('pause');
    }
  };

})(jQuery);
