DrupalHub.controller('documentationsCtrl', function($scope, DrupalHubRequest, $location, $routeParams) {
  var page = $location.search().page == undefined ? 1 : $location.search().page;

  var filter = $routeParams['filter_id'] != undefined ? '&filter[tags]=' + $routeParams['filter_id'] : '';

  $scope.endpoint = 'wiki?range=5&page=' + page + filter;

  DrupalHubRequest.localRequest('get', $scope.endpoint).success(function(data) {
    $scope.documentations = data.data;

    DrupalHubRequest.userAccess(['create wiki content', 'bypass node access']).success(function(data) {
      $scope.showCreate = data.data['create_wiki_content'] || data.data['bypass_node_access'];
    });
  });

  DrupalHubRequest.localRequest('get', 'wiki_category?range=15').success(function(data) {
    $scope.documentation_tags = data.data;
  });
});
