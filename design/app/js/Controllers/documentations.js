DrupalHub.controller('documentationsCtrl', function($scope, DrupalHubRequest, $location, $routeParams) {
  var page = $location.search().page == undefined ? 1 : $location.search().page;

  console.log($routeParams);

  if ($routeParams['filter_id'] != undefined) {
    console.log($routeParams['filter_id']);
  }

  var filter = $routeParams['filter_id'] != undefined ? '&filter[tags]=' + $routeParams['filter_id'] : '';

  $scope.endpoint = 'wiki?range=5&page=' + page + filter;

  DrupalHubRequest.localRequest('get', $scope.endpoint).success(function(data) {
    $scope.documentations = data.data;

    DrupalHubRequest.userAccess('create wiki content').success(function(data) {
      $scope.showCreate = data.data.access;
    });
  });

  DrupalHubRequest.localRequest('get', 'wiki_category?range=15').success(function(data) {
    $scope.documentation_tags = data.data;
  });
});
