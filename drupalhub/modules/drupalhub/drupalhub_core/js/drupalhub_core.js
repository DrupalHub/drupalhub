(function($) {

  /**
   * Adding the spinning the next to the submit button.
   */
  jQuery.fn.AddSpinner = function() {
    $(this).after('<i class="fa fa-spinner fa-spin" id="fa-spinner"></i>');
  };

  /**
   * Return an item push that will be used when displaying the suggester.
   */
  jQuery.RemoveSpinner = function() {
    $("#fa-spinner").remove();
  };

  /**
   * Adding errors to a given field.
   */
  jQuery.fn.SetError = function(error) {
    if ($(this).parent().find(".error").length == 0) {
      $(this).after("<div class='error'></div>");
    }

    $(this).siblings('.error').html(error);
    $(this).addClass('error');
    $(this).parents('.form-group').addClass('has-error');

    $.FormStatus = false;
  };

  /**
   * Init the form by removing any class and any errors.
   *
   * @param parent
   *   The name of the selector.
   *
   * @constructor
   */
  jQuery.DrupalHubFormInit = function(parent) {
    $.FormStatus = true;
    $("#" + parent).DrupalHubResetElement();
  };

  /**
   * Resetting a specific form element.
   *
   * @constructor
   */
  jQuery.fn.DrupalHubResetElement = function() {
    $(this).find(".form-group").removeClass('has-error');
    $(this).removeClass('has-error');
    $(this).find("textarea, input").removeClass('error');
    $(this).find("div.error").remove();
  };

  /**
   * Remove the spinner and show success message.
   *
   * @constructor
   */
  jQuery.DrupalHubFormSuccess = function() {
    jQuery.RemoveSpinner();
    $(".modal-footer .btn").addClass("disabled");
    $(".modal-footer .passed").removeClass('disabled');
    $(".success").slideDown();
  };

  /**
   * Easy interaction with the restful services until i'll replace it to
   * angular.
   *
   * @param type
   *   The type: POST, GET etc. etc.
   * @param path
   *   The menu item of the path.
   * @param data
   *   The data passing to the request.
   * @returns {*}
   * @constructor
   */
  jQuery.DrupalHubAjax = function(type, path, data) {
    return $.ajax({
      type: type,
      beforeSend: function (request) {
        request.setRequestHeader("X-CSRF-Token", Drupal.settings.hub.csrfToken);
      },
      url: Drupal.settings.hub.basePath + '/' + path,
      dataType: "json",
      contentType: "application/json",
      data: data
    });
  };

  /**
   * Checking if the element is empty. When empty adding the error passing in
   * the variable.
   *
   * @param error
   *   The appended error message.
   *
   * @constructor
   */
  jQuery.fn.CheckEmpty = function(error) {
    if ($(this).val() == "") {
      $(this).SetError(error);
    }
  };

  /**
   * Collecting errors for form elements.
   *
   * @param error
   *   The error name.
   * @param object
   *   The object that the errors will be concatenate.
   *
   * @returns {{error: *, id: *}}
   *   - error: The error text.
   *   - id: The element ID's.
   * @constructor
   */
  jQuery.fn.CollectErrors = function(error, object) {
    if ($(this).val() == "") {
      $.FormStatus = false;
      object.push({error: error, id: $(this)});
    }
  };

  /**
   * Add the error manually.
   *
   * @param error
   * @constructor
   */
  jQuery.AddError = function(error, object) {
    $.FormStatus = false;
    object.push({error: error, id: ''});
  };

  /**
   * Process the errors and show the error div. You can do this with list,
   * simple UL with the errors, or in case of unknown DB error pass the watchdog
   * log ID and display that to the user.
   *
   * @param state
   *   - list: Display the errors in list.
   *   - log: Will display the log ID with some explanation.
   * @param errors
   *   Object with the errors or the DB log.
   *
   * @constructor
   */
  jQuery.ProcessErrors = function(state, errors) {
    if (errors == "") {
      return;
    }

    if (state == 'list') {
      var list = [];
      $.each(errors, function(index, value) {
        if (value != "undefined") {
          if (value.id != "") {
            value.id.SetError();
          }
          list.push("<li>" + value.error + "</li>");
        }
      });

      var data = {
        title: Drupal.t("Wow! We can't submit the form due to some error:"),
        list: list.join("")
      };

      var template = Handlebars.compile("{{title}}<br /> <ul>{{{list}}}</ul>");

      $(".errors").html(template(data)).slideDown("fast");
    }
  };

  /**
   * Converting a given string to timestamp.
   *
   * @param string
   *   The current date string.
   *
   * @constructor
   * @return Date
   */
  jQuery.ProcessDate = function(string) {
    var parts = string.split("/");
    return new Date(parts[1] + '/' + parts[0] + '/' + parts[2]);
  };

  /**
   * Redirect the user to location after a given amount of seconds.
   *
   * @param url
   *   The url address.
   * @param seconds
   *   The amount of seconds to wait.
   * @constructor
   */
  jQuery.DrupalHubRedirect = function(url, seconds) {
    window.setTimeout(function() {
      window.location.href = url;
    }, seconds * 1000);
  };

  /**
   * Apply the ckedior upon text area.
   * @constructor
   */
  jQuery.fn.DrupalHubApplyCKedtor = function() {
    CKEDITOR.replace($(this).attr('id'), {
      toolbar: [
        ['Bold', 'Italic', 'Underline', 'Source', '-', 'Cut', 'Undo', 'Redo'],
        ['-', 'JustifyLeft', 'JustifyCenter', 'JustifyRight', 'JustifyBlock', '-', 'BidiLtr', 'BidiRtl'],
        ['Link', 'Unlink', 'Anchor',  'Image', 'Table', 'HorizontalRule', 'Smiley'],
        ['Styles', 'Format', 'Font', 'FontSize']
      ]
    });
  };

  /**
   * Closing the erros modal when focusing out or the error div.
   */
  Drupal.behaviors.CloseErrosModal = {
    attach: function() {
      $(":not(.errors)").focus(function() {
        $(".errors").slideUp();
      });
    }
  };

})(jQuery);
