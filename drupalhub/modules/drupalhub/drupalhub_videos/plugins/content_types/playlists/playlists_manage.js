// todo: Use angular.
(function ($) {

  /**
   * Displaying the form for CRUDing a plyalist.
   */
  Drupal.behaviors.DrupalHubShowPlaylist = {
    attach: function (context, settings) {
      $(".show-playlist-form").live('click', function(event) {
        event.preventDefault();
        $("#description").DrupalHubApplyCKedtor();
        $(".playlist-form").removeClass("disabled");
        $(".passed").addClass('disabled');
      });
    }
  };

  /**
   * Handling the submission of the form.
   */
  Drupal.behaviors.DrupalHubSubmissionHandeling = {
    attach: function (context, settings) {
      var ar = $(".autocomplete-results");
      $(".playlist-form").live('submit', function(event) {
        event.preventDefault();

        $.DrupalHubFormInit("ManagePlaylist");

        var name = $("#name");

        $("#name").CheckEmpty(Drupal.t('Please fill in the name.'));

        if ($(".items li").length == 0) {
          $("#playlist-search").SetError(Drupal.t('Please insert videos.'));
        }

        if ($(".description iframe").contents().find("body").text() == "") {
          $("#description").SetError(Drupal.t('Please insert description.'));
        }

        if (!$.FormStatus) {
          return;
        }

        $(".buttons button").AddSpinner();

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
          "label": name.val(),
          "body": CKEDITOR.instances.description.getData()
        };

        var id = $(this).attr("update");
        var type = 'POST';
        if (id != null) {
          data['id'] = id;
          type = 'PATCH';
        }

        $.DrupalHubAjax(type, "api/v1/playlist", data)
          .error(function() {
            $.RemoveSpinner();
            $(".buttons").append("<i class='fa fa-thumbs-down'></i>" + Drupal.t('An error has occurred while creating the playlist. Please content the site admin.'));
          })
          .success(function(data) {
            $.RemoveSpinner();
            $(".passed").removeClass('disabled');
            $(".playlist-form").addClass("disabled");

            if (type == 'POST') {
              // Add the playlist in the bottom.
              var append =
                '<tr>' +
                  '<td class="name">' + data.label + '</td>' +
                  '<td class="videos">' + data.videos.length + '</td>' +
                  '<td>' +
                    '<a href="#" class="delete" id="' + data.id + '">' + Drupal.t('Delete') + '</a> ' +
                    '<a href="#" class="edit" id="' + data.id + '">' + Drupal.t('Edit') + '</a>' +
                  '</td>' +
                '</tr>';

              if ($('.playlist tbody tr').length == 1) {
                $('.playlist tbody tr').remove();
              }
            }
            else {
              var row = $("[id='" + id + "']").parents('tr');
              row.find('.name').html(data.label);
              row.find('.videos').html(data.videos.length);
            }

            $(".playlist tbody tr:last").before(append);

            // Reset the form.
            ar.addClass("disabled").html('');
            $('.playlist-form')[0].reset();
            $('.items li').remove();
          });
      });
    }
  };

  /**
   * handling auto complete of the form.
   */
  Drupal.behaviors.DrupalHubSearchHandeling = {
    attach: function (context, settings) {
      var ar = $(".autocomplete-results");
      $("#playlist-search").keyup(function(event) {

        if (event.keyCode == 27) {
          // The user pressed on ESC. Close the select list.
          ar.addClass("disabled").html('');
          $("#playlist-search").val('');
          return;
        }

        var value = $(this).val();

        ar.removeClass("disabled").AddSpinner();

        if (value == "") {
          ar.addClass("disabled").html('');
          $.RemoveSpinner();
          return;
        }

        var results = [];
        $.DrupalHubAjax('GET', "api/v1/youtube", {"title": value}).success(function(result) {
          $.RemoveSpinner();

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
    }
  };

  /**
   * Adding the elements to the list.
   */
  Drupal.behaviors.DrupalHubAddingToPlaylist = {
    attach: function () {
      $(".fa-plus").live('click', function() {
        var ar = $(".autocomplete-results");
        var element = $(this).parents('.wrapper');

        ar.parent().DrupalHubResetElement();

        // Remove the element from the box.
        element.remove();

        // Check if there no more elements in the box.
        if (ar.find('.wrapper').length == 0) {
          ar.addClass("disabled").html('');
          $("#playlist-search").val('');
        }

        // Switch the plus symbol with minus.
        element.find(".fa-plus").addClass("fa-minus").removeClass("fa-plus");

        // Add the element.
        $(".items").append("<li id='" + element.attr('id') + "'>" + element.html() + "</li>");
      });
    }
  };

  /**
   * Remove a video from the list.
   */
  Drupal.behaviors.DrupalHubRemoveFromPlaylist = {
    attach: function () {
      $(".fa-minus").live('click', function() {
        var element = $(this).parents('li');

        // Remove the element from the box.
        element.remove();
      });
    }
  };

  /**
   * Delete a list.
   */
  Drupal.behaviors.DrupalHubDeletePlaylist = {
    attach: function (context, settings) {
      $(".delete").live('click', function(event) {
        event.preventDefault();

        var element = $(this);

        // Adding the spinner.
        element.AddSpinner();

        // Create the request.
        $.DrupalHubAjax('DELETE', "api/v1/playlist", {
          "id": $(this).attr("id")
        }).success(function(result) {
          // Remove the line.
          element.parents('tr').remove();

          if ($('.playlist tbody tr').length == 0) {
            $('.playlist tbody').html('<tr><td class="odd" colspan="3">' + Drupal.t('You did not created any playlist. <a href="#" class="show-playlist-form">Create a new playlist</a>') + '</td></tr>');
          }
        });
      });
    }
  };

  /**
   * Edit a list.
   */
  Drupal.behaviors.DrupalHubEditPlaylist = {
    attach: function () {
      $(".edit").live('click', function(event) {
        event.preventDefault();
        var element = $(this);

        // Adding the spinner.
        element.AddSpinner();
        var id = element.attr("id");

        // Get the list value.
        var info = '';
        $.DrupalHubAjax('GET', "api/v1/playlist", {"id": id}).done(function(result) {
          info = result.data[0];
          $("#name").val(info.label);
          $("#description").val(info.body.value).DrupalHubApplyCKedtor();
          $("#access_level").val(info.access);
          $(".playlist-form").attr("update", id);

          jQuery.each(info.videos, function(index, value) {
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
        }).then(function() {
          // Remove the spinner and display the form.
          $.RemoveSpinner();
          $(".playlist-form").removeClass("disabled");
          $(".passed").addClass('disabled');
        });
      });
    }
  };

})(jQuery);
