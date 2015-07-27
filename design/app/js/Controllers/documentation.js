DrupalHub.controller('documentationCtrl', function($scope, DrupalHubRequest, $routeParams, $rootScope) {

  DrupalHubRequest.localRequest('get', 'wiki/' + $routeParams.id).then(function(data) {
    $scope.documentation = data.data.data[0];
    $rootScope.$emit('titleAlter', $scope.documentation.label);
  });
});
