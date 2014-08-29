(function ($) {

  Drupal.behaviors.DrupalHubUsers = {
    attach: function (context) {
      var position = $(".pane-user-field-reputation").offset();

      var scroller = function() {
        var scroller = $(this).scrollTop();

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

  Drupal.behaviors.DrupalHubUpdateAbout = {
    attach: function() {
      $("#edit-submit--2").click(function(event) {
        event.preventDefault();
        // Getting the value.
        var value = CKEDITOR.instances['edit-field-about-und-0-value--2'].getData();

        // JS effects: appending
        $(this).append('<div class="ajax-progress ajax-progress-throbber"><i class="glyphicon glyphicon-refresh glyphicon-spin"></i></div>');
        // todo: add here the restful callback.
        $(this).find('.ajax-progress').remove();
        // Hide the modal after finishing with the callback.
        $(".field-about-wrapper").addClass("disabled");
        // Update the content for now. The next page callback will have the
        // about field value.
        $(".pane-about .pane-content").html(value);

      });
    }
  }

})(jQuery);
