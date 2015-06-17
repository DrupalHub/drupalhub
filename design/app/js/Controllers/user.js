DrupalHub.controller('UserProfileCtrl', function($scope, DrupalHubRequest) {
  $scope.user = false;

  DrupalHubRequest.localRequest('get', 'me').success(function(data) {
    $scope.user = data.data;
    console.log($scope.user);
  });
});
