DrupalHub.directive('autoComplete', function($location, DrupalHubRequest, $rootScope) {
  return {
    restrict: 'AE',
    templateUrl: 'js/Directives/autocomplete/element.html',
    scope: {
      endpoint: '@',
      id: '@',
      placeholder: '@',
      scope: '@',
      key: '@'
    },
    link: function($scope, elem) {
      // The search value.
      $scope.search = '';
      $rootScope.autocomplete = $scope.search;

      // Determine if we need to show the results element or hide it.
      $scope.showResults = false;

      // The user types on the keyboard. Start the search.
      $scope.request = function() {

        // Trim the results.
        var split = $scope.search.split(',').map(function(n) {
          return n.trim();
        });

        $scope.results = [];

        // Ask for results.
        DrupalHubRequest.localRequest('get', $scope.endpoint + '?autocomplete[string]=' + _.last(split).trim()).success(function(data) {

          // Loop over the results and remove existing elements.
          for (var prop in data.data) {
            var value = data.data[prop];

            if (split.indexOf(value) == -1) {
              $scope.results.push(value);
            }
          }

          // Unique the results. We don't need duplicates.
          $scope.results = _.unique($scope.results);

          if ($scope.results != '') {
            $scope.showResults = true;
          }

        });
      };

      /**
       * Check which key element was pressed.
       */
      $scope.keyHandle = function() {
        elem.on('keydown', function(e) {

          var key = e.which;

          if (key == 38 || key == 40 || key == 13) {
            e.preventDefault();
          }

          // todo: handle later.
        });
      };

      /**
       * Append the result to the autocomplete element.
       *
       * @param text
       *   The text value.
       */
      $scope.appendToElement = function(text) {
        if ($scope.search.split(',').length > 1) {
          var split = $scope.search.split(',');
          $scope.search = _.slice(split, 0, split.length - 1).join() + ', ' + text + ', ';
        }
        else {
          $scope.search = text + ', ';
        }

        $scope.showResults = false;
      }
    }
  };
});
//
