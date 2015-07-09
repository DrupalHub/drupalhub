DrupalHub.controller('DocumentationFormCtrl', function($scope, DrupalHubRequest) {

  $scope.documentation = {
    label: '',
    text: '',
    tags: ''
  };

  $scope.getTags = function(val) {

    return DrupalHubRequest.localRequest('get', 'wiki_category?autocomplete[string]=' + val)
      .then(function(response) {

        var results = [];

        angular.forEach(response.data.data, function(value, key) {
          results.push(value);
        });

        return _.unique(results);
      });
  };

  $scope.errors = [];

  // Processing the form.
  $scope.submit = function() {
    $scope.errors = [];

    if (!$scope.documentation.label) {
      $scope.errors.push('The label field is required');
    }

    if (!$scope.documentation.text) {
      $scope.errors.push('The text field is required');
    }

    if (!$scope.documentation.tags) {
      $scope.errors.push('The category field is required');
    }

    if ($scope.documentationForm.$valid) {
      DrupalHubRequest.localRequest('post', 'wiki', $scope.documentation)
        .success(function(data) {
          window.location = "#/documentation/" + data.data[0].id;
        })
        .error(function(data) {
          $scope.errors.push(data.title);
        });
    }
  };
});
