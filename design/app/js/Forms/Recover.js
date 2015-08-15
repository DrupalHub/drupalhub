DrupalHub.controller('recoverCtrl', function($scope, DrupalHubRequest, drupalMessagesService) {
  $scope.recoverPassed = false;
  $scope.showSubmit = true;
  $scope.mail = '';

  $scope.recoverPassword = function() {
    drupalMessagesService.reset();


    if (!$scope.RecoverPasswordForm.email.$valid) {
      drupalMessagesService.danger('You need to populate the email field');
      return;
    }

    DrupalHubRequest.localRequest('post', 'recover_password', {
      'email': $scope.mail
      })
      .error(function(data) {
        drupalMessagesService.danger(data.title);
      })
      .then(function() {
        drupalMessagesService.success('Further instructions have been sent to your e-mail address.');
      });
  };

});
