DrupalHub.controller('BlogFormCtrl', function($scope, DrupalHubRequest, $location, $routeParams, drupalMessagesService) {

  $scope.blog = {
    label: '',
    text: ''
  };

  if ($location.path() != '/add-blog') {
    DrupalHubRequest.localRequest('get', 'blog/' + $routeParams['id']).then(function(data) {
      var blog = data.data.data[0];

      $scope.blog.label = blog.label;
      $scope.blog.text = blog.text;
    });
  }

  // Processing the form.
  $scope.publishBlog = function() {

    drupalMessagesService.reset();
    drupalMessagesService.checkRequired($scope.blogForm);

    if ($scope.blogForm.$valid) {
      var request;

      if ($routeParams['id'] != undefined) {
        request = DrupalHubRequest.localRequest('PATCH', 'blog/' + $routeParams['id'], $scope.blog);
      }
      else {
        request = DrupalHubRequest.localRequest('post', 'blog', $scope.blog);
      }

      request.success(function(data) {
        window.location = "#/blog/" + data.data[0].id;
      });
    }
  };
});
