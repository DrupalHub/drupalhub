DrupalHub.controller('resetPasswordCtrl', function($scope, DrupalHubRequest, $routeParams, localStorageService, drupalMessagesService, $filter) {

  $scope.resetPassword = function() {
    drupalMessagesService.reset();
    drupalMessagesService.checkRequired($scope.ResetPasswordForm);

    var translations = {
      'password1': $filter('translate')('Password'),
      'password2': $filter('translate')('Password - verification')
    };

    if ($scope.password1 != $scope.password2) {
      drupalMessagesService.danger($filter('translate')('The password are not matching.'));
      $scope.ResetPasswordForm[translations.password1].$setValidity(translations.password1, false);
      $scope.ResetPasswordForm[translations.password2].$setValidity(translations.password2, false);
    }
    else {
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
