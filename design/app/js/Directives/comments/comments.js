DrupalHub.directive('drupalHubComments', function($location, DrupalHubRequest) {
  return {
    restrict: 'AE',
    templateUrl: 'js/Directives/comments/element.html',
    link: function($scope) {

      // Display comment part.
      var path = $location.path().split('/');
      var nid = path[2];
      var type = path[1];

      DrupalHubRequest.localRequest('get', 'comments?nid=' + nid).success(function(data, status) {
        $scope.comments = data.data;
      });

      if (type == 'question') {
        $scope.title = 'Help this question';
        $scope.btnType = 'btn-primary';
      }

      // Submit a comment part.
      $scope.newComment = {
        text: '',
        nid: nid
      };

      $scope.submit = function() {
      $scope.commentsError = '';
        if ($scope.newComment.body == '') {
          $scope.commentsError = "OOPS... It's look the comment is empty.";
        }

        if ($scope.commentForm.$valid) {
          DrupalHubRequest.localRequest('post', 'comments', $scope.newComment).
            success(function(data, status) {
              $scope.comments.push(data.data[0]);
              $scope.newComment = {
                text: '',
                nid: nid
              };
            }).
            error(function(data, status) {
              console.log(data, status);
            });
        }
      };
    }
  };
});
