DrupalHub.controller('blogCtrl', function($scope, DrupalHubRequest, $routeParams) {

  // Check if the user can post new blogs.
  $scope.canPostNewBlogs = false;
  DrupalHubRequest.userAccess('create blog content').success(function(data) {
    $scope.canPostNewBlogs = data.data.access;
  });


  // Get the blogs.
  $scope.blogs = {};

  DrupalHubRequest.localRequest('get', 'blog').success(function(data) {
    $scope.blogs = data.data;
  });

});
