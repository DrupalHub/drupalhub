DrupalHub.controller('eventCtrl', function($scope, DrupalHubRequest, $routeParams, $modal) {
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

      if (rsvp.rsvp_status == 'coming') {
        $scope.rsvpStatus = 'yes';
      }
    }
  });

  $scope.rsvp = function(status) {
    if (status == 'yes') {
      if ($scope.rsvpID) {

        $modal.open({
          animation: $scope.animationsEnabled,
          template: '<div class="text-center">You cannot create the same entry</div>',
          size: 'small'
        });
        return;
      }
      DrupalHubRequest.localRequest('post', 'rsvp', {
        'rsvp_status': 'coming',
        'event': $scope.event.id
      }).then(function (data) {
        $scope.rsvpStatus = 'yes';

        // todo: push the value to the $scope.event.rsvp.coming.
      });
    }
  };
});
