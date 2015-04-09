DrupalHub.controller('BlogFormCtrl', function($scope, DrupalHubRequest) {

  $scope.blog = {
    label: '',
    text: ''
  };

  // Processing the form.
  $scope.publishBlog = function() {
    $scope.labelErrors = '';
    $scope.textErrors = '';

    if (!$scope.blog.label) {
      $scope.labelErrors = 'The field is required';
    }

    if (!$scope.blog.text) {
      $scope.textErrors = 'The field is required';
    }

    if ($scope.blogForm.$valid) {
      DrupalHubRequest.localRequest('post', 'blog', $scope.blog).
        success(function(data) {
          window.location = "#/blog/" + data.data[0].id;
        });
    }
  };
});
