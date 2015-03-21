DrupalHub.controller('blogCtrl', function($scope, DrupalHubRequest) {

  $scope.blogs = {};

  DrupalHubRequest.localRequest('get', 'blog').success(function(data, status) {
    $scope.blogs = data.data;
  });
});
