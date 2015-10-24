DrupalHub.controller('bodyController', function($scope, $http, Config, localStorageService, DrupalHubRequest, ngToast, DrupalHubPusher) {

  DrupalHubPusher.bind('new question',
    function(data) {
      $scope.pushed = data;
      DrupalHubRequest.localRequest('get', 'me').success(function(data) {
        if ($scope.pushed.uid == data.data.id) {
          return;
        }

        ngToast.create({
          className: 'info',
          content: "There is a new question in the site: <a href='#/question/" + $scope.pushed.nid + "'>" + $scope.pushed.title + "</a>",
          dismissButton: true,
          timeout: 5000
        });
      });
    }
  );

  if (localStorageService.get('expire_in') == null || localStorageService.get('refresh_token') == null) {
    return;
  }

  if (new Date().getTime() > localStorageService.get('expire_in')) {
    // Get the new refresh token.
    DrupalHubRequest.localRequest('get', 'refresh-token/' + localStorageService.get('refresh_token')).
      success(function(data) {
        localStorageService.set('access_token', data.access_token);
        localStorageService.set('refresh_token', data.refresh_token);
        localStorageService.set('expire_in', new Date().getTime() + data.expires_in);
      });
  }
});
