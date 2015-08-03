DrupalHub.controller('questionCtrl', function($scope, DrupalHubRequest, $routeParams, $rootScope, dialogs) {

  DrupalHubRequest.localRequest('get', 'question/' + $routeParams['id'] + '?add_view=add').then(function(data) {
    $scope.question = data.data.data[0];
    $rootScope.$emit('titleAlter', $scope.question.label);
  });

  /**
   * Delete the question.
   */
  $scope.deleteQuestion = function() {
    var dlg = dialogs.confirm('Delete the question', 'Are you sure you want to delete this question?');

    dlg.result.then(function() {
      DrupalHubRequest.localRequest('delete', 'question/' + $scope.question.id);
      dialogs.notify('Deleted', 'The question has deleted.');
      window.location = "#/";
    });
  };
});
