/**
 * Sign up controller.
 */
DrupalHub.controller('registerCtrl', function($scope, DrupalHubRequest, $http, $rootScope, vcRecaptchaService, drupalMessagesService) {

  $scope.user = {
    mail: '',
    label: '',
    pass: '',
    pass2: ''
  };

  $scope.model = {
    key: '6Le8PAsTAAAAAElF_dS-x94G9TRRPrU4qf59usSh'
  };

  $scope.RegisterSuccess = false;

  $scope.register = function() {
    drupalMessagesService.reset();

    if (vcRecaptchaService.getResponse() === "") {
      drupalMessagesService.danger("Please resolve the captcha and submit!")
    }
    else {
      DrupalHubRequest.localRequest('post', 'recaptcha', {response: vcRecaptchaService.getResponse()})
        .then(function(data) {
          if (!data.data.data.passed) {
            drupalMessagesService.danger('The reacptcha process has failed.');
          }
        });
    }

    $scope.errors = {
      mail: '',
      label: '',
      pass: '',
      pass2: ''
    };

    if (!$scope.registerForm.mail.$dirty) {
      drupalMessagesService.danger('E-mail: The field is required');
    }

    if ($scope.registerForm.mail.$dirty && $scope.registerForm.mail.$invalid) {
      drupalMessagesService.danger('E-mail: The field is not valid');
    }

    if (!$scope.registerForm.label.$dirty) {
      drupalMessagesService.danger('Name: The field is required');
    }

    if (!$scope.registerForm.pass.$dirty) {
      drupalMessagesService.danger('Password: The field is required');
    }

    if (!$scope.registerForm.pass2.$dirty) {
      drupalMessagesService.danger('Password(again): The field is required');
    }

    if ($scope.user.pass != $scope.user.pass2) {
      $scope.registerForm.pass2.$setValidity('required', false);
      drupalMessagesService.danger('Password: The passwords are not matching!');
    }

    if ($scope.registerForm.$valid) {
      DrupalHubRequest.localRequest('post', 'users', {
        mail: $scope.user.mail,
        label: $scope.user.label,
        password: $scope.user.pass
      })
      .error(function(data) {
        var errors = data.errors;

        if (errors.mail != undefined) {
          drupalMessagesService.danger(errors.mail.join());
        }

        if (errors.label != undefined) {
          drupalMessagesService.danger(errors.label.join());
        }
      })
      .then(function() {
        // Display the message.
          drupalMessagesService.success('Welcome ' + $scope.user.label + '!');

        // Login the user and redirect him the front page.
        $http.get(DrupalHubRequest.getConfig().backend + 'login-token',{
          headers: {'Authorization': 'Basic ' + Base64.encode($scope.user.label + ':' + $scope.user.pass)}
        }).success(function(data) {
          DrupalHubRequest.getLocalStorage().set('access_token', data.access_token);

          $http.get(DrupalHubRequest.getConfig().backend + 'me', {
            headers: {'access_token': data.access_token}
          }).success(function(data) {
            $rootScope.$broadcast('userLoggedIn', data.data);
          });
        });
      });
    }
  }

});
