DrupalHub.controller('PlaylistCtrl', function($scope, DrupalHubRequest, $routeParams) {

  $scope.playlist = {};
  $scope.video = {};

  DrupalHubRequest.localRequest('get', 'playlist/' + $routeParams['id']).success(function(data) {
    $scope.playlist = data.data[0];
    $scope.delta = $routeParams['delta'] - 1;
    $scope.video = $scope.playlist.videos[$routeParams['delta'] - 1];
    $scope.youtube = '<iframe class="embed-responsive-item" src="https://www.youtube.com/embed/' + $scope.video.embed  + '?autoplay=true" frameborder="0" allowfullscreen></iframe>';
  });
});
