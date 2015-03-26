DrupalHub.directive('autoComplete', function($location, DrupalHubRequest) {
  return {
    restrict: 'AE',
    templateUrl: 'js/Directives/autocomplete/element.html',
    scope: {
      endpoint: '@',
      id: '@',
      placeholder: '@'
    },
    link: function($scope) {
      $scope.tags = '';

      $scope.request = function() {
        $scope.results = [];

        DrupalHubRequest.localRequest('get', $scope.endpoint + '?autocomplete[string]=drupal').success(function(data) {
          angular.forEach(data.data, function(tag) {
            console.log(tag);
            $scope.results.push(tag.label);
          });
        });
      }
    }
  };
});
//
