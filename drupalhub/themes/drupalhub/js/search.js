(function($) {

  Drupal.behaviors.Search = {
    attach: function() {
      $("#search").submit(function(event) {
        event.preventDefault();
        window.location = Drupal.settings.hub.basePath + "/search_results/" + $(this).find("input").val();
      });
    }
  };

})(jQuery);
