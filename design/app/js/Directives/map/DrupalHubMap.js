DrupalHub.directive('drupalhubMap', function() {
  return {
    restrict: 'AE',
    scope: {
      latitude: '=',
      longitude: '=',
      address: '='
    },
    templateUrl: 'js/Directives/map/element.html',
    link: function($scope) {
      angular.element('#maps').gMap({
        address: $scope.address,
        zoom: 16,
        controls: {
          panControl: true,
          zoomControl: true,
          mapTypeControl: true,
          scaleControl: true,
          streetViewControl: true,
          overviewMapControl: true
        }
        //markers: [{
        //  latitude: $scope.latitude,
        //  longitude: $scope.longitude,
        //  html: "Tel aviv",
        //  popup: true
        //}]
      });

    }
  };
});
