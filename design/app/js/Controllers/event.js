DrupalHub.controller('eventCtrl', function($scope, DrupalHubRequest, $routeParams) {
  $scope.event = false;

  DrupalHubRequest.localRequest('get', 'event/' + $routeParams.id).then(function(data) {
    $scope.event = data.data.data[0];
  });

  $scope.rsvpStatus = 'Unknown';

  $scope.rsvp = function(status) {
    $scope.rsvpStatus = status;
  };
});
