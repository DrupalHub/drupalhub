DrupalHub.controller('PlaylistCtrl', function($scope, DrupalHubRequest, $routeParams) {

  $scope.playlistObject = {};
  $scope.video = {};

  DrupalHubRequest.localRequest('get', 'playlist/' + $routeParams['id']).success(function(data) {
    $scope.playlistObject = data.data[0];
    $scope.delta = $routeParams['delta'] - 1;
    $scope.video = $scope.playlistObject.videos[$routeParams['delta'] - 1];
    $scope.youtube = '<iframe class="embed-responsive-item" src="https://www.youtube.com/embed/' + $scope.video.embed  + '?autoplay=1" frameborder="0" allowfullscreen></iframe>';
  });
});
