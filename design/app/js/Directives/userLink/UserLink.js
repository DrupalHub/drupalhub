DrupalHub.directive('drupalHubUser', function($location, DrupalHubRequest, localStorageService) {
  return {
    restrict: 'AE',
    template:'<ng-include src="template"/>',
    link: function($scope) {
      $scope.$on('userLoggedIn', function(event, data) {
        DrupalHubRequest.set('userObject', data);
        $scope.userName = data.label;
        $scope.template = 'js/Directives/userLink/loggedin.html';
      });

      // Check first the access token works.
      DrupalHubRequest.localRequest('get', 'me').success(function (data) {
        if (data.data.id == null) {
          $scope.template = 'js/Directives/userLink/anonymous.html';
        }
        else {
          DrupalHubRequest.localRequest('GET', 'me')
            .success(function (data) {
              var user = data.data;
              DrupalHubRequest.set('userObject', user);
              $scope.userName = user.label;
            });
          $scope.template = 'js/Directives/userLink/loggedin.html';
        }
      });

      $scope.logout = function() {
        localStorage.clear();
        location.reload();
      }
    }
  };
});
