DrupalHub.controller('UserProfileCtrl', function($scope, DrupalHubRequest) {
  $scope.user = false;

  // todo: check permission for this actions.
  $scope.showEditButton = true;

  DrupalHubRequest.localRequest('get', 'me').success(function(data) {
    $scope.user = data.data;
    console.log($scope.user);
  });
});
