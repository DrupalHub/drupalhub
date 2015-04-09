DrupalHub.controller('videoCtrl', function($scope, DrupalHubRequest) {

  $scope.videos = {};
  $scope.waiting = true;

  DrupalHubRequest.localRequest('get', 'video?range=5').success(function(data, status) {
    $scope.videos = data.data;
    $scope.waiting = false;
  });
});
