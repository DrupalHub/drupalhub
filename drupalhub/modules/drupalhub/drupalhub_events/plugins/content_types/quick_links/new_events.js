(function($) {

  /**
   * Interact when the modal for new event opened.
   */
  Drupal.behaviors.NewEventModalOpen = {
    attach: function() {
      $('#NewEvent').on('shown.bs.modal', function () {
        var settings = {
          format: "dd/mm/yyyy",
          todayBtn: "linked",
          lang: "he",
          orientation: "auto right",
          autoclose: true,
          todayHighlight: true
        };

        $("#date").datepicker(settings);
        $("#end_date").datepicker(settings);
      });
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
        title.CheckEmpty(Drupal.t("This is a required field."));
        description.CheckEmpty(Drupal.t("This is a required field."));
        start_date.CheckEmpty(Drupal.t("You need to set a date for the event."));


        if (end_date_on) {
          end_date.CheckEmpty(Drupal.t("You need to fill the end date."));
        }

        if (!$.FormStatus) {
          return;
        }

        $(this).AddSpinner();
        var format = "YYYY-MM-DD HH:mm:s";

        var FormattedDate = $.ProcessDate(start_date.val());

        var data = {
          label: title.val(),
          body: description.val(),
          start: {value: moment(FormattedDate).format(format)},
          end: {value: moment(FormattedDate).format(format)}
        };

        if (end_date_on) {
          data.end.value = moment($.ProcessDate(end_date.val())).format(format);
        }

        $.DrupalHubAjax('POST', 'api/v1/event', data)
          .error(function (result) {
            console.log(result);
          })
          .success(function(result) {
            $.DrupalHubFormSuccess();

            $(".passed span a").attr('href', result.data[0].self);
          });
      });
    }
  };

})(jQuery);
