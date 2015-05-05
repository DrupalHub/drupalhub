DrupalHub.directive('drupalhubGeoLocation', function() {
  return {
    restrict: 'AE',
    templateUrl: 'js/Directives/geolocation/element.html',
    link: function($scope) {

      $scope.showMap = false;

      $scope.lat = undefined;
      $scope.lng = undefined;

      $scope.$on('gmPlacesAutocomplete::placeChanged', function(){
        var location = $scope.autocomplete.getPlace().geometry.location;
        $scope.lat = location.lat();
        $scope.lng = location.lng();
        $scope.showMap = true;
      });

    }
  };
});
