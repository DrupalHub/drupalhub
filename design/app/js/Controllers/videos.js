DrupalHub.controller('videosCtrl', function($scope, DrupalHubRequest, $location, $filter) {

  $scope.page = 1;
  $scope.videosSearch = '';
  $scope.playlistSearch = '';
  $scope.showPager = true;

  $scope.videos_title = $filter('translate')('Videos');
  $scope.playlist_title = $filter('translate')('Playlists');

  var page = $location.search().page == undefined ? 1 : $location.search().page;

  DrupalHubRequest.userAccess(['create youtube content', 'create playlist content']).then(function(data) {
    $scope.suggestYoutube = data.data.data.create_youtube_content;
    $scope.suggestPlaylist = data.data.data.create_playlist_content;
  });

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
