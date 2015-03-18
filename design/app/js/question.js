DrupalHub.controller('questionCtrl', function($scope, $http, SERVER) {
  $scope.questions = {};

  $http.get(SERVER + 'question').
    success(function(data, status) {
      $scope.questions = data.data;
    });
});
