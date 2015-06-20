DrupalHub.controller('UserProfileCtrl', function($scope, DrupalHubRequest, $routeParams) {

  var path, access;

  if ($routeParams.id) {
    path = 'users/' + $routeParams.id;
    access = 'edit user:' + $routeParams.id;
  }
  else {
    path = 'me';
    access = 'edit user';
  }

  DrupalHubRequest.userAccess(access).then(function(data) {
    $scope.showEditButton = data.data.data.access;

    console.log($scope.showEditButton);
  });

  DrupalHubRequest.localRequest('get', path).success(function(data) {
    $scope.user = $routeParams.id ? data.data[0] : data.data;
  });
});
