DrupalHub.controller('UserEditCtrl', function($scope, DrupalHubRequest) {

  DrupalHubRequest.localRequest('get', 'me').then(function(data) {
    $scope.user = data.data.data;
  });

});
