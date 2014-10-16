(function($) {

  /**
   * Interact when the modal for new event opened.
   */
  Drupal.behaviors.NewEventModalOpen = {
    attach: function() {

      var settings = {
        pick12HourFormat: false,
        useSeconds: false,
        icons: {
          time: "fa fa-clock-o",
          date: "fa fa-calendar",
          up: "fa fa-arrow-up",
          down: "fa fa-arrow-down"
        }
      };

      $('#StartDate').datetimepicker(settings);
      $('#EndDate').datetimepicker(settings);
    }
  };

  /**
   * Show/hide end date.
   */
  Drupal.behaviors.ShowEndDate = {
    attach: function() {

      function show() {
        $(".end_date").removeClass('disabled');
      }

      function hide() {
        $(".end_date").addClass('disabled');
      }

      $("#end_date_on").click(function() {
        return (this.tog = !this.tog) ? show() : hide();
      });
    }
  };

  /**
   * Validate the form.
   */
  Drupal.behaviors.DrupalHubEventModalValidate = {
    attach: function() {
      $("#NewEvent button").click(function() {
        $.DrupalHubFormInit("NewEvent");

        // Init variables.
        var title = $("#title");
        var description = $("#body");
        var start_date = $("#date");
        var end_date_on = $("#end_date_on").attr("checked") == 'checked';
        var end_date = $("#end_date");

        // Verifying the elements are not empty. If so attach the message via
        // API method.
        var errors = [];

        errors.push(title.CollectErrors(Drupal.t("Title field if q required field.")));
        errors.push(description.CollectErrors(Drupal.t("The description is a required field.")));
        errors.push(start_date.CollectErrors(Drupal.t("You must supply a start date")));

        if (end_date_on) {
          errors.push(end_date.CollectErrors(Drupal.t("You need to fill the end date.")));
        }

        $.ProcessErrors('list', errors);

        if (!$.FormStatus) {
          return;
        }

        $(this).AddSpinner();

        var format = "DD/MM/YYYY HH:mm";
        var StartDate = moment(start_date.val(), format).format("YYYY-MM-DD HH:mm:s");

        var data = {
          label: title.val(),
          body: description.val(),
          start: {value: StartDate},
          end: {value: StartDate}
        };

        if (end_date_on) {
          data.end.value = moment(end_date.val(), format).format("YYYY-MM-DD HH:mm:s");
        }

        $.DrupalHubAjax('POST', 'api/v1/event', data)
          .success(function(result) {
            $.DrupalHubFormSuccess();

            $(".passed span a").attr('href', result.data[0].self);
          });
      });
    }
  };

})(jQuery);
