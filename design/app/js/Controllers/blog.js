DrupalHub.controller('blogCtrl', function($scope, DrupalHubRequest, $location, $routeParams, $rootScope) {

  // Get the blogs.
  $scope.blogs = {};

  DrupalHubRequest.localRequest('get', 'blog/' + $routeParams['id']).success(function(data) {
    $scope.blog = data.data[0];
    $rootScope.$emit('titleAlter', data.data[0].label);
    $scope.showEditButton = $scope.blog.access.update;
    $scope.showDeleteButton = $scope.blog.access.delete;
  });

});
