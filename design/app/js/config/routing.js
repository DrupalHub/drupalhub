DrupalHub.config(function($routeProvider) {
  // Configure the route.
  $routeProvider.when('/', {
    templateUrl: 'pages/index.html',
    controller: 'headerCtrl',
    title: 'Home page'
  });

  $routeProvider.when('/register-signin', {
    templateUrl: 'pages/login-signup.html',
    controller: 'loginCtrl',
    title: 'Login/Sign in'
  });

  $routeProvider.when('/recover-password', {
    templateUrl: 'pages/recover-password.html',
    controller: 'recoverCtrl',
    title: 'Recover password'
  });

  $routeProvider.when('/reset-password/:access', {
    templateUrl: 'pages/reset-password.html',
    controller: 'resetPasswordCtrl',
    title: 'Reset password'
  });

  // Question.
  $routeProvider.when('/questions', {
    templateUrl: 'pages/questions.html',
    controller: 'questionCtrl',
    title: 'Questions'
  });

  $routeProvider.when('/question/:id', {
    templateUrl: 'pages/question.html',
    controller: 'questionCtrl'
  });

  $routeProvider.when('/add-question', {
    templateUrl: 'pages/add-question.html',
    controller: 'QuestionFormCtrl',
    title: 'Asking a question'
  });

  // Blogs.
  $routeProvider.when('/add-blog', {
    templateUrl: 'pages/add-blog.html',
    controller: 'BlogFormCtrl',
    title: 'Blogging on something'
  });

  $routeProvider.when('/blogs', {
    templateUrl: 'pages/blogs.html',
    controller: 'blogCtrl',
    title: 'Blogs'
  });

  $routeProvider.when('/blog/:id', {
    templateUrl: 'pages/blog.html',
    controller: 'blogCtrl'
  });

  // Events.
  $routeProvider.when('/events', {
    templateUrl: 'pages/events.html',
    controller: 'eventsCtrl',
    title: 'Upcoming events'
  });

  $routeProvider.when('/add-event', {
    templateUrl: 'pages/add-event.html',
    controller: 'EventFormCtrl',
    title: 'Creating event'
  });

  $routeProvider.when('/event/:id', {
    templateUrl: 'pages/event.html',
    controller: 'eventCtrl'
  });

  // Video.
  $routeProvider.when('/videos', {
    templateUrl: 'pages/videos.html',
    controller: 'videosCtrl',
    reloadOnSearch: false,
    title: 'Looking for a video'
  });

  $routeProvider.when('/video/:id', {
    templateUrl: 'pages/video.html',
    controller: 'videoCtrl'
  });

  $routeProvider.when('/playlist/:id/:delta', {
    templateUrl: 'pages/playlist.html',
    controller: 'PlaylistCtrl'
  });

  $routeProvider.when('/add-video', {
    templateUrl: 'pages/add-video.html',
    controller: 'VideoFormCtrl',
    title: 'Submitting a video'
  });

  $routeProvider.when('/add-playlist', {
    templateUrl: 'pages/add-playlist.html',
    controller: 'PlayListFormCtrl',
    title: 'Compiling a playlist'
  });

  // User.
  $routeProvider.when('/profile', {
    templateUrl: 'pages/user.html',
    controller: 'UserProfileCtrl',
    title: 'Watching your profile'
  });

  $routeProvider.when('/user/:id', {
    templateUrl: 'pages/user.html',
    controller: 'UserProfileCtrl'
  });

  $routeProvider.when('/user/edit/:id', {
    templateUrl: 'pages/edit-user.html',
    controller: 'UserEditCtrl'
  });

  // Documentation.
  $routeProvider.when('/documentations', {
    templateUrl: 'pages/documentations.html',
    controller: 'documentationsCtrl',
    title: 'All documentations'
  });

  $routeProvider.when('/documentations/term/:filter_id', {
    templateUrl: 'pages/documentations.html',
    controller: 'documentationsCtrl'
  });

  $routeProvider.when('/add-documentation', {
    templateUrl: 'pages/add-documentation.html',
    controller: 'DocumentationFormCtrl',
    title: 'Sharing information '
  });

  $routeProvider.when('/documentation/:id', {
    templateUrl: 'pages/documentation.html',
    controller: 'documentationCtrl'
  });

  // 404 and other stanz.
  $routeProvider.otherwise({
    templateUrl: 'pages/404.html',
    controller: 'pageNotFound',
    reloadOnSearch: false,
    title: '404'
  });
});

// Implements for flag directive the address for endpoint.
angular.module('flagConfig', []).constant('flagConfig', {
  'server': 'http://localhost/drupalhub/www/api/'
});

