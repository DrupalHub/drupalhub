DrupalHub.controller('questionCtrl', function($scope, $http, $location, SERVER) {

  var promise;
  promise = $location.path() == "" ? $http.get(SERVER + 'question?range=10') : $http.get(SERVER + 'question');

  promise.success(function(data, status) {
    $scope.questions = data.data;
  });
});
