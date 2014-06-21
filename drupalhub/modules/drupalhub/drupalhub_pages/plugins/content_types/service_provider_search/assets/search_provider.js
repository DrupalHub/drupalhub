
(function ($) {

  Drupal.behaviors.DrupalHubPagesSerachServiceProvider = {
    attach: function (context, settings) {
      $("#edit-search").keyup(function(event) {
        $('.carousel').html('<div class="ajax-progress"><span class="throbber"></span></div>');

        if ($(this).val() == null) {
          request = $.ajax({
            url: settings.baseURL + "service_provider"
          });

        }
        else {
          request = $.ajax({
            url: settings.baseURL + "service_provider/" + $(this).val()
          });
        }

        request.fail(function() {
          $('.carousel').html(Drupal.t('Service provider was not found.'));
        });

        request.done(function(result) {
          $('.carousel').html(result);
        });
      });
    }
  };

})(jQuery);
