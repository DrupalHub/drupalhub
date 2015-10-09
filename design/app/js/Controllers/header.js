DrupalHub.controller('headerCtrl', function($scope, DrupalHubRequest, $rootScope, $filter) {

  $scope.headerTitle = 'Drupal.org.il';

  $scope.$on('$routeChangeStart', function(value, route) {

    if (route.title) {
      $scope.headerTitle = 'Drupal.org.il: ' + $filter('translate')(route.title);
    }
    else {
      $rootScope.$on('titleAlter', function(info, value) {
        $scope.headerTitle = 'Drupal.org.il: ' + value;
      });
    }
  });

  // Alter the access token before the flag directive http request kicks in.
  $scope.$on('flagAccessToken', function(event, data) {
    data.accessToken = DrupalHubRequest.accessToken;
  });
});
