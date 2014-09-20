// todo: Use angular.
(function ($) {

  Drupal.behaviors.DrupalHubPlaylistForm = {
    attach: function (context, settings) {
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

          // Get rest of the values.
          var ids = [];
          $(".items li").each(function(i) {
            ids[i] = $(this).attr("id");
          });

          // Get the access level.
          var access = $(".access_level").val();

          var data = {
            "videos[]": ids,
            "access": access,
            "label": name,
            "body": description
          };

          $.ajax({
            type: 'POST',
            beforeSend: function (request) {
              request.setRequestHeader("X-CSRF-Token", settings.plyalist.csrfToken);
            },
            url: settings.basePath + "api/v1/playlist",
            dataType: "json",
            contentType: "application/json",
            data: data,
            error: function(e) {
              console.log(e);
              $(".buttons .fa-spinner").remove();
              $(".buttons").append('<i class="fa fa-thumbs-down"></i>');
            },
            success: function(e) {
              $(".buttons .fa-spinner").remove();
              $(".buttons").append('<i class="fa fa-thumbs-up"></i>' + Drupal.t('The playlist has created successfully'));
            }
          });
        }
      });

      // Searching for videos.
      $("#playlist-search").keyup(function(event) {

        if (event.keyCode == 27) {
          // The user pressed on ESC. Close the select list.
          ar.addClass("disabled").html('');
          return;
        }

        var value = $(this).val();

        ar.removeClass("disabled").html('<i class="fa fa-spinner fa-spin"></i>');

        if (value == "") {
          ar.addClass("disabled").html('');
          return;
        }

        var results = [];
        // todo: switch to $.get.
        $.getJSON(settings.basePath + "?q=api/v1/youtube&title=" + value, function(result) {

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
    }
  };

})(jQuery);

function buildQuery(obj) {
  var Result= '';
  if(typeof(obj)== 'object') {
    jQuery.each(obj, function(key, value) {
      Result+= (Result) ? '&' : '';
      if(typeof(value)== 'object' && value.length) {
        for(var i=0; i<value.length; i++) {
          Result+= [key+'[]', encodeURIComponent(value[i])].join('=');
        }
      } else {
        Result+= [key, encodeURIComponent(value)].join('=');
      }
    });
  }
  return Result;
}
