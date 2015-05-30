DrupalHub.controller('eventCtrl', function($scope, DrupalHubRequest, $routeParams) {
  $scope.event = false;

  DrupalHubRequest.localRequest('get', 'event/' + $routeParams.id).then(function(data) {
    $scope.event = data.data.data[0];
  });

  $scope.rsvpStatus = 'Unknown';
  $scope.rsvpID = 0;

  DrupalHubRequest.localRequest('get', 'rsvp').then(function (data) {
    if (data.data.count != 0) {
      var rsvp = data.data.data[0];

      $scope.rsvpID = rsvp.id;
      $scope.rsvpStatus = rsvp.rsvp_status;
    }
  });

  $scope.rsvp = function(status) {

    var method, path;

    if ($scope.rsvpID) {
      method = 'patch';
      path = 'rsvp/' + $scope.rsvpID;

    }
    else {
      method = 'post';
      path = 'rsvp';
    }

    DrupalHubRequest.localRequest(method, path, {
      'rsvp_status': status,
      'event': $scope.event.id
    }).then(function (data) {
      $scope.rsvpStatus = status;

      DrupalHubRequest.localRequest('get', 'event/' + $routeParams.id).then(function(data) {
        var new_event = data.data.data[0];

        // Updating the rsvp with the new data.
        $scope.event.rsvp = new_event.rsvp;
      });

    });
  };
});
