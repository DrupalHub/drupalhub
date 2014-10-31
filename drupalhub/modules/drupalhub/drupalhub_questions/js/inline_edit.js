(function($) {

  Drupal.behaviors.InlineEditTitle = {
    attach: function() {
      $(".pane-node-title h1").dblclick(function() {
        alert('a');
      });
    }
  };

})(jQuery);