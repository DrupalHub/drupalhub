(function($) {

  Drupal.behaviors.DrupalHubUsersModalSubmit = {
    attach: function() {
      $("#UpdateAbout .modal-footer button").click(function() {

        $.DrupalHubFormInit('UpdateAbout');
        var about = $("#UpdateAbout #about").val();

        if (about == "") {
          $("#UpdateAbout #about").SetError(Drupal.t('This is required field'));
        }

        if (!$.FormStatus) {
          return;
        }

        $(this).AddSpinner();

        jQuery.DrupalHubAjax('PATCH', "api/v1/update_about", {
          about: about
        })
          .error(function(result) {
            console.log(result);
          })
        .success(function(result) {
          console.log(result);
          jQuery.RemoveSpinner();
        });
      });
    }
  };

})(jQuery);