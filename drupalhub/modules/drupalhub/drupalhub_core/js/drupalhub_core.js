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

  jQuery.setFormStatus = function() {

  };

  /**
   * Adding errors to a given field.
   */
  jQuery.fn.SetError = function(error) {
    if ($(this).parent().find(".errors").length == 0) {
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
    $("#" + parent).find(".form-group").removeClass('has-error');
    $("#" + parent).find("textarea, input").removeClass('error');
    $("#" + parent).find("div.error").remove();
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
      url: Drupal.settings.baseURL + path,
      dataType: "json",
      contentType: "application/json",
      data: data
    });
  };

})(jQuery);