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

      if (DrupalHubRequest.accessToken) {
        var userObject;

        if (userObject = DrupalHubRequest.get('userObject')) {
          $scope.userName = userObject.label;
        }
        else {
          DrupalHubRequest.localRequest('GET', 'me')
            .success(function (data) {
              var user = data.data;
              DrupalHubRequest.set('userObject', user);
              $scope.userName = user.label;
            });
        }

        $scope.template = 'js/Directives/userLink/loggedin.html';
      }
      else {
        $scope.template = 'js/Directives/userLink/anonymous.html';
      }

      $scope.logout = function() {
        localStorage.clear();
        location.reload();
      }
    }
  };
});
