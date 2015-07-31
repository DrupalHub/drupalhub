DrupalHub.controller('blogsCtrl', function($scope, DrupalHubRequest, $location, $routeParams, $rootScope) {

  // Get the blogs.
  $scope.blogs = {};
  $scope.waiting = true;

  DrupalHubRequest.localRequest('get', 'blog').success(function(data) {
    $scope.blogs = data.data;
    $scope.waiting = false;
  });

});
