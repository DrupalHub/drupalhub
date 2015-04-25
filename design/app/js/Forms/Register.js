/**
 * Sign up controller.
 */
DrupalHub.controller('registerCtrl', function($scope, DrupalHubRequest, $http, $rootScope) {

  $scope.user = {
    mail: '',
    label: '',
    pass: '',
    pass2: ''
  };

  $scope.RegisterSuccess = false;

  $scope.register = function() {
    $scope.errors = {
      mail: '',
      label: '',
      pass: '',
      pass2: ''
    };

    if (!$scope.registerForm.mail.$dirty) {
      $scope.errors.mail = 'The field is required';
    }

    if ($scope.registerForm.mail.$dirty && $scope.registerForm.mail.$invalid) {
      $scope.errors.mail = 'The field is not valid';
    }

    if (!$scope.registerForm.label.$dirty) {
      $scope.errors.label = 'The field is required';
    }

    if (!$scope.registerForm.pass.$dirty) {
      $scope.errors.pass = 'The field is required';
    }

    if (!$scope.registerForm.pass2.$dirty) {
      $scope.errors.pass2 = 'The field is required';
    }

    if ($scope.user.pass != $scope.user.pass2) {
      $scope.registerForm.pass2.$setValidity('required', false);
      $scope.errors.pass2 = 'The pass are not matching!';
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
          $scope.errors.mail = errors.mail.join();
        }

        if (errors.label != undefined) {
          $scope.errors.label = errors.label.join();
        }
      })
      .then(function() {
        // Display the message.
        $scope.RegisterSuccess = 'Welcome ' + $scope.user.label + '!';

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
