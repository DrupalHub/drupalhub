DrupalHub.controller('documentationCtrl', function($scope, DrupalHubRequest, $routeParams) {

  DrupalHubRequest.localRequest('get', 'wiki/' + $routeParams.id).then(function(data) {
    $scope.documentation = data.data.data[0];
  });
});
