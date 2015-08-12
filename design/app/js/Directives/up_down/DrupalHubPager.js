DrupalHub.directive('drupalhubUpDown', function(DrupalHubRequest, $location) {
  return {
    restrict: 'AE',
    scope: {
      id: '@',
      type: '@',
      points: '@'
    },
    templateUrl: 'js/Directives/up_down/element.html',
    link: function($scope) {

      /**
       * Vote against up or down.
       */
      $scope.vote = function(type) {
      };
    }
  };
});
