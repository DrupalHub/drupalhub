(function($) {

  Drupal.behaviors.DrupalHubUsersModalSubmit = {
    attach: function() {
      $("#UpdateAbout .modal-footer button").click(function() {

        $.DrupalHubFormInit('UpdateAbout');

        if ($("#UpdateAbout #about").val() == "") {
          $("#UpdateAbout #about").SetError(Drupal.t('This is required field'));
        }

        if (!$.FormStatus) {
          return;
        }

        $(this).AddSpinner();

//        jQuery.DrupalHubAjax('PATCH', "api/v1/update_about", {
//          about: 'a'
//        })
//        .success(function(result) {
//          console.log(result);
//          jQuery.RemoveSpinner();
//        });
      });
    }
  };

})(jQuery);