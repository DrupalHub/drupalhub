DrupalHub.controller('eventsCtrl', function($scope, DrupalHubRequest, $location) {

  $scope.events = {};
  $scope.waiting = true;

  DrupalHubRequest.localRequest('get', $location.path() == "" ? 'event?range=10' : 'event').
    success(function(data, status) {
      $scope.events = data.data;
      $scope.waiting = false;
    });

});
