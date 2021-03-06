DrupalHub.controller('CommentFormCtrl', function($scope, DrupalHubRequest, $routeParams, language) {

  $scope.editorOptions = {
    contentsLangDirection: language.direction,
    language: language.code
  };

  $scope.comment = {
    text: ''
  };

  DrupalHubRequest.localRequest('get', 'comments/' + $routeParams['id']).then(function(data) {
    $scope.comment.text = data.data.data[0].text;
  });

  $scope.FormSubmit = function() {
    DrupalHubRequest.localRequest('patch', 'comments/' + $routeParams['id'], $scope.comment).then(function(data) {
      window.location = "#/" + data.data.data[0].nid.type + "/" + data.data.data[0].nid.nid;
    });
  };

});
