DrupalHub.controller('eventsCtrl', function($scope, DrupalHubRequest, $location) {

  $scope.events = {};
  $scope.waiting = true;
  $scope.type = 'future';

  DrupalHubRequest.localRequest('get', $location.path() == "" ? 'event?range=10&type=future' : 'event').
    success(function(data, status) {
      $scope.events = data.data;
      $scope.waiting = false;
    });

  $scope.switchEvent = function() {
    $scope.events = {};
    $scope.waiting = true;
    $scope.type = $scope.type == 'future' ? 'past' : 'future';

    DrupalHubRequest.localRequest('get', 'event?range=10&type=' + $scope.type).
      success(function(data, status) {
        $scope.events = data.data;
        $scope.waiting = false;
      });
  }

});
