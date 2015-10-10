DrupalHub.controller('recoverCtrl', function($scope, DrupalHubRequest, drupalMessagesService, $filter) {
  $scope.recoverPassed = false;
  $scope.showSubmit = true;
  $scope.mail = '';

  $scope.recoverPassword = function() {
    drupalMessagesService.reset();

    var email = $filter('translate')('Email');

    if (!$scope.RecoverPasswordForm[email].$valid) {
      drupalMessagesService.danger($filter('translate')('empty field', {'name': email}));
      return;
    }

    DrupalHubRequest.localRequest('post', 'recover_password', {
      'email': $scope.mail
      })
      .error(function(data) {
        drupalMessagesService.danger(data.title);
      })
      .then(function() {
        drupalMessagesService.success($filter('translate')('Further instructions have been sent to your e-mail address.'));
      });
  };

});
