(function ($) {

  Drupal.behaviors.DrupalHubUsers = {
    attach: function (context) {
      var position = $(".pane-user-field-reputation").offset();

      var scroller = function() {
        var scroller = $(this).scrollTop();
        if (!position) {
          return;
        }
        if (position.top < scroller) {
          $(".pane-sidebar .normal").fadeOut();
          $(".sticky-container").fadeIn();
        }
        else {
          $(".pane-sidebar .normal").fadeIn();
          $(".sticky-container").fadeOut();
        }
      };

      scroller();
      $(window).scroll(function() {
        scroller();
      });
    }
  };

  Drupal.behaviors.DrupalHubUsersAbout = {
    attach: function() {
      $(".add-info").click(function(event) {
        event.preventDefault();
        $(".field-about-wrapper").removeClass("disabled");
      });
    }
  };

})(jQuery);
