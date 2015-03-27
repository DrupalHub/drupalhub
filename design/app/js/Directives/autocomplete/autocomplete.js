DrupalHub.directive('autoComplete', function($location, DrupalHubRequest) {
  return {
    restrict: 'AE',
    templateUrl: 'js/Directives/autocomplete/element.html',
    scope: {
      endpoint: '@',
      id: '@',
      placeholder: '@'
    },
    link: function($scope, elem, window) {
      // The search value.
      $scope.search = '';

      // Determine if we need to show the results element or hide it.
      $scope.showResults = false;

      // Holds the terms we need to exclude from the results.
      $scope.exclude = [];

      // The user types on the keyboard. Start the search.
      $scope.request = function() {

        DrupalHubRequest.localRequest('get', $scope.endpoint + '?autocomplete[string]=' + $scope.search).success(function(data) {
          $scope.results = data.data;

          if (data.data != '') {
            $scope.showResults = true;
          }
        });
      };

      /**
       * Check which key element was pressed.
       */
      $scope.keyHandle = function() {
        elem.on('keydown', function(e) {
          if (e.which == '38') {
            console.log('up');
          }
          else {
            console.log('down');
          }
        });
      };

      /**
       * Append the result to the autocomplete element.
       *
       * @param text
       *   The text value.
       */
      $scope.appendToElement = function(text) {
        $scope.search = text;
        $scope.exclude.push(text);
        $scope.showResults = false;
      }
    }
  };
});
//
