DrupalHub.controller('questionCtrl', function($scope, DrupalHubRequest, $location, $routeParams, $sce) {

  var path = $location.path();
  var endpoint;

  if ($location.path() == '/add-question') {
    $scope.question = {
      title: '',
      tags: {},
      body: ''
    };

    $scope.question.askQuestion = function() {
      $scope.titleError = false;
      $scope.bodyError = false;

      if ($scope.question.title == "") {
        $scope.titleError = 'You need to populate the title.';
      }

      if ($scope.question.body == null) {
        $scope.bodyError = 'You need to populate the text';
      }

      if ($scope.questionForm.$valid) {

      }
    }
  }
  else {

    if (['/', '/questions'].indexOf(path) != -1) {
      endpoint = $location.path() != '/questions' ? 'question?range=5' : 'question';
    }
    else {
      endpoint = 'question/' + $routeParams['id'];
    }

    DrupalHubRequest.localRequest('get', endpoint).
      success(function(data) {
        if (['/', '/questions'].indexOf(path) != -1) {
          $scope.questions = data.data;
        }
        else {
          $scope.question = data.data[0];
        }
      });
  }
});
