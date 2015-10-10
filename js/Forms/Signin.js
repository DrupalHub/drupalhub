/**
 * Login controller.
 */
DrupalHub.controller('loginCtrl', function($scope, $http, Config, localStorageService, $rootScope, drupalMessagesService, $filter) {
  $scope.user = {
    name: '',
    pass: ''
  };

  $scope.showLoginInput = true;

  $scope.user.login = function() {

    $scope.error = {
      name: '',
      pass: ''
    };

    drupalMessagesService.reset();
    drupalMessagesService.checkRequired($scope.loginForm);

    if ($scope.loginForm.$valid) {
      var response = $http.get(Config.backend + 'login-token', {
        headers: {'Authorization': 'Basic ' + Base64.encode($scope.user.name + ':' + $scope.user.pass)}
      });

      response.error(function(data) {
        if (data.title == 'Bad credentials') {
          drupalMessagesService.danger($filter('translate')('The username/password are wrong.'));
        }
      });

      response.success(function(data) {
        localStorageService.set('access_token', data.access_token);
        localStorageService.set('refresh_token', data.refresh_token);
        localStorageService.set('expire_in', new Date().getTime() + data.expires_in);

        $http.get(Config.backend + 'me', {
          headers: {
            'access-token': data.access_token,
            'access_token': data.access_token
          }
        }).success(function(data) {
          $rootScope.$broadcast('userLoggedIn', data.data);
          drupalMessagesService.success($filter('translate')('welcome user', {'user': data.data.label}));
          window.location.href = (Config.front);
        });
      });
    }

  }
});
