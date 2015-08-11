DrupalHub.directive('drupalhubUpDown', function(DrupalHubRequest, $location) {
  return {
    restrict: 'AE',
    scope: {
      id: '@',
      type: '@'
    },
    templateUrl: 'js/Directives/up_down/element.html',
    link: function($scope) {
      $scope.$watchGroup(['id', 'type'], function(value) {
        var id = +value[0];

        if (!id) {
          return;
        }
        DrupalHubRequest.localRequest('get', 'voting_api?filter[entity_type]=' + value[1] + '&filter[entity_id]=' + id).then(function(data) {
          console.log(data);
        });
      });
    }
  };
});
