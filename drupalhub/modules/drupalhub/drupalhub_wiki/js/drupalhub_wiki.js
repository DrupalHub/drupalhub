(function($) {

  Drupal.behaviors.AutoCompleteSearch = {
    attach: function() {

      var countries = new Bloodhound({
        datumTokenizer: Bloodhound.tokenizers.obj.whitespace('name'),
        queryTokenizer: Bloodhound.tokenizers.whitespace,
        limit: 10,
        remote: {
          // todo: handle the filter option.
          url: Drupal.settings.baseURL + 'api/v1/wiki?filter[label][value]=%QUERY&filter[label][operator]=CONTAINS',
          filter: function(results) {
            var result = [];

            $.each(results.data, function(index, value) {
              result.push(value);
            });

            return result;
          }
        }
      });

      countries.initialize();

      $('.typeahead').typeahead(null, {
        name: 'countries',
        displayKey: 'name',
        source: countries.ttAdapter(),
        templates: {
          suggestion: Handlebars.compile('<a href="{{self}}">{{label}}</a> <Br />' + Drupal.t('Category: ') + '{{category}}')
        }
      });

    }
  };

})(jQuery);
