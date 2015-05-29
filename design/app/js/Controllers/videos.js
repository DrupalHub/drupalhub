DrupalHub.controller('videosCtrl', function($scope, DrupalHubRequest) {

  $scope.videos = {};
  $scope.playlists = {};

  DrupalHubRequest.localRequest('get', 'video?range=4').success(function(data) {
    $scope.videos = data.data;
  });

  DrupalHubRequest.localRequest('get', 'playlist').success(function(data) {
    $scope.playlists = data.data;
  });
});
