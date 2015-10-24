DrupalHub.controller('UserEditCtrl', function($scope, DrupalHubRequest, Config, drupalMessagesService, $filter, language) {

  $scope.endpoint = Config.backend + 'drupalhub-file-upload';
  $scope.selectedForm = 'pages/forms/user-edit.html';
  $scope.password = {
    one: '',
    two: ''
  };

  $scope.editorOptions = {
    contentsLangDirection: language.direction,
    language: language.code
  };

  $scope.translations = {
    'password1': $filter('translate')('Password'),
    'password2': $filter('translate')('Password(again)'),
    'mail':  $filter('translate')('Email')
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
      $scope.notifications = $scope.user.settings;
    }
  });

  /**
   * Switch between the forms.
   *
   * @param template
   */
  $scope.switchTemplate = function(template) {
    drupalMessagesService.reset();
    $scope.selectedForm = 'pages/forms/user-' + template + '.html';
  };

  /**
   * Update the use details.
   */
  $scope.userDetailsSave = function() {
    drupalMessagesService.reset();
    $scope.pass = false;

    if ($scope.password.one != $scope.password.two) {
      drupalMessagesService.danger($filter('translate')('The passwords are not matching!'));

      $scope.userDetailsForm[$scope.translations.password1].$setValidity("passOne", false);
      $scope.userDetailsForm[$scope.translations.password2].$setValidity("passTwo", false);
    }
    else {
      $scope.userDetailsForm[$scope.translations.password1].$setValidity("passOne", true);
      $scope.userDetailsForm[$scope.translations.password2].$setValidity("passTwo", true);

      $scope.user.password = $scope.password.one;
    }

    if ($scope.userDetailsForm[$scope.translations.mail].$invalid) {
      drupalMessagesService.danger($filter('translate')('E-mail: The field is not valid'));
    }

    drupalMessagesService.checkRequired($scope.userDetailsForm);

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
        drupalMessagesService.success($filter('translate')('All the details were updated successfully'));
      })
      .error(function (data) {
        if (data.errors instanceof Object) {
          angular.forEach(data.errors, function(value, key) {
            angular.forEach(value, function(value, key) {
              drupalMessagesService.danger($filter('translate')(value));
            });
          });
        }
        else {
          drupalMessagesService.danger($filter('translate')(data.title));
        }
      });
  };

  /**
   * Update the user notifications.
   */
  $scope.userNotificationUpdate = function() {
    drupalMessagesService.reset();
    var data = {
      'settings': ($scope.notifications)
    };
    DrupalHubRequest.localRequest('patch', 'users/' + $scope.user.id, data);
    drupalMessagesService.success($filter('translate')('Your settings has been updated.'));
  };

  /**
   * Update the user picture file ID.
   */
  $scope.updateUserFid = function($file, $message, $flow) {
    $scope.user.image = JSON.parse($message).data[0].id;
    $scope.showSaveButton = true;
  };

  /**
   * Updating the picture relation in the DB.
   */
  $scope.userPictureUpdate = function() {
    drupalMessagesService.reset();
    var data = {
      'image_fid': $scope.user.image
    };
    drupalMessagesService.success($filter('translate')('Your profile picture has updated.'));
    DrupalHubRequest.localRequest('patch', 'users/' + $scope.user.id, data);
  }
});
