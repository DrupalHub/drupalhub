var DrupalHub = angular.module('DrupalHub', ['DrupalHubConfig', 'ngRoute', 'LocalStorageModule']);

// Since we using jekyll we can't use {{}} as interpreter.
DrupalHub.config(function($interpolateProvider) {
  $interpolateProvider.startSymbol('{ {');
  $interpolateProvider.endSymbol('} }');
});

// Controller that will wrap the entire application.
DrupalHub.controller('headerCtrl', function($scope, $http, SERVER, localStorageService) {
  $scope.userName = 'Login/Sign in';
  $scope.userLink = 'register-signin.html';

  var access_token;
  if (access_token = localStorageService.get('access_token')) {
    var userObject;

    if (userObject = localStorageService.get('userObject')) {
      $scope.userName = userObject.label;
      $scope.userLink = 'profile.html';
    }
    else {

      $http.get(SERVER + 'me', {
        headers: {'access_token': access_token}
      }).
      success(function(data, status) {
        var user = data.data;
        localStorageService.set('userObject', user);
        $scope.userName = user.label;
      });
    }
  }
});

