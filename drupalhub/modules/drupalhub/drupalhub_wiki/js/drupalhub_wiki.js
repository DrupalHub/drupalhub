(function($) {

  Drupal.behaviors.AutoCompleteSearch = {
    attach: function() {
      var element = $("#drupalhub-wiki-search-form #edit-text");
      element.keyup(function() {
        var value = $(this).val();

        $(this).AddSpinner();

        $.DrupalHubAjax("GET", "api/v1/wiki", {
          filter: {
            label: {
              value: value,
              operator: "CONTAINS"
            }
          }
        }).success(function(result) {
          var results = {};
          $.each(result.data, function(index, value) {
            results[index] = {
              self: value.self,
              label: value.label
            };
          });

          console.log(results);

          $("#edit-text").autocomplete({
            minLength: 0,
            source: results
          });
        });

        $.RemoveSpinner();
      });
    }
  };

})(jQuery);