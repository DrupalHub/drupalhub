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
          about: about,
          id: Drupal.settings.hub_user.id
        })
        .success(function(result) {
          jQuery.DrupalHubFormSuccess();
          Drupal.result = result;
        });
      });
    }
  };


  /**
   * The modal closed. Update the missing about text after closing.
   */
  Drupal.behaviors.DrupalHubAboutModalClose = {
    attach: function() {
      $('#UpdateAbout').on('hidden.bs.modal', function () {
        if (Drupal.result.about == "") {
          return;
        }

        $(".pane-about .pane-content").html(Drupal.result.about);
      });
    }
  }

})(jQuery);