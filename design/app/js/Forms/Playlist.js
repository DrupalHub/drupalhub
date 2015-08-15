DrupalHub.controller('PlayListFormCtrl', function($scope, DrupalHubRequest, drupalMessagesService) {

  $scope.results = '';
  $scope.videos = [];
  $scope.ids = [];
  $scope.playlist = {
    'label': '',
    'text': '',
    'videos': []
  };

  $scope.updateVideos = function(value) {
    $scope.videos.push(value.originalObject);
    $scope.ids.push(+value.originalObject.id);
  };

  /**
   * Alter the results for the auto complete widget. This how we prevent from
   * selected videos to appear.
   */
  $scope.alterResults = function(value) {

    if ($scope.ids.length == 0) {
      return value;
    }

    var results = [];

    for (var i = 0; i < value.data.length; i++) {
      if ($scope.ids.indexOf(+value.data[i].id) == -1) {
        results.push(value.data[i]);
      }
    }

    return {data: results};
  };

  /**
   * Delete the selected video from the list.
   */
  $scope.removeSelectedVideo = function(video) {
    var id = +video.id;
    var index = $scope.ids.indexOf(id);
    $scope.ids.splice(index, 1);

    var videos = [];

    for (var i = 0; i < $scope.videos.length; i++) {

      if ($scope.videos[i].id == id) {
        continue;
      }

      videos.push($scope.videos[i]);
    }

    $scope.videos = videos;
  };

  /**
   * Submitting the playlist.
   */
  $scope.compilePlaylist = function() {
    drupalMessagesService.reset();

    drupalMessagesService.checkRequired($scope.PlaylistForm);

    if ($scope.ids.length < 3) {
      drupalMessagesService.danger('Playlist should be more then 3 videos');
      $scope.PlaylistForm.videos.$setValidity("videos", false);
    }
    else {
      $scope.PlaylistForm.videos.$setValidity("videos", true);
    }

    if (!$scope.PlaylistForm.$valid) {
      return;
    }

    // Submit the form.
    $scope.playlist.videos = $scope.ids;

    DrupalHubRequest.localRequest('post', 'playlist', $scope.playlist)
      .success(function(data) {
        window.location = "#/playlist/" + data.data[0].id + "/1";
      })
      .error(function(data) {
        $scope.error.push(data.title);
      });

  };

});
