// todo: Use angular.
(function ($) {

  Drupal.behaviors.DrupalHubPlaylistForm = {
    attach: function (context, settings) {
      var ar = $(".autocomplete-results");

      // Show the form.
      $(".show-playlist-form").live('click', function(event) {
        event.preventDefault();
        $(".playlist-form").removeClass("disabled");
        $(".passed").addClass('disabled');
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

          $.ajax({
            type: 'POST',
            beforeSend: function (request) {
              request.setRequestHeader("X-CSRF-Token", settings.plyalist.csrfToken);
            },
            url: settings.basePath + "api/v1/playlist",
            dataType: "json",
            contentType: "application/json",
            data: {
              "videos[]": ids,
              "access": access,
              "label": name,
              "body": description
            },
            error: function(e) {
              console.log(e);
              $(".buttons .fa-spinner").remove();
              $(".buttons").append('<i class="fa fa-thumbs-down"></i>');
            },
            success: function(id) {
              $(".buttons .fa-spinner").remove();
              $(".passed").removeClass('disabled');
              $(".playlist-form").addClass("disabled");

              // Add the playlist in the bottom.
              var append =
                '<tr>' +
                  '<td>' + name + '</td>' +
                  '<td>' + ids.length + '</td>' +
                  '<td>' +
                    '<a href="#" class="delete" id="' + id + '">' + Drupal.t('Delete') + '</a></td>' +
                    '<a href="#" class="edit" id="' + id + '">' + Drupal.t('Edit') + '</a></td>' +
                '</tr>';

              if ($('.playlist tbody tr').length == 1) {
                $('.playlist tbody tr').remove();
              }

              $('.playlist tbody:last').append(append);

              // Reset the form.
              ar.addClass("disabled").html('');
              $('.playlist-form')[0].reset();
              $('.items li').remove();

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
        $.get(settings.basePath + "api/v1/youtube", {"title": value})
          .done(function(result) {

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

      // Edit a list.
      $(".edit").click(function(event) {
        event.preventDefault();
        var element = $(this);

        // Adding the spinner.
        element.parent().append(' <i class="fa fa-spinner fa-spin"></i>');

        // Get the list value.
        var info = '';
        $.get(settings.basePath + "api/v1/playlist", {"id": element.attr("id")})
          .done(function(result) {
            info = result.data[0];
            $("#name").val(info.label);
            $("#description").val(info.body.value);
            $("#access_level").val(info.access);
            $(".playlist-form").attr("update", info.id);

            console.log(info);

            $.get(settings.basePath + "api/v1/youtube", {"ids[]": info.videos})
              .then(function(result) {
                console.log(info.videos);
                jQuery.each(result.data, function(index, value) {
                  if ($(".items li[id=" + value.id + "]").length != 0) {
                    return 1;
                  }

                  var html =
                    '<div class="wrapper clearfix" id="' + value.id + '">' +
                      '<img size=80 width=80 src="' + value.image + '" />' +
                      '<p class="information">' +
                        value.label + '<br />' +
                        value.length +
                      '</p>' +
                      '<p class="add">' +
                      '<i class="fa fa-minus"></i>' +
                      '</p>' +
                    '</div>';

                  $(".items").append("<li id='" + value.id + "'>" + html + "</li>");

                });
              });
          });

        // Remove the spinner and display the form.
        element.parent().find('i').remove();
        $(".playlist-form").removeClass("disabled");
        $(".passed").addClass('disabled');

        // Submit the form.
      });

      // Edit a list.
      $(".delete").live('click', function(event) {
        event.preventDefault();

        var element = $(this);

        // Adding the spinner.
        element.parent().append(' <i class="fa fa-spinner fa-spin"></i>');

        // Create the request.
        $.ajax({
          beforeSend: function (request) {
            request.setRequestHeader("X-CSRF-Token", settings.plyalist.csrfToken);
          },
          url: settings.basePath + "api/v1/playlist",
          type: 'DELETE',
          data: {
            "id": $(this).attr("id")
          },
          success: function(result) {
            // Remove the line.
            element.parents('tr').remove();

            if ($('.playlist tbody tr').length == 0) {
              $('.playlist tbody').html('<tr><td class="odd" colspan="3">' + Drupal.t('You did not created any playlist. <a href="#" class="show-playlist-form">Create a new playlist</a>') + '</td></tr>');
            }
          }
        });
      });
    }
  };

})(jQuery);