DrupalHub.controller('VideoFormCtrl', function($scope, DrupalHubRequest, $http) {

  $scope.video = {
    address: '',
    label: ''
  };

  $scope.showUrl = true;

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
      $scope.showUrl = false;
      var result = data.data.items[0];

      $scope.video.label = result.snippet.title;
      $scope.video.text = result.snippet.description;

      console.log(result);
    });
  };

});
