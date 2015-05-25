DrupalHub.directive('drupalhubGeoLocation', function() {
  return {
    restrict: 'AE',
    scope: {
      latitude: '=',
      longitude: '='
    },
    templateUrl: 'js/Directives/geolocation/element.html',
    link: function($scope) {

      $scope.showMap = false;

      $scope.lat = undefined;
      $scope.longitude = undefined;

      $scope.$on('gmPlacesAutocomplete::placeChanged', function(){
        var location = $scope.autocomplete.getPlace().geometry.location;
        $scope.latitude = location.lat();
        $scope.longitude = location.lng();
      });

    }
  };
});
