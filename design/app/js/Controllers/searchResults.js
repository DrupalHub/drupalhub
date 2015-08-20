DrupalHub.controller('searchResults', function($scope, DrupalHubRequest, $routeParams) {

  if ($routeParams.value != null) {
    $scope.search = $routeParams.value;
  }

  $scope.results = {};

  if ($routeParams.types != null) {
    var types = $routeParams.types.split(',');

    angular.forEach(types, function(value) {
      if (['questions', 'blogs', 'documentation', 'videos'].indexOf(value) > -1) {

        DrupalHubRequest.localRequest('get', 'search?entity_type=node&value=' + $scope.search)
          .then(function(data) {
            $scope.results.node = data.data.data.results;
          });
      }
      else {
      }
    });

  }

});
