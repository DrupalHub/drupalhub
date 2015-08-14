DrupalHub.controller('videoCtrl', function($scope, DrupalHubRequest, $routeParams, $rootScope, dialogs) {

  $scope.video = {};
  $scope.youtube = '';
  $scope.other_videos = false;
  $scope.page = 2;
  $scope.show_more = false;

  var id = $routeParams['id'];

  DrupalHubRequest.localRequest('get', 'video/' + id).success(function(data) {
    $scope.video = data.data[0];
    $scope.youtube = '<iframe class="embed-responsive-item" src="https://www.youtube.com/embed/' + $scope.video.embed  + '?autoplay=true" frameborder="0" allowfullscreen></iframe>';
    $rootScope.$emit('titleAlter', $scope.video.label);
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

  /**
   * Delete the video.
   */
  $scope.deleteVideo = function() {
    var dlg = dialogs.confirm('Delete the video', 'Are you sure you want to delete this video?');

    dlg.result.then(function() {
      DrupalHubRequest.localRequest('delete', 'video/' + $scope.video.id);
      dialogs.notify('Deleted', 'The video has deleted.');
      window.location = "#/";
    });
  };
});
