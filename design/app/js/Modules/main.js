var DrupalHub = angular.module('DrupalHub', ['DrupalHubConfig', 'ngRoute', 'LocalStorageModule']);

// Since we using jekyll we can't use {{}} as interpreter.
DrupalHub.config(function($interpolateProvider) {
  $interpolateProvider.startSymbol('{ {');
  $interpolateProvider.endSymbol('} }');
});

// Controller that will wrap the entire application.
DrupalHub.controller('headerCtrl', function($scope, DrupalHubRequest) {
  $scope.userName = 'Login/Sign in';
  $scope.userLink = 'register-signin.html';

  if (DrupalHubRequest.accessToken) {
    var userObject;

    if (userObject = DrupalHubRequest.userObject) {
      $scope.userName = userObject.label;
      $scope.userLink = 'profile.html';
    }
    else {

      DrupalHubRequest.localRequest('GET', 'me')
        .success(function(data, status) {
          var user = data.data;
          DrupalHubRequest.set('userObject', user);
          $scope.userName = user.label;
      });
    }
  }
});

