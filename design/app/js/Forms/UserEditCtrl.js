DrupalHub.controller('UserEditCtrl', function($scope, DrupalHubRequest, Config) {

  $scope.endpoint = Config.backend + 'drupalhub-file-upload';
  $scope.selectedForm = 'pages/user-picture.html';
  $scope.password = {
    one: '',
    two: ''
  };

  DrupalHubRequest.localRequest('get', 'me').then(function(data) {
    $scope.user = data.data.data;

    if ($scope.user.settings == null) {
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
    }
    else {
      console.log('a');
      $scope.notifications = $scope.user.settings;
    }
  });

  $scope.switchTemplate = function(template) {
    $scope.selectedForm = 'pages/user-' + template + '.html';
  };

  $scope.userDetailsSave = function() {
    $scope.errors = [];
    $scope.pass = false;

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

    if (!$scope.userDetailsForm.$valid) {
      return;
    }

    var data = {
      'label': $scope.user.label,
      'mail': $scope.user.mail,
      'first_name': $scope.user.first_name,
      'last_name': $scope.user.last_name
    };

    if ($scope.password.one) {
      data.password = $scope.password.one;
    }

    if ($scope.user.about) {
      data.about = $scope.user.about;
    }

    DrupalHubRequest.localRequest('put', 'users/' + $scope.user.id, data)
      .success(function (data) {
        $scope.pass = true;
      })
      .error(function (data) {
        angular.forEach(data.errors, function(value, key) {
          console.log(key);
          $scope.userDetailsForm[key].$setValidity(key, false);

          angular.forEach(value, function(value, key) {
            $scope.errors.push(value);
          });
        });
      });
  };

  $scope.userNotificationUpdate = function() {
    var data = {
      'settings': ($scope.notifications)
    };
    DrupalHubRequest.localRequest('patch', 'users/' + $scope.user.id, data).success(function(data) {
      console.log('foo', data);
    }).error(function(data) {
      console.log('bar', data);
    });
  };
});
