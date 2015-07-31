DrupalHub.controller('questionCtrl', function($scope, DrupalHubRequest, $routeParams, $rootScope) {

  DrupalHubRequest.localRequest('get', 'question/' + $routeParams['id'] + '?add_view=add').then(function(data) {
    $scope.question = data.data.data[0];
    $rootScope.$emit('titleAlter', $scope.question.label);
  });
});
