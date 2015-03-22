DrupalHub.directive('drupalHubComments', function($location, DrupalHubRequest) {
  return {
    restrict: 'AE',
    templateUrl: 'pages/comments.html',
    link: function($scope) {

      // Display comment part.
      var path = $location.path().split('/');
      var nid = path[2];
      var type = path[1];

      DrupalHubRequest.localRequest('get', 'comments').success(function(data, status) {
        $scope.comments = data.data;
      });

      if (type == 'question') {
        $scope.title = 'Help this question';
        $scope.btnType = 'btn-primary';
      }

      // Submit a comment part.
      $scope.newComment = {
        body: ['value'],
        nid: nid
      };

      $scope.submit = function() {
      $scope.commentsError = '';
        if ($scope.newComment.body == '') {
          $scope.commentsError = "OOPS... It's look the comment is empty.";
        }

        if ($scope.commentForm.$valid) {
          $scope.newComment.body = [$scope.newComment.body];
          console.log($scope.newComment);
          DrupalHubRequest.localRequest('post', 'comments', $scope.newComment).
            success(function(data, status) {
              console.log(data, status);
            }).
            error(function(data, status) {
              console.log(data, status);
            });
        }
      };
    }
  };
});
