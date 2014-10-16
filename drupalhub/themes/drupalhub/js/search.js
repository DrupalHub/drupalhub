(function($) {

  Drupal.behaviors.Search = {
    SearchResults: function (index) {
      return new Bloodhound({
        datumTokenizer: Bloodhound.tokenizers.obj.whitespace('name'),
        queryTokenizer: Bloodhound.tokenizers.whitespace,
        limit: 10,
        remote: {
          url: Drupal.settings.baseURL + 'api/v1/search?value=%QUERY&index=' + index,
          filter: function (results) {
            var result = [];

            $.each(results, function (index, value) {
              result.push(value);
            });

            return result;
          }
        }
      });
    },
    attach: function() {
      var tags = this.SearchResults('taxonomy_term');
      var nodes = this.SearchResults('node');
      var users = this.SearchResults('user');
      var comment = this.SearchResults('comment');

      nodes.initialize();
      users.initialize();
      tags.initialize();
      comment.initialize();

      var source = $("#search-results").html();

      $('.search .typeahead').typeahead({
          highlight: true
        },
        {
          name: 'nodes',
          displayKey: 'name',
          source: nodes.ttAdapter(),
          templates: {
            header: '<h4 class="league-name">' + Drupal.t('Content') + '</h4>',
            suggestion: Handlebars.compile(source)
          }
        },
        {
          name: 'comment',
          displayKey: 'name',
          source: comment.ttAdapter(),
          templates: {
            header: '<h4 class="league-name">' + Drupal.t('Comments') + '</h4>',
            suggestion: Handlebars.compile(source)
          }
        },
        {
          name: 'users',
          displayKey: 'name',
          source: users.ttAdapter(),
          templates: {
            header: '<h4 class="league-name">' + Drupal.t('Users') + '</h4>',
            suggestion: Handlebars.compile(source)
          }
        },
        {
          name: 'tags',
          displayKey: 'name',
          source: tags.ttAdapter(),
          templates: {
            header: '<h4 class="league-name">' + Drupal.t('Tags') + '</h4>',
            suggestion: Handlebars.compile(source)
          }
        }
      );
    }
  };

})(jQuery);
