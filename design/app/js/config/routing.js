DrupalHub.config(function($routeProvider) {
  // Configure the route.
  $routeProvider.when('/', {
    templateUrl: 'pages/index.html',
    controller: 'headerCtrl',
    title: 'Home page'
  });

  $routeProvider.when('/register-signin', {
    templateUrl: 'pages/forms/login-signup.html',
    controller: 'loginCtrl',
    title: 'Login/Sign in'
  });

  $routeProvider.when('/recover-password', {
    templateUrl: 'pages/forms/recover-password.html',
    controller: 'recoverCtrl',
    title: 'Recover password'
  });

  $routeProvider.when('/reset-password/:access', {
    templateUrl: 'pages/forms/reset-password.html',
    controller: 'resetPasswordCtrl',
    title: 'Reset password'
  });

  // Comments edit.
  $routeProvider.when('/comment/:id/edit', {
    templateUrl: 'pages/forms/comment-edit.html',
    controller: 'CommentFormCtrl',
    title: 'Editing comment'
  });

  // Question.
  $routeProvider.when('/questions', {
    templateUrl: 'pages/questions.html',
    controller: 'questionsCtrl',
    title: 'Questions'
  });

  $routeProvider.when('/question/:id', {
    templateUrl: 'pages/question.html',
    controller: 'questionCtrl'
  });

  $routeProvider.when('/question/:id/edit', {
    templateUrl: 'pages/forms/add-question.html',
    controller: 'QuestionFormCtrl'
  });

  $routeProvider.when('/add-question', {
    templateUrl: 'pages/forms/add-question.html',
    controller: 'QuestionFormCtrl',
    title: 'Asking a question'
  });

  // Blogs.
  $routeProvider.when('/add-blog', {
    templateUrl: 'pages/forms/add-blog.html',
    controller: 'BlogFormCtrl',
    title: 'Blogging on something'
  });

  $routeProvider.when('/blogs', {
    templateUrl: 'pages/blogs.html',
    controller: 'blogsCtrl',
    title: 'Blogs'
  });

  $routeProvider.when('/blog/:id', {
    templateUrl: 'pages/blog.html',
    controller: 'blogCtrl'
  });

  $routeProvider.when('/blog/:id/edit', {
    templateUrl: 'pages/forms/add-blog.html',
    controller: 'BlogFormCtrl'
  });

  // Events.
  $routeProvider.when('/events', {
    templateUrl: 'pages/events.html',
    controller: 'eventsCtrl',
    title: 'Upcoming events'
  });

  $routeProvider.when('/add-event', {
    templateUrl: 'pages/forms/add-event.html',
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
    templateUrl: 'pages/forms/add-video.html',
    controller: 'VideoFormCtrl',
    title: 'Submitting a video'
  });

  $routeProvider.when('/add-playlist', {
    templateUrl: 'pages/forms/add-playlist.html',
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
    templateUrl: 'pages/forms/edit-user.html',
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
    templateUrl: 'pages/forms/add-documentation.html',
    controller: 'DocumentationFormCtrl',
    title: 'Sharing information '
  });

  $routeProvider.when('/documentation/:id/edit', {
    templateUrl: 'pages/forms/add-documentation.html',
    controller: 'DocumentationFormCtrl'
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

