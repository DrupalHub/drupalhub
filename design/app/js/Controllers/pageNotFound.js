DrupalHub.controller('pageNotFound', function($scope) {
  var messages = [
    'His dead JIM!',
    "This isn't the page you are looking for.",
    '404 Page... The final frontier'
  ];
  $scope.message = messages[Math.floor(Math.random() * messages.length)];
});
