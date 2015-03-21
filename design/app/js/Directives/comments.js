DrupalHub.directive('drupalHubComments', function($location, DrupalHubRequest) {
  return {
    restrict: 'AE',
    templateUrl: 'pages/comments.html',
    link: function($scope) {
      var nid = $location.path().split('/')[2];

      DrupalHubRequest.localRequest('get', 'comments?nid=' + nid).success(function(data, status) {
        $scope.comments = data.data;
      });
    }
  };
});
