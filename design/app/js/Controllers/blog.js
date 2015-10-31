DrupalHub.controller('blogCtrl', function($scope, DrupalHubRequest, $location, $routeParams, $rootScope, dialogs) {

  // Get the blogs.
  $scope.blogs = {};

  DrupalHubRequest.localRequest('get', 'blog/' + $routeParams['id'] + '?add_view=add').success(function(data) {
    $scope.blog = data.data[0];
    $rootScope.$emit('titleAlter', data.data[0].label);
  });

  // Delete the blog.
  $scope.blogQuestion = function() {
    var dlg = dialogs.confirm('Delete the blog', 'Are you sure you want to delete this blog?');

    dlg.result.then(function() {
      DrupalHubRequest.localRequest('delete', 'blog/' + $scope.blog.id);
      dialogs.notify('Deleted', 'The blog has deleted.');
      window.location = "#/";
    });
  };

});
