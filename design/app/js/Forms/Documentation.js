DrupalHub.controller('DocumentationFormCtrl', function($scope, DrupalHubRequest, $location, $routeParams) {

  $scope.documentation = {
    label: '',
    text: '',
    tags: ''
  };

  if ($location.path() != '/add-documentation') {
    DrupalHubRequest.localRequest('get', 'wiki/' + $routeParams['id']).then(function(data) {
      var documentation = data.data.data[0];
      $scope.documentation.label = documentation.label;
      $scope.documentation.text = documentation.text;
      $scope.documentation.tags = documentation.tags[0].label;
    });
  }

  $scope.refreshAddresses = function(address) {
    return DrupalHubRequest.localRequest('get', 'wiki_category?autocomplete[string]=' + address).then(function(response) {

      var ret = [];

      angular.forEach(response.data.data, function(value, key) {
        ret.push(value);
      });

      $scope.tags = ret;
    });
  };

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

      var request;

      if ($routeParams['id'] != undefined) {
        request = DrupalHubRequest.localRequest('patch', 'wiki/' + $routeParams['id'], $scope.documentation);
      }
      else {
        request = DrupalHubRequest.localRequest('post', 'wiki', $scope.documentation);
      }

      request.success(function(data) {
          window.location = "#/documentation/" + data.data[0].id;
        })
        .error(function(data) {
          $scope.errors.push(data.title);
        });
    }
  };
});
