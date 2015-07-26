DrupalHub.controller('headerCtrl', function($scope, DrupalHubRequest) {

  $scope.headerTitle = 'Drupal.org.il';

  // Alter the access token before the flag directive http request kicks in.
  $scope.$on('flagAccessToken', function(event, data) {
    data.accessToken = DrupalHubRequest.accessToken;
  });
});
