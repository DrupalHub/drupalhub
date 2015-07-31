DrupalHub.controller('questionsCtrl', function($scope, DrupalHubRequest, $location, $routeParams, $rootScope) {

  $scope.waiting = true;
  DrupalHubRequest.localRequest('get', $location.path() == '/questions' ? 'question?range=5' : 'question').success(function(data) {
    $scope.questions = data.data;
    $scope.waiting = false;
  });
});
