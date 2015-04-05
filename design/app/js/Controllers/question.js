DrupalHub.controller('questionCtrl', function($scope, DrupalHubRequest, $location, $routeParams, $http) {

  var path = $location.path();
  var endpoint;

  // Determine if the user can ask a question.
  $scope.showNewQuestion = false;

  DrupalHubRequest.userAccess('create question content').success(function(data) {
    $scope.showNewQuestion = data.data.access;
  });

  if ($location.path() == '/add-question') {

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

      if ($scope.question.title == "") {
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
