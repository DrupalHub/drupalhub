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