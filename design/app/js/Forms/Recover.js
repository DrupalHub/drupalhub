DrupalHub.controller('recoverCtrl', function($scope, DrupalHubRequest) {
  $scope.recoverPassed = false;
  $scope.showSubmit = true;
  $scope.mail = '';

  $scope.recoverPassword = function() {
    $scope.error = '';

    if (!$scope.RecoverPasswordForm.email.$valid) {
      $scope.error = 'You need to populate the email field';
      return;
    }

    DrupalHubRequest.localRequest('post', 'recover_password', {
      'email': $scope.mail
      })
      .error(function(data) {
        $scope.error = data.title;
      })
      .then(function() {
        $scope.showSubmit = false;
        $scope.recoverPassed = true;
        $scope.loginResults = 'Further instructions have been sent to your e-mail address.';
      });
  };

});
