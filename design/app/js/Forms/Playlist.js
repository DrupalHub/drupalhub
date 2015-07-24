DrupalHub.controller('PlayListFormCtrl', function($scope, DrupalHubRequest) {

  $scope.results = '';
  $scope.videos = [];
  $scope.ids = [];

  $scope.updateVideos = function(value) {
    $scope.videos.push(value);
    $scope.ids.push(value.originalObject.id);
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
      if ($scope.ids.indexOf(value.data[i].id) == -1) {
        results.push(value.data[i]);
      }
    }

    return {data: results};
  };

  /**
   * Delete the selected video from the list.
   */
  $scope.removeSelectedVideo = function(video) {

  }

});
