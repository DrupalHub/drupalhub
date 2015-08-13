DrupalHub.directive('drupalhubUpDown', function(DrupalHubRequest, drupalMessagesService) {
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
        var object = {
          entity_type: $scope.type,
          entity_id: $scope.id,
          value: type == 'up' ? 1 : -1
        };
        DrupalHubRequest.localRequest('post', 'voting_api', object)
          .success(function(data) {
            $scope.points = data.data[0].new_value;
            drupalMessagesService.reset();
            drupalMessagesService.success('Your vote has been applied.');
          })
          .error(function(data) {
            drupalMessagesService.reset();
            drupalMessagesService.danger(data.title);
          });
      };
    }
  };
});
