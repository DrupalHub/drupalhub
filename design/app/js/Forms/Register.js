/**
 * Sign up controller.
 */
DrupalHub.controller('registerCtrl', function($scope, DrupalHubRequest) {

  $scope.user = {
    mail: '',
    label: '',
    pass: '',
    pass2: ''
  };

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
        password: $scope.pass
      })
        .error(function(data) {
          console.log(data);
        })
        .then();

    }
  }

});
