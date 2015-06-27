DrupalHub.controller('documentationsCtrl', function($scope, DrupalHubRequest, $location) {
  var page = $location.search().page == undefined ? 1 : $location.search().page;

  DrupalHubRequest.localRequest('get', 'wiki?range=5&page=' + page).success(function(data) {
    $scope.documentations = data.data;

    DrupalHubRequest.userAccess('create wiki content').success(function(data) {
      $scope.showCreate = data.data.access;
    });
  });

  DrupalHubRequest.localRequest('get', 'wiki_tags?range=5').success(function(data) {
    $scope.documentation_tags = data.data;
  });
});
