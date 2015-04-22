DrupalHub.controller('recoverCtrl', function($scope, $http) {
  $scope.showRecoverForm = true;
  $scope.mail = '';

  $scope.recoverPassword = function() {
    $scope.error = '';

    if (!$scope.RecoverPasswordForm.email.$valid) {
      $scope.error = 'You need to populate the email field';
      return;
    }

  };

});
