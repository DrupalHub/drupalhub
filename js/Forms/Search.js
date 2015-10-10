DrupalHub.controller('searchForm', function($scope, DrupalHubRequest, drupalMessagesService, $filter) {

  $scope.searchType = {};
  $scope.search = {};

  $scope.commitSearch = function() {
    drupalMessagesService.reset();
    drupalMessagesService.checkRequired($scope.searchForm);

    var types = [];
    angular.forEach($scope.searchType, function(value, key) {

      if (value) {
        types.push(key);
      }
    });

    if (types.length == 0) {
      drupalMessagesService.danger($filter('translate')('You need to select filters!'));
    }

    if (drupalMessagesService.valid()) {
      window.location = '#/search-results/' + $scope.search.search + '/' + types.join(',');
    }
  };
});
