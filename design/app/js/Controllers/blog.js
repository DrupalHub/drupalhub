DrupalHub.controller('blogCtrl', function($scope, DrupalHubRequest, $location, $routeParams, $rootScope) {

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
    if ($routeParams['id']) {
      $scope.blogs = data.data[0];
      $rootScope.$emit('titleAlter', data.data[0].label);
    }
    else {
      $scope.blogs = data.data;
    }

    $scope.waiting = false;
  });

});
