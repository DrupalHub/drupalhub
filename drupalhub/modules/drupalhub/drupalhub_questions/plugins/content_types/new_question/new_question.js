(function($) {

  /**
   * Validating the question creation for before submitting.
   */
  Drupal.behaviors.ValidateQuestionForm = {
    attach: function (context, settings) {

      $("#AddQuestion .modal-footer .btn").click(function() {
        // Remove any errors.
        $.DrupalHubFormInit("AddQuestion");

        // Processing the form.
        var title = $("#title").val();
        var body = $("#body").val();
        var status = true;

        if (title == "") {
          $("#title").SetError(Drupal.t('The title field is required.'));
        }

        if (body == "") {
          $("#body").SetError(Drupal.t('The body field is required.'));
        }

        if ($.FormStatus) {
          return;
        }

        $('#AddQuestion .modal-footer .btn').AddSpinner();

        $.DrupalHubAjax('POST', "api/v1/question", {
          label: title,
          body: body,
          tags: $("#tags").val()
        })
        .error(function() {
          jQuery.RemoveSpinner();
        })
        .success(function(result) {
          jQuery.RemoveSpinner();
          $(".modal-footer .btn").addClass("disabled");
          $(".modal-footer .passed").removeClass('disabled');
          $(".modal-footer .passed span a").attr("href", result.self);
        });
      });
    }
  };

  /**
   * Handling the tags input. Since we using a simple input text we can't use
   * FAPI for the autocomplete with tags so we need to implement the same UX.
   */
  Drupal.behaviors.DrupalHubQuetionTags = {
    attach: function(context, settings) {

      function split(val) {
        return val.split( /,\s*/ );
      }
      function extractLast(term) {
        return split(term).pop();
      }

      $("#tags").keyup(function() {
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
          filter: {
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