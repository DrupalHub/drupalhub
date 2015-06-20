DrupalHub.controller('PlaylistCtrl', function($scope, DrupalHubRequest, $routeParams) {

  $scope.playlistId = $routeParams['id'];

  DrupalHubRequest.localRequest('get', 'playlist/' + $scope.playlistId).success(function(data) {
    $scope.playlistObject = data.data[0];
    $scope.delta = $routeParams['delta'] - 1;
    $scope.nextVideo = $scope.playlistObject.videos[$scope.delta + 1] ? $scope.delta + 2 : false;
    $scope.previousVideo = $scope.playlistObject.videos[$scope.delta - 1] ? $scope.delta : false;
    $scope.video = $scope.playlistObject.videos[$scope.delta];
    $scope.youtube = '<iframe class="embed-responsive-item" src="https://www.youtube.com/embed/' + $scope.video.embed  + '?autoplay=1" frameborder="0" allowfullscreen></iframe>';
  });
});
