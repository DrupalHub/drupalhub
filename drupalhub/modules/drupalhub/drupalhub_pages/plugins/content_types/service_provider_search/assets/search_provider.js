
(function ($) {

  Drupal.behaviors.DrupalHubPagesSerachServiceProvider = {
    attach: function (context) {
      $("#edit-search").keypress(function() {
        alert('a');
      });
    }
  };

})(jQuery);
