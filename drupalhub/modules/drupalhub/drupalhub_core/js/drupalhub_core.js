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

})(jQuery);
