(function($) {

  /**
   * Replacing the title with form for a quick edit.
   */
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

  /**
   * Submitting the title quick edit form.
   */
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

  /**
   * Replace the body with a CKEDITOR instance for a quick edit of the question
   * body.
   */
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

  /**
   * Submitting the CKEDITOR form.
   */
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

  /**
   * Quick edit for the question's terms. This is pretty ugly but we need to
   * adjust the code to the bootstrap dialog library.
   */
  Drupal.behaviors.TermsInlineEdit = {
    attach: function() {
      if (Drupal.settings.drupalhub_question.access == false) {
        return;
      }

      function split(val) {
        return val.split(/,\s*/);
      }
      function extractLast(term) {
        return split(term).pop();
      }

      $(".pane-node-metatags .fa-tags").on('dblclick', function() {
        var tags = $(".tags-links").text();

        BootstrapDialog.show({
          message: function(dialogRef) {
            var $message = $('<div class="input-group">' +
            '<input type="text" class="form-control" id="tags" value="' + tags + '" placeholder="' + Drupal.t('Add tags for the question') + '">' +
            '<span class="input-group-addon"><i class="fa fa-refresh"></i></span>' +
            '</div>');

            $message.on('keyup', "input", function() {
              // Get the value and check what the last the tag the user entered.
              var value = $(this).val();
              var tags = value.split(",");
              var last = tags.pop().trim();

              tags = _.map(tags, function(value) {
                return value.trim()
              });

              $(".fa-refresh").addClass('fa-spin');

              // Suggest tags according to the last tag.
              $.DrupalHubAjax("GET", "api/v1/tags", {
                autocomplete: {
                  label: {
                    value: last,
                    operator: "CONTAINS"
                  }
                }
              }).success(function(result) {
                var FoundTags = [];
                $(".fa-refresh").removeClass('fa-spin');

                $.each(result.data, function(index, value) {
                  if (_.contains(tags, value.label)) {
                    return 1;
                  }

                  FoundTags.push(value.label);
                });

                $('#tags').autocomplete({
                  source: function(request, response) {
                    response($.ui.autocomplete.filter(FoundTags, extractLast(request.term)));
                    $(".fa-refresh").removeClass('fa-spin');
                  },
                  focus: function() {
                    return false;
                  },
                  select: function(event, ui) {
                    var terms = split(this.value);
                    terms.pop();
                    terms.push(ui.item.value);
                    terms.push("");
                    this.value = terms.join(", ");
                    return false;
                  }
                });
              })
            });

            return $message;
          },
          buttons: [
            {
              icon: 'glyphicon glyphicon-remove',
              label: ' ' + Drupal.t('Close'),
              cssClass: 'btn-danger',
              action: function(dialogItself) {
                dialogItself.close();
              }
            },
            {
              icon: 'glyphicon glyphicon-ok',
              label: ' ' + Drupal.t('Send'),
              cssClass: 'btn-success',
              action: function(dialogItself) {
                var data = {
                  id: Drupal.settings.drupalhub_question.nid,
                  tags: $("#tags").val()
                };

                $.DrupalHubAjax('PATCH', "api/v1/question", data)
                  .success(function(result) {
                    $(".tags-links").html(result.tags_output);
                  });
                dialogItself.close();
              }
            }
          ]
        });
      });
    }
  };
})(jQuery);
