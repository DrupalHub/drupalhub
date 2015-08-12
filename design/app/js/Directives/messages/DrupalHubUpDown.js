DrupalHub.directive('drupalhubMessages', function($scope) {
  return {
    restrict: 'E',
    templateUrl: 'js/Directives/messages/element.html',
    link: function($scope) {

      $scope.types = {
        'danger': [],
        'success': [],
        'warning': [],
        'info': []
      };

      $scope.$on('DrupalHubMessagesDanger', function(event, data) {
        $scope.types.danger.push('foo');
      });

    }
  };
});
