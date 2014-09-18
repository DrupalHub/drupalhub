// todo: Use angular.
(function ($) {

  Drupal.behaviors.DrupalHubPlaylistForm = {
    attach: function (context) {
      var ar = $(".autocomplete-results");

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

        if (description == "") {
          $(".form-group.description").append("<div class='error'>" + Drupal.t('Please insert description.') + "</div>");
          status = false;
        }

        if (status) {
          $(".buttons").append('<i class="fa fa-spinner fa-spin"></i>');
        }
      });

      // Searching for videos.
      $("#playlist-search").keyup(function() {
        var value = $(this).val();

        ar.removeClass("disabled").html('<i class="fa fa-spinner fa-spin"></i>');

        if (value == "") {
          ar.addClass("disabled").html('');
          return;
        }

        var results = [];
        // todo: Get the base address.
        $.getJSON("http://localhost/drupalhub/www?q=api/v1/youtube&title=" + value, function(result) {

          jQuery.each(result.data, function(index, value) {
            if ($(".items li[id=" + value.id + "]").length != 0) {
              return 1;
            }

            results.push(
              '<div class="wrapper clearfix" id="' + value.id + '">' +
                '<img size=80 width=80 src="' + value.image + '" />' +
                  '<p class="information">' +
                    value.label + '<br />' +
                    value.length +
                  '</p>' +
                  '<p class="add">' +
                    '<i class="fa fa-plus"></i>' +
                  '</p>' +
              '</div>'
            );
          });

          var content = results.join("");

          if (content == "") {
            ar.addClass("disabled").html('');
          }
          else {
            ar.html(results.join(""));
          }

        });

      });

      // Adding the elements to the list.
      $(".fa-plus").live('click', function() {
        var element = $(this).parents('.wrapper');

        // Remove the element from the box.
        element.remove();

        // Check if there no more elements in the box.
        if (ar.find('.wrapper').length == 0) {
          ar.addClass("disabled").html('');
        }

        // Add the element.
        $(".items").append("<li id='" + element.attr('id') + "'>" + element.html() + "</li>");
      });

      // Checking where the mouse was focused. If out side the autocomplete
      // results hide it.
      $(':not(.autocomplete-results)').click(function() {
      });

    }
  };

})(jQuery);
