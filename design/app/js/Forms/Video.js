DrupalHub.controller('VideoFormCtrl', function($scope, DrupalHubRequest, $http) {

  $scope.video = {
    address: '',
    label: ''
  };

  $scope.getVideoDetails = function() {
    var split = $scope.video.address.split('v=');
    $http({
      url: "https://www.googleapis.com/youtube/v3/videos",
      params: {
        id: split[1],
        key: "AIzaSyB9GaMYWcFitmreglsphxlBIm1WO5IXUeM",
        part: "snippet,contentDetails,statistics,status"
      }
    }).then(function(data) {
      $scope.showResults = true;
      var result = data.data.items[0];

      $scope.video.label = result.snippet.title;
      $scope.video.text = result.snippet.description.replace(/(\r\n|\n|\r)/gm, "<br>");

      $scope.image = result.snippet.thumbnails.high.url;
    });
  };

  $scope.toggleLabel = function() {
    $scope.showLabel = true;
  };

  $scope.updateVideoLabel = function(event) {
    if (event.keyCode == 13) {
      $scope.showLabel = false;
    }
  };


});
