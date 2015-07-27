DrupalHub.controller('headerCtrl', function($scope, DrupalHubRequest) {

  $scope.headerTitle = 'Drupal.org.il';

  $scope.$on('$routeChangeStart', function(value, route) {

    if (route.title) {
      $scope.headerTitle = 'Drupal.org.il: ' + route.title;
    }
  });

  // Alter the access token before the flag directive http request kicks in.
  $scope.$on('flagAccessToken', function(event, data) {
    data.accessToken = DrupalHubRequest.accessToken;
  });
});
