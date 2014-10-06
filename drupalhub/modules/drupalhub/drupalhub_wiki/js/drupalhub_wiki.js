(function($) {

  Drupal.behaviors.AutoCompleteSearch = {
    attach: function() {

      var countries = new Bloodhound({
        datumTokenizer: Bloodhound.tokenizers.obj.whitespace('name'),
        queryTokenizer: Bloodhound.tokenizers.whitespace,
        limit: 10,
        remote: {
          // todo: handle the filter option.
          url: Drupal.settings.baseURL + 'api/v1/wiki',
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
          empty: [
            '<div class="empty-message">',
            Drupal.t('unable to find any Best Picture winners that match the current query'),
            '</div>'
          ].join('\n'),
          suggestion: Handlebars.compile('<a href="{{self}}">{{label}}</a> <Br />' + Drupal.t('Category: ') + '{{category}}')
        }
      });

    }
  };

})(jQuery);