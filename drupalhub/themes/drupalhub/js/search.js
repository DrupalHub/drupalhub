(function($) {

  Drupal.behaviors.Search = {
    attach: function() {
      $("#search").submit(function(event) {
        event.preventDefault();
        var value = $(this).find("input").val();

        if (!value) {
          return;
        }

        window.location = Drupal.settings.hub.basePath + "/search_results/node/" + value;
      });
    }
  };

})(jQuery);
