DrupalHub.controller('resetPasswordCtrl', function($scope, DrupalHubRequest) {

  $scope.resetPassword = function() {
    $scope.errors = [];

    if ($scope.password1 != $scope.password2) {
      $scope.errors.push('The password are not matching.');
    }
  };
});
