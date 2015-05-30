DrupalHub.controller('frontPage', function($scope, DrupalHubRequest) {

  $scope.assets = {
    question: {},
    blog: {},
    videos: {},
    events: {}
  };
  $scope.permissions = {};
  $scope.waiting = true;

  DrupalHubRequest.localRequest('get', 'front_page').
    success(function(data) {
      var content = data.data.content;

      $scope.assets.question = content.question[0];
      $scope.assets.blog = content.blog[0];
      $scope.assets.videos = content.videos[0];
      $scope.assets.events = content.events[0];

      $scope.permission = data.data.permissions;
      $scope.waiting = false;

      console.log($scope.permission);
    });

});
