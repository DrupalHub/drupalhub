DrupalHub.controller('questionCtrl', function($scope, DrupalHubRequest, $location, $routeParams) {

  var path = $location.path();
  var endpoint;

  if (['/', '/questions'].indexOf(path) != -1) {
    endpoint = $location.path() != '/questions' ? 'question?range=5' : 'question';
  }
  else {
    endpoint = 'question/' + $routeParams['id'];
  }

  DrupalHubRequest.localRequest('get', endpoint).
    success(function(data, status) {
      if (['/', '/questions'].indexOf(path) != -1) {
        $scope.questions = data.data;
      }
      else {
        $scope.question = data.data[0];
      }
    });
});
