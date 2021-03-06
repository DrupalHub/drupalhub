DrupalHub.controller('DocumentationFormCtrl', function($scope, DrupalHubRequest, $location, $routeParams, drupalMessagesService, $filter, language) {

  $scope.documentation = {
    label: '',
    text: '',
    tags: ''
  };

  $scope.editorOptions = {
    contentsLangDirection: language.direction,
    language: language.code
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
    drupalMessagesService.reset();
    var tags = true;

    drupalMessagesService.checkRequired($scope.documentationForm);

    if (!$scope.documentation.tags) {
      drupalMessagesService.danger($filter('translate')('empty field', {'name': $filter('translate')('Tags')}));
      tags = false;
    }

    if ($scope.documentationForm.$valid && tags) {

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
