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

  DrupalHubRequest.localRequest('get', path).success(function(data) {
    $scope.user = $routeParams.id ? data.data[0] : data.data;

    DrupalHubRequest.userAccess(access).then(function(data) {

      if (data.data.data.access) {
        $scope.editButton = "<a href='#/user/edit/" +  $scope.user.id + "'>Control panel</a>";
      }

    });
  });
});
