DrupalHub.controller('questionCtrl', function($scope, DrupalHubRequest, $location, $routeParams, $rootScope) {

  var path = $location.path();
  var endpoint;

  // Determine if the user can ask a question.
  $scope.showNewQuestion = false;

  DrupalHubRequest.userAccess('create question content').success(function(data) {
    $scope.showNewQuestion = data.data.access;
  });

  if (path != '/add-question') {
    endpoint = $location.path() != '/questions' ? 'question?range=5' : 'question';
  }
  else {
    endpoint = 'question/' + $routeParams['id'] + '?add_view=add';
  }

  $scope.waiting = true;
  DrupalHubRequest.localRequest('get', endpoint).
    success(function(data) {
      if (['/', '/questions'].indexOf(path) != -1) {
        $scope.questions = data.data;
      }
      else {
        $scope.question = data.data[0];
        $rootScope.$emit('titleAlter', data.data[0].label);

        DrupalHubRequest.entityAccess('update', 'node', $routeParams['id']).then(function(data) {
          $scope.showEditButton = data.data.data[0];
        });

        DrupalHubRequest.entityAccess('delete', 'node', $routeParams['id']).then(function(data) {
          $scope.showDeleteButton = data.data.data[0];
        });
      }
      $scope.waiting = false;
    });
});
