var app = angular.module('QuestionApp', []);

app.controller('TitleController', ['$scope', function($scope) {
  $scope.InlineEdit = function() {
    $scope.content = 'a';
  };
}]);
