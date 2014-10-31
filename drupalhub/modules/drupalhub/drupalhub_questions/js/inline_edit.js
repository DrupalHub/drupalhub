(function($) {

  Drupal.behaviors.InlineEditTitle = {
    attach: function() {
      $(".pane-node-title h1").on('dblclick', function() {
        var title = $(this).text();
        $(this).parent().html(
          '<input class="form-control" id="title" type="text" value="' + title + '" /> ' +
          '<button type="button" id="update_title" class="btn btn-primary">' + Drupal.t('Update') + '</button>');
      });
    }
  };

  Drupal.behaviors.SendInlineEdititng = {
    attach: function() {
      $(".pane-node-title").on('click', "#update_title", function() {

        var data = {
          id: Drupal.settings.nid,
          "label": $("#title").val()
        };
        $.DrupalHubAjax('PATCH', "api/v1/question", data)
          .success(function(result) {
            $(this).attr("class", "btn btn-success");
            $(this).html('Saved!');
            $(".pane-node-title").html("<h1>" + $("#title").val() + "</h1>");
            window.location.href = result.url;
          });
      });
    }
  }

})(jQuery);