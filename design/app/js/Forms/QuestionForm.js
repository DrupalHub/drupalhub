DrupalHub.controller('QuestionFormCtrl', function($scope, DrupalHubRequest) {
  $scope.loadingLocations = false;
  $scope.getTags = function(val) {

    var split = val.split(',').map(function(n) {
      return n.trim();
    });

    return DrupalHubRequest.localRequest('get', 'tags?autocomplete[string]=' + _.last(split).trim())
      .then(function(response) {

        var results = [];

        angular.forEach(response.data.data, function(value, key) {

          if (split.indexOf(value) == -1) {
            results.push(value);
          }

        });

        return _.unique(results);
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
    $scope.question.tags = $scope.$$childHead.search;

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
