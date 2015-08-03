DrupalHub.directive('drupalhubPager', function(DrupalHubRequest, $location) {
  return {
    restrict: 'AE',
    scope: {
      url: '=',
      currents: '=',
      perpage: '=',
      object: '=',
      endpoint: '@'
    },
    templateUrl: 'js/Directives/pager/element.html',
    link: function($scope) {

      DrupalHubRequest.localRequest('get', $scope.endpoint).then(function(data) {
        $scope.total = data.data.count;
      });

      // Get the current page from the query argument.
      $scope.currentPage = $location.search().page == undefined ? 0 : $location.search().page - 1;

      // Wait for a change in the variables we need.
      $scope.$watchGroup(['object', 'total'], function(data) {

        if (data[0] == undefined || data[1] == undefined) {
          return;
        }

        // Calculate how many pages we have.
        $scope.pages = new Array(Math.round(data[1] / $scope.perpage));

        // Of the items in the pager has changed.
        $scope.loadPage = function(page) {

          this.$parent.currentPage = page - 1;

          $location.search('page', page);

          // Get the items which belong to this page.
          DrupalHubRequest.localRequest('get', this.$parent.endpoint + '?range=' + this.$parent.perpage + '&page=' + page).then(function(data) {
            $scope.object = data.data.data;
          });
        }
      });
    }
  };
});
