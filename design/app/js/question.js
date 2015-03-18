DrupalHub.controller('questionCtrl', function($scope, $http, $location, SERVER) {

  console.log($location.path());
  var promise;
  if ($location.path() == "") {
    promise = $http.get(SERVER + 'question?range=10');
  }
  else {
    promise = $http.get(SERVER + 'question');
  }

    promise.success(function(data, status) {
      $scope.questions = data.data;
    });
});
