DrupalHub.controller('eventsCtrl', function($scope, DrupalHubRequest, $location, $filter) {

  $scope.events = {};
  $scope.waiting = true;
  $scope.type = 'future';

  $scope.status = $scope.type == 'future' ? $filter('translate')('past events') : $filter('translate')('future event');

  DrupalHubRequest.localRequest('get', $location.path() == "" ? 'event?range=10&type=future' : 'event').
    success(function(data) {
      $scope.events = data.data;
      $scope.waiting = false;
    });

  $scope.switchEvent = function() {
    $scope.events = {};
    $scope.waiting = true;
    $scope.type = $scope.type == 'future' ? 'past' : 'future';
    $scope.status = $scope.type == 'future' ? $filter('translate')('past events') : $filter('translate')('future event');

    DrupalHubRequest.localRequest('get', 'event?range=10&type=' + $scope.type).
      success(function(data, status) {
        $scope.events = data.data;
        $scope.waiting = false;
      });
  }

});
