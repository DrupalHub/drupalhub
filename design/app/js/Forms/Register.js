/**
 * Sign up controller.
 */
DrupalHub.controller('registerCtrl', function($scope, DrupalHubRequest) {

  $scope.user = {

  };

  $scope.register = function() {

    DrupalHubRequest.localRequest('post', 'update', $scope.user)
      .error(function(data) {
        console.log(data);
      })
      .then();
  }

});
