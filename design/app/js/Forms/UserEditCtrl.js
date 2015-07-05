DrupalHub.controller('UserEditCtrl', function($scope, DrupalHubRequest) {

  $scope.selectedForm = 'pages/user-edit.html';
  $scope.password = {
    one: '',
    two: ''
  };

  DrupalHubRequest.localRequest('get', 'me').then(function(data) {
    $scope.user = data.data.data;
  });

  $scope.switchTemplate = function(template) {
    $scope.selectedForm = 'pages/user-' + template + '.html';
  };

  $scope.notifications = {
    new_question :{
      label: 'New question',
      value: false
    },
    new_video: {
      label: 'New video',
      value: true
    }
  };

  $scope.userDetailsSave = function() {
    $scope.errors = [];

    if ($scope.password.one != $scope.password.two) {
      $scope.errors.push('The passwords are not matching!');

      $scope.userDetailsForm.passOne.$setValidity("passOne", false);
      $scope.userDetailsForm.passTwo.$setValidity("passTwo", false);
    }
    else {
      $scope.userDetailsForm.passOne.$setValidity("passOne", true);
      $scope.userDetailsForm.passTwo.$setValidity("passTwo", true);

      $scope.user.password = $scope.password.one;
    }

    var data = {
      'label': $scope.user.label,
      'mail': $scope.user.mail,
      'about': $scope.user.about
    };

    DrupalHubRequest.localRequest('put', 'users/' + $scope.user.id, data)
      .success(function (data) {
        console.log(data, 'bar');
      })
      .error(function (data) {
        console.log(data, 'foo');
      });

  }

});
