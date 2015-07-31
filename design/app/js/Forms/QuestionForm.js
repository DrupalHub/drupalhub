DrupalHub.controller('QuestionFormCtrl', function($scope, DrupalHubRequest, $location, $routeParams) {
  $scope.tags = [];
  $scope.refreshAddresses = function(address) {
    return DrupalHubRequest.localRequest('get', 'tags?autocomplete[string]=' + address).then(function(response) {

      var ret = [];

      angular.forEach(response.data.data, function(value, key) {
        ret.push(value);
      });

      $scope.tags = ret;
    });
  };

  $scope.question = {
    label: '',
    tags: '',
    text: ''
  };

  if ($location.path() != '/add-question') {
    DrupalHubRequest.localRequest('get', 'question/' + $routeParams['id']).then(function(data) {
      var question = data.data.data[0];

      var tags = [];
      angular.forEach(question.tags, function(value) {
        tags.push(value.label);
      });

      $scope.question.label = question.label;
      $scope.question.tags = tags;
      $scope.question.text = question.text;
    });
  }

  $scope.question.askQuestion = function() {
    $scope.titleError = false;
    $scope.bodyError = false;

    if ($scope.question.label == "") {
      $scope.titleError = 'You need to populate the title.';
    }

    if ($scope.question.text == null) {
      $scope.bodyError = 'You need to populate the text';
    }

    if ($scope.questionForm.$valid) {
      var request;

      if ($routeParams['id'] != undefined) {
        request = DrupalHubRequest.localRequest('PATCH', 'question/' + $routeParams['id'], $scope.question);
      }
      else {
        request = DrupalHubRequest.localRequest('post', 'question', $scope.question);
      }

      request.success(function(data) {
        window.location = "#/question/" + data.data[0].id;
      })
    }
  }
});
