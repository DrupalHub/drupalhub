(function($) {

  /**
   * Apply CKEDITOR on the body.
   */
  Drupal.behaviors.ApplyCKEDITOR = {
    attach: function() {
      $(".pane-new-question a").click(function() {
        $("#body").DrupalHubApplyCKedtor();
      });
    }
  };

  /**
   * Validating the question creation for before submitting.
   */
  Drupal.behaviors.ValidateQuestionForm = {
    attach: function() {

      $("#AddQuestion .modal-footer .btn").click(function() {
        // Remove any errors.
        $.DrupalHubFormInit("AddQuestion");

        // Processing the form.
        var title = $("#title");
        var body = $("#body");

        var errors = [];

        title.CollectErrors(Drupal.t("Title field is a required field."), errors);

        if ($(".modal-body iframe").contents().find("body").text() == "") {
          $.AddError(Drupal.t('The body is a required field.'), errors);
        }

        $.ProcessErrors('list', errors);

        if (!$.FormStatus) {
          return;
        }

        $('#AddQuestion .modal-footer .btn').AddSpinner();

        $.DrupalHubAjax('POST', "api/v1/question", {
          label: title.val(),
          body: CKEDITOR.instances.body.getData(),
          tags: $("#tags").val()
        }).success(function(result) {
          $.DrupalHubFormSuccess();
          $(".success a").attr('href', result.self);
          $.DrupalHubRedirect(result.self, 1);
        });
      });
    }
  };

  /**
   * Handling the tags input. Since we using a simple input text we can't use
   * FAPI for the autocomplete with tags so we need to implement the same UX.
   */
  Drupal.behaviors.DrupalHubQuetionTags = {
    attach: function() {
      function split(val) {
        return val.split(/,\s*/);
      }
      function extractLast(term) {
        return split(term).pop();
      }

      $("#tags").on('click', function() {
        // Get the value and check what the last the tag the user entered.
        var value = $(this).val();
        var tags = value.split(",");
        var last = tags.pop().trim();

        tags = _.map(tags, function(value) {
          return value.trim()
        });

        $(".tags .fa-refresh").addClass('fa-spin');

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
          $(".tags .fa-refresh").removeClass('fa-spin');

          $.each(result.data, function(index, value) {
            if (_.contains(tags, value.label)) {
              return 1;
            }

            FoundTags.push(value.label);
          });

          $('#tags').autocomplete({
            source: function(request, response) {
              response($.ui.autocomplete.filter(FoundTags, extractLast(request.term)));
              $(".tags .fa-refresh").removeClass('fa-spin');
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
    }
  };

})(jQuery);