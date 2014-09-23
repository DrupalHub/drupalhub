// todo: Use angular.
(function ($) {

  /**
   * Reset the modal form after closing it.
   */
  Drupal.behaviors.DrupalHubVideoModalOpened = {
    attach: function (context, settings) {
      $(".new-video a").click(function() {
        $("#url").val("");
        $("#AddVideo .result").addClass("disabled");
        $(".modal-footer .btn").removeClass('disabled');
        $(".modal-footer .passed").addClass('disabled');
        $(".modal-footer").addClass("disabled");
        $(".modal-dialog").css("right", "140px");
        $("#AddVideo .modal-content").css('width', '578px');
        $(".errors").html('');
      });
    }
  };

  /**
   * Displaying the form for CRUDing a plyalist.
   */
  Drupal.behaviors.DrupalHubVideoModal = {
    attach: function (context, settings) {
      $("#url").keyup(function() {
        var value = $(this).val();

        var regExp = /^.*(youtu.be\/|v\/|u\/\w\/|embed\/|watch\?v=|\&v=)([^#\&\?]*).*/;
        var match = value.match(regExp);
        if (match && match[2].length == 11) {
          // Reset any errors.
          $(".errors").html('');

          // Start the magic: get the video info.
          var id = match[2];
          $(this).parent().append('<i id="fa" class="fa fa-spin fa-spinner"></i>');

          $.get('http://gdata.youtube.com/feeds/api/videos/' + id + '?v=2&alt=jsonc').done(function(result) {
            $("#fa").remove();

            var data = result.data;

            $("#AddVideo .modal-content").animate({width: "1000px"}, 1000, function() {

              $("#AddVideo .result").removeClass("disabled");

              $("#AddVideo .information .title").html(data.title);
              $("#AddVideo .information .description").html(data.description);
              $("#AddVideo .image img").attr("src", data.thumbnail.hqDefault);
            });

            $(".modal-dialog").animate({right: "140px"}, 1000);
            $(".modal-footer").removeClass("disabled");

            Drupal.video = {
              label: data.title,
              description: data.description,
              address: {video_url: value}
            };
          });
        }
      });
    }
  };

  /**
   * Sending the youtube video.
   */
  Drupal.behaviors.DrupalHubVideoCreate = {
    attach: function(context, settings) {
      $(".modal-footer button").click(function() {
        $(this).parent().append('<i id="fa" class="fa fa-spin fa-spinner"></i>');

        $.ajax({
          type: 'POST',
          beforeSend: function (request) {
            request.setRequestHeader("X-CSRF-Token", settings.plyalist.csrfToken);
          },
          url: settings.basePath + "api/v1/youtube",
          dataType: "json",
          contentType: "application/json",
          data: Drupal.video,
          error: function(result) {
            $("#fa").remove();
            $(this).parent().append('<i class="fa fa-thumbs-down"></i>');
            var json = jQuery.parseJSON(result.responseText).errors;

            if (json.address != null) {
              $(".errors").html(json.address.join("<br />"));
            }
          },
          success: function(data) {
            $("#fa").remove();
            $(".modal-footer .btn").addClass('disabled');
            $(".modal-footer .passed").removeClass('disabled');
          }
        });
      });
    }
  };

})(jQuery);
