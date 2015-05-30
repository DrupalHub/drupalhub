DrupalHub.controller('videoCtrl', function($scope, DrupalHubRequest, $routeParams) {

  $scope.video = {};
  $scope.youtube = '';
  $scope.other_videos = false;
  $scope.page = 2;
  $scope.show_more = false;

  var id = $routeParams['id'];

  console.log($routeParams);

  DrupalHubRequest.localRequest('get', 'video/' + id).success(function(data, status) {
    $scope.video = data.data[0];
    $scope.youtube = '<iframe class="embed-responsive-item" src="https://www.youtube.com/embed/' + $scope.video.embed  + '?autoplay=true" frameborder="0" allowfullscreen></iframe>';
  });

  DrupalHubRequest.localRequest('get', 'video?filter[id][value]=' + id + '&filter[id][operator]=<>&range=10').success(function(data, status) {
    $scope.other_videos = data.data;
    $scope.show_more = true;
  });

  $scope.loadMoreVideos = function() {

    DrupalHubRequest.localRequest('get', 'video?filter[id][value]=' + id + '&filter[id][operator]=<>&range=10&page=' + $scope.page).success(function(data) {
      var heap_videos = $scope.other_videos;

      angular.forEach(data.data, function(value, key) {
        heap_videos.push(value);
      });

      $scope.other_videos = heap_videos;
      $scope.show_more = !(heap_videos.length == data.count);
      $scope.page++;
    });
  };
});
