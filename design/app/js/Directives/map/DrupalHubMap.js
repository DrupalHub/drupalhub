DrupalHub.directive('drupalhubMap', function() {
  return {
    restrict: 'AE',
    templateUrl: 'js/Directives/map/element.html',
    controller: function($scope, uiGmapGoogleMapApi) {
      var vm = this;

      $scope.$watch('drupalhubMapCtrl.event', function(event) {
        if (angular.isUndefined(event)) {
          return;
        }

        vm.map = {center: {latitude: event.latitude, longitude: event.longitude }, zoom: 14 };
      });
      // Do stuff with your $scope.
      // Note: Some of the directives require at least something to be defined originally!
      // e.g. $scope.markers = []


      // uiGmapGoogleMapApi is a promise.
      // The "then" callback function provides the google.maps object.
      uiGmapGoogleMapApi.then(function(maps) {

      });
    },
    controllerAs: 'drupalhubMapCtrl',
    bindToController: true,
    scope: {
      event: '='
    }
  };
});
