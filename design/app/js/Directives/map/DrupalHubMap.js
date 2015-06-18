DrupalHub.directive('drupalhubMap', function() {
  return {
    restrict: 'AE',
    scope: {
      latitude: '=',
      longitude: '=',
      address: '='
    },
    templateUrl: 'js/Directives/map/element.html',
    controller: function($scope, uiGmapGoogleMapApi) {
      // Do stuff with your $scope.
      // Note: Some of the directives require at least something to be defined originally!
      // e.g. $scope.markers = []

      $scope.map = { center: { latitude: 45, longitude: -73 }, zoom: 8 };

      // uiGmapGoogleMapApi is a promise.
      // The "then" callback function provides the google.maps object.
      uiGmapGoogleMapApi.then(function(maps) {

      });

      /* From link function
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
      */


    },
    controllerAs: 'drupalhubMapCtrl'
  };
});
