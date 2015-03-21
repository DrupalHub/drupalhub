// Controller that will wrap the entire application.
DrupalHub.controller('headerCtrl', function($scope, DrupalHubRequest) {
  $scope.userName = 'Login/Sign in';
  $scope.userLink = '#register-signin';

  if (DrupalHubRequest.accessToken) {
    var userObject;

    if (userObject = DrupalHubRequest.userObject) {
      $scope.userName = userObject.label;
      $scope.userLink = 'profile.html';
    }
    else {

      DrupalHubRequest.localRequest('GET', 'me')
        .success(function(data, status) {
          var user = data.data;
          DrupalHubRequest.set('userObject', user);
          $scope.userName = user.label;
        });
    }
  }
});
