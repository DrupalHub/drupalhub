DrupalHub.directive('drupalHubComments', function($location) {
  return {
    restrict: 'AE',
    templateUrl: 'pages/comments.html',
    link: function($scope) {
      console.log($location);
    }
  };
});
