DrupalHub.controller('searchResults', function($scope, DrupalHubRequest, $routeParams, $rootScope) {

  if ($routeParams.value != null) {
    $scope.search = $routeParams.value;
    $rootScope.$emit('titleAlter', 'Search results: ' + $routeParams.value);
  }

  $scope.noResults = false;

  if ($routeParams.types != null) {
    var types = $routeParams.types.split(',');

    angular.forEach(types, function(value) {
      DrupalHubRequest.localRequest('get', 'search?entity_type=node&value=' + $scope.search + '&bundles=' + types)
        .success(function(data) {
          $scope.results = data.data.results;
        })
        .error(function() {
          $scope.noResults = true;
        });
    });
  }
});
