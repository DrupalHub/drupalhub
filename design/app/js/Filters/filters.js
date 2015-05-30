DrupalHub.filter('fullHtml', ['$sce', function($sce) {
  return function(text) {
    return $sce.trustAsHtml(text);
  };
}]);

DrupalHub.filter('countAttendees', ['$sce', function($sce) {
  return function(object) {

    if (object == null) {
      return 0;
    }

    return object.length;
  };
}]);
