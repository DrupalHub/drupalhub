DrupalHub.controller('QuestionFormCtrl', function($scope, DrupalHubRequest, $http, Config) {
  $scope.loadingLocations = false;
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
      DrupalHubRequest.localRequest('post', 'question', $scope.question).
        success(function(data) {
          window.location = "#/question/" + data.data[0].id;
        });
    }
  }
});
