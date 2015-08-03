DrupalHub.directive('drupalHubComments', function($location, DrupalHubRequest, DrupalHubPusher, dialogs) {
  return {
    restrict: 'AE',
    templateUrl: 'js/Directives/comments/element.html',
    scope: {
      nid: '=',
      type: '@'
    },
    link: function($scope) {
      $scope.$watch('nid', function(nid) {

        if (nid == undefined) {
          return;
        }

        var type = $scope.type;

        $scope.canComment = false;
        DrupalHubRequest.userAccess('post comments').success(function(response) {
          $scope.canComment = response.data.access;
        });

        if (type == 'question') {
          $scope.title = 'Help this question';
          $scope.btnType = 'btn-primary';
        }
        else if (['video', 'playlist'].indexOf(type) >= 0) {
          $scope.title = 'What do you think on this video?';
          $scope.btnType = 'btn-danger';
        }
        else if (type == 'event') {
          $scope.title = 'What do you think on this event?';
          $scope.btnType = 'btn-success';
        }
        else if (type == 'documentation') {
          $scope.title = 'Any thoughts for this documentation?';
          $scope.btnType = 'btn-info';
        }
        else {
          $scope.title = 'What do you think on this blog?';
          $scope.btnType = 'btn-warning';
        }

        DrupalHubRequest.localRequest('get', 'comments?nid=' + nid).success(function(data) {
          $scope.comments = data.data;
        });

        DrupalHubPusher.bind('new comment',
          function(data) {

            if (+data.nid != nid) {
              return;
            }

            $scope.comments.push(data.object);

          }
        );

        // Submit a comment part.
        $scope.newComment = {
          text: '',
          nid: nid
        };

        /**
         * Posting the comment.
         */
        $scope.submit = function() {
          $scope.commentsError = '';
          if ($scope.newComment.body == '') {
            $scope.commentsError = "OOPS... It's look the comment is empty.";
          }

          if ($scope.commentForm.$valid) {
            DrupalHubRequest.localRequest('post', 'comments', $scope.newComment).success(function(data) {
              $scope.newComment = {
                text: '',
                nid: nid
              };
            });
          }
        };
      });

      /**
       * Delete the comment.
       */
      $scope.deleteComment = function(id, delta) {
        var dlg = dialogs.confirm('Delete the comment', 'Are you sure you want to delete this comment?');

        dlg.result.then(function() {
          DrupalHubRequest.localRequest('delete', 'comments/' + id);
          _.pullAt($scope.comments, delta);
          dialogs.notify('Deleted', 'The comment has deleted.');
        });
      }
    }
  };
});
