DrupalHub.controller('questionCtrl', function($scope, DrupalHubRequest, $location, $routeParams, $rootScope) {

  var path = $location.path();
  var endpoint;

  if ($location.path() == '/add-question') {
    $scope.question = {
      label: '',
      tags: '',
      text: ''
    };

    $scope.question.askQuestion = function() {
      $scope.titleError = false;
      $scope.bodyError = false;
      $scope.question.tags = $scope.$$childHead.search;

      if ($scope.question.title == "") {
        $scope.titleError = 'You need to populate the title.';
      }

      if ($scope.question.text == null) {
        $scope.bodyError = 'You need to populate the text';
      }

      if ($scope.questionForm.$valid) {
        DrupalHubRequest.localRequest('post', 'question', $scope.question).
        success(function(data) {
        });
      }
    }
  }
  else {

    if (['/', '/questions'].indexOf(path) != -1) {
      endpoint = $location.path() != '/questions' ? 'question?range=5' : 'question';
    }
    else {
      endpoint = 'question/' + $routeParams['id'] + '?add_view=add';
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
