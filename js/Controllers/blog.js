DrupalHub.controller('blogCtrl', function($scope, DrupalHubRequest, $location, $routeParams) {

  var path;
  if ($location.url() == '/') {
    // Check if the user can post new blogs.
    $scope.canPostNewBlogs = false;
    DrupalHubRequest.userAccess('create blog content').success(function(data) {
      $scope.canPostNewBlogs = data.data.access;
    });

    path = 'blog?range=5';
  }
  else {
    path = 'blog';
    if ($routeParams['id']) {
      path += '/' + $routeParams['id'];
    }
  }


  // Get the blogs.
  $scope.blogs = {};
  $scope.waiting = true;

  DrupalHubRequest.localRequest('get', path).success(function(data) {
    $scope.blogs = $routeParams['id'] ? data.data[0] : data.data;
    $scope.waiting = false;
  });

});
