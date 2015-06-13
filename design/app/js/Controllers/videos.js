DrupalHub.controller('videosCtrl', function($scope, DrupalHubRequest, $location) {

  $scope.videos = {};
  $scope.playlists = {};
  $scope.page = 1;
  $scope.videosSearch = '';
  $scope.playlistSearch = '';
  $scope.showPager = true;

  var page = $location.search().page == undefined ? 1 : $location.search().page;

  DrupalHubRequest.localRequest('get', 'video?range=12&page=' + page).success(function(data) {
    $scope.videos = data.data;
    $scope.page++;
  });

  DrupalHubRequest.localRequest('get', 'playlist').success(function(data) {
    $scope.playlists = data.data;
  });

  // Search for videos.
  $scope.searchVideo = function() {
    if (this.videosSearch.length == 0) {
      DrupalHubRequest.localRequest('get', 'video?range=12&page=' + page).success(function(data) {
        $scope.videos = data.data;
        $scope.showPager = true;
      });
    }
    else {
      DrupalHubRequest.localRequest('get', 'video?autocomplete[string]=' + this.videosSearch).success(function(data) {
        $scope.videos = data.data;
        $scope.showPager = false;
      });
    }
  };

  // Search for playlists.
  $scope.searchPlaylist = function() {
    if (this.playlistSearch.length == 0) {
      DrupalHubRequest.localRequest('get', 'playlist').success(function(data) {
        $scope.playlists = data.data;
      });
    }
    else {
      DrupalHubRequest.localRequest('get', 'playlist?autocomplete[string]=' + this.playlistSearch).success(function(data) {
        $scope.playlists = data.data;
      });
    }
  };

});
