DrupalHub.controller('documentationCtrl', function($scope, DrupalHubRequest, $routeParams, $rootScope) {

  DrupalHubRequest.localRequest('get', 'wiki/' + $routeParams.id + '?add_view=add').then(function(data) {
    $scope.documentation = data.data.data[0];
    $rootScope.$emit('titleAlter', $scope.documentation.label);
  });
});
