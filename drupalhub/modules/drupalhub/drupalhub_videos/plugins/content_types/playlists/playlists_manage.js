// todo: Use angular.
(function ($) {

  Drupal.behaviors.DrupalHubPlaylistForm = {
    attach: function (context) {

      // Show the form.
      $(".show-playlist-form").click(function(event) {
        event.preventDefault();
        $(".playlist-form").removeClass("disabled");
      });

      // Start dealing with the form.
      $(".playlist-form").submit(function(event) {
        event.preventDefault();

        $(".playlist-form .error").remove();

        var name = $("#name").val();
        var description = $("#description").val();

        var status = true;
        if (name == "") {
          $(".form-group.name").append("<div class='error'>" + Drupal.t('Please fill in the name.') + "</div>");
          status = false;
        }

        if ($(".items li").length == 0) {
          $(".form-group.videos").append("<div class='error'>" + Drupal.t('Please insert videos.') + "</div>");
          status = false;
        }

        if (status) {
          $(".buttons").append('<i class="fa fa-spinner fa-spin"></i>');
        }
      });
    }
  };

})(jQuery);
