DrupalHub.controller('headerCtrl', function($scope, DrupalHubRequest, $rootScope, $translate) {

  $scope.headerTitle = 'Drupal.org.il';

  $scope.$on('$routeChangeStart', function(value, route) {

    if (route.title) {
      $translate(route.title).then(function(translation) {
        $scope.headerTitle = 'Drupal.org.il: ' + translation;
        $scope.headerDescription = translation;
      });
    }
    else {
      $rootScope.$on('titleAlter', function(info, value) {
        $scope.headerTitle = 'Drupal.org.il: ' + value;
        $scope.headerDescription = value;
      });
    }
  });

  // Alter the access token before the flag directive http request kicks in.
  $scope.$on('flagAccessToken', function(event, data) {
    data.accessToken = DrupalHubRequest.accessToken;
  });
});
