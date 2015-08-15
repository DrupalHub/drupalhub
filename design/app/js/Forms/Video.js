DrupalHub.controller('VideoFormCtrl', function($scope, DrupalHubRequest, $http, $location, $routeParams, drupalMessagesService) {

  $scope.video = {
    embed: '',
    label: '',
    text: ''
  };

  if ($location.path() != '/add-video') {
    DrupalHubRequest.localRequest('get', 'video/' + $routeParams['id']).then(function(data) {
      var video = data.data.data[0];

      $scope.video.label = video.label;
      $scope.video.text = video.text;
      $scope.video.embed = "https://www.youtube.com/watch?v=" + video.embed;
      $scope.getVideoDetails();
    });
  }

  $scope.getVideoDetails = function() {
    var split = $scope.video.embed.split('v=');
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

  $scope.post = function() {
    drupalMessagesService.reset();

    var request;

    if ($routeParams['id'] != undefined) {
      request = DrupalHubRequest.localRequest('patch', 'video/' + $routeParams['id'], $scope.video);
    }
    else {
      request = DrupalHubRequest.localRequest('post', 'video', $scope.video);
    }

    request.success(function(data) {
      window.location = '#/video/' + data.data[0].id;
    })
    .error(function(data) {
      if (data.detail == 'Bad Request.') {
        drupalMessagesService.danger(data.errors.embed[0]);
      }
      else {
        drupalMessagesService.danger(data.title);
      }

    });
  }

});
