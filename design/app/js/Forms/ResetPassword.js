DrupalHub.controller('resetPasswordCtrl', function($scope, DrupalHubRequest, $routeParams, localStorageService, drupalMessagesService) {

  $scope.resetPassword = function() {
    drupalMessagesService.reset();

    if ($scope.password1 != $scope.password2) {
      drupalMessagesService.danger('The password are not matching.');
      $scope.ResetPasswordForm.password1.$setValidity("password1", false);
      $scope.ResetPasswordForm.password2.$setValidity("password2", false);
    }
    else {
      $scope.ResetPasswordForm.password1.$setValidity("password1", true);
      $scope.ResetPasswordForm.password2.$setValidity("password2", true);
      angular.forEach($scope.ResetPasswordForm.$error.required, function(value, key) {
        drupalMessagesService.danger('The field ' + value.$name + ' is required.');
      });

      localStorageService.set('access_token', $routeParams['access']);
      DrupalHubRequest.accessToken = $routeParams['access'];
      DrupalHubRequest.localRequest('get', 'me').then(function(data) {
        DrupalHubRequest.localRequest('put', 'users/' + data.data.data.id, {'password': $scope.password1}).then(function(data) {
          window.location.href = '/#';
          window.location.reload();
        });
      });

    }
  };
});
