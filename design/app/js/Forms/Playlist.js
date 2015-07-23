DrupalHub.controller('PlayListFormCtrl', function($scope, DrupalHubRequest) {

  $scope.results = '';
  $scope.videos = [];

  $scope.$watch('results', function(value) {
    if (value == undefined) {
      return;
    }

    if (value.originalObject == undefined) {
      return;
    }

    $scope.videos.push(value.originalObject);
  });

  $scope.compilePlaylist = function() {
    console.log($scope.videos);
  };

  $scope.alterRemoterResponse = function() {
    console.log('foo');
    debugger;
  };

});
