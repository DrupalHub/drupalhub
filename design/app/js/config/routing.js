DrupalHub.config(function($routeProvider) {
  // Configure the route.
  $routeProvider.when('/', {
    templateUrl: 'pages/index.html',
    controller: 'headerCtrl'
  });

  $routeProvider.when('/register-signin', {
    templateUrl: 'pages/login-signup.html',
    controller: 'loginCtrl'
  });

  $routeProvider.when('/questions', {
    templateUrl: 'pages/questions.html',
    controller: 'questionCtrl'
  });

  $routeProvider.when('/question/:id', {
    templateUrl: 'pages/question.html',
    controller: 'questionCtrl'
  });

  $routeProvider.when('/add-question', {
    templateUrl: 'pages/add-question.html',
    controller: 'QuestionFormCtrl'
  });

  $routeProvider.when('/add-blog', {
    templateUrl: 'pages/add-blog.html',
    controller: 'blogCtrl'
  });

  $routeProvider.otherwise({
    templateUrl: 'pages/404.html',
    controller: 'pageNotFound'
  });
});
