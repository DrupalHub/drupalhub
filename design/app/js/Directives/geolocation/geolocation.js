DrupalHub.directive('drupalhubGeoLocation', function() {
  return {
    restrict: 'AE',
    templateUrl: 'js/Directives/geolocation/element.html',
    link: function(scope) {
      scope.autocompleteOptions = {};
      scope.autocompleteModel = '';

      scope.$on('gmPlacesAutocomplete::placeChanged', function(){

        // Get place
        console.dir(autocompleteModel.getPlace());

        // Get bounds
        console.dir(autocompleteModel.getBounds());

      });
    }
  };
});
