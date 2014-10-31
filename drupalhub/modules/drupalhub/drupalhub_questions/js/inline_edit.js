(function($) {

  Drupal.behaviors.InlineEditTitle = {
    attach: function() {
      $(".pane-node-title h1").live('dblclick', function() {
        var title = $(this).text();
        $(this).parent().html(
          '<input class="form-control" id="title" type="text" value="' + title + '" /> ' +
          '<button type="button" id="update_title" class="btn btn-primary">' + Drupal.t('Update') + '</button>');
      });
    }
  };

  Drupal.behaviors.SendInlineEdititng = {
    attach: function() {
      $("#update_title").live('click', function() {
        $(this).attr("class", "btn btn-success");
        $(this).html('Saved!');

        $.DrupalHubSleep(3);

        $(".pane-node-title").html("<h1>" + $("#title").val() + "</h1>");
      });
    }
  }

})(jQuery);