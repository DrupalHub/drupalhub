DrupalHub.directive('drupalhubMap', function() {
  return {
    restrict: 'AE',
    templateUrl: 'js/Directives/map/element.html',
    controller: function($scope, uiGmapGoogleMapApi) {
      var vm = this;

      // Do stuff with your $scope.
      // Note: Some of the directives require at least something to be defined originally!
      // e.g. $scope.markers = []

      vm.map = {center: {latitude: 51.219053, longitude: 4.404418 }, zoom: 14 };;
      vm.map = {center: {latitude: 51.219053, longitude: 4.404418 }, zoom: 14 };;

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
    controllerAs: 'drupalhubMapCtrl',
    bindToController: true,
    scope: {
      event: '='
    }
  };
});
