DrupalHub.controller('searchForm', function($scope, DrupalHubRequest, drupalMessagesService) {

  $scope.searchType = {};
  $scope.search = '';

  $scope.commitSearch = function() {
    drupalMessagesService.reset();
    drupalMessagesService.checkRequired($scope.searchForm);

    if (drupalMessagesService.valid()) {
      var types = [];
      angular.forEach($scope.searchType, function(value, key) {

        if (value) {
          types.push(key);
        }
      });

      window.location = '#/search-results/' + $scope.search + '/' + types.join(',');
    }
  };
});
