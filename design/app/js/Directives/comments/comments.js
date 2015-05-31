DrupalHub.directive('drupalHubComments', function($location, DrupalHubRequest) {
  return {
    restrict: 'AE',
    templateUrl: 'js/Directives/comments/element.html',
    link: function($scope) {

      $scope.canComment = false;
      DrupalHubRequest.userAccess('post comments').success(function(response) {
        $scope.canComment = response.data.access;
      });

      // Display comment part.
      var path = $location.path().split('/');
      var nid = path[2];
      var type = path[1];

      if (type != 'playlist') {
        DrupalHubRequest.localRequest('get', 'comments?nid=' + nid).success(function(data, status) {
          $scope.comments = data.data;
        });
      }

      if (type == 'question') {
        $scope.title = 'Help this question';
        $scope.btnType = 'btn-primary';
      }
      else if (['video', 'playlist'].indexOf(type) >= 0) {
        $scope.title = 'What do you think on this video?';
        $scope.btnType = 'btn-danger';

        if (type == 'playlist') {
          DrupalHubRequest.localRequest('get', 'playlist/' + nid).success(function (data) {

            DrupalHubRequest.localRequest('get', 'comments?nid=' + data.data[0].videos[path[3] - 1].id).success(function(data, status) {
              $scope.comments = data.data;
            });
          });
        }
      }
      else {
        $scope.title = 'What do you think on this blog?';
        $scope.btnType = 'btn-warning';
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
            });
        }
      };
    }
  };
});
