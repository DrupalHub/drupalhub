(function($) {

  Drupal.behaviors.InlineEditTitle = {
    attach: function() {
      if (Drupal.settings.drupalhub_question.access == false) {
        return;
      }

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
        var title = $("#title").val();

        if (title == "") {
          BootstrapDialog.alert({
            title: Drupal.t('Empty title'),
            message: Drupal.t('The title is empty. Populate it and click again')
          });
          return;
        }

        var data = {
          id: Drupal.settings.drupalhub_question.nid,
          "label": title
        };
        $.DrupalHubAjax('PATCH', "api/v1/question", data)
          .success(function(result) {
            $(".pane-node-title").html("<h1>" + $("#title").val() + "</h1>");
            window.location.href = result.url;
          });
      });
    }
  };

  Drupal.behaviors.InlineBodyEditing = {
    attach: function() {
      if (Drupal.settings.drupalhub_question.access == false) {
        return;
      }

      $(".pane-node-body .field-item").on("dblclick", function() {
        var html = $(this).html();
        $(this).html('<textarea id="question_body">' + html + '</textarea>' +
        '<div class="submit"><button type="button" id="update_body" class="btn btn-primary">' + Drupal.t('Update') + '</button></div>');
        $("#question_body").DrupalHubApplyCKedtor();
      });
    }
  };

  Drupal.behaviors.InlineBodyEditingSubmitting = {
    attach: function() {
      $(".panel-col-top .field-name-body").on('click', "#update_body", function() {
        var title = $("#title").val();
        if ($(".field-name-body iframe").contents().find("body").text() == "") {
          BootstrapDialog.alert({
            type: BootstrapDialog.TYPE_DANGER,
            title: Drupal.t('Empty body'),
            message: Drupal.t('The body is empty. Populate it and click again')
          });
          return;
        }

        var data = {
          id: Drupal.settings.drupalhub_question.nid,
          body: CKEDITOR.instances.question_body.getData()
        };

        $.DrupalHubAjax('PATCH', "api/v1/question", data)
          .success(function(result) {
            $(".panel-col-top .field-name-body").html(CKEDITOR.instances.question_body.getData());
          });
      });
    }
  };

})(jQuery);