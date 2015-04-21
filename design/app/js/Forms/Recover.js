DrupalHub.controller('recoverCtrl', function($scope) {
  $scope.showRecoverForm = true;
  $scope.recover = {
    mail: ''
  };

  $scope.recover.recoverPassword = function() {
    $scope.error = '';

    if ($scope.recover.mail == "") {
      $scope.error = 'You need to populate the email field';
    }

  };

});
