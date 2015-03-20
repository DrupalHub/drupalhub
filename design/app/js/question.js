DrupalHub.controller('questionCtrl', function($scope, DrupalHubRequest, $location) {

  DrupalHubRequest.localRequest('get', $location.path() == "" ? 'question?range=10' : 'question').
    success(function(data, status) {
      $scope.questions = data.data;
    });
});
