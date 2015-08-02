DrupalHub.config(function($routeProvider) {
  // Configure the route.
  $routeProvider.when('/', {
    templateUrl: 'pages/index.html',
    title: 'Home page',
    resolve: {
      loadMyService: ['$ocLazyLoad', function($ocLazyLoad) {
        return $ocLazyLoad.load('js/Controllers/frontPage.js');
      }]
    }
  });

  $routeProvider.when('/register-signin', {
    templateUrl: 'pages/forms/login-signup.html',
    title: 'Login/Sign in'
  });

  $routeProvider.when('/recover-password', {
    templateUrl: 'pages/forms/recover-password.html',
    title: 'Recover password'
  });

  $routeProvider.when('/reset-password/:access', {
    templateUrl: 'pages/forms/reset-password.html',
    title: 'Reset password'
  });

  // Comments edit.
  $routeProvider.when('/comment/:id/edit', {
    templateUrl: 'pages/forms/comment-edit.html',
    title: 'Editing comment'
  });

  // Question.
  $routeProvider.when('/questions', {
    templateUrl: 'pages/questions.html',
    title: 'Questions'
  });

  $routeProvider.when('/question/:id', {
    templateUrl: 'pages/question.html'
  });

  $routeProvider.when('/question/:id/edit', {
    templateUrl: 'pages/forms/add-question.html'
  });

  $routeProvider.when('/add-question', {
    templateUrl: 'pages/forms/add-question.html',
    title: 'Asking a question'
  });

  // Blogs.
  $routeProvider.when('/add-blog', {
    templateUrl: 'pages/forms/add-blog.html',
    title: 'Blogging on something'
  });

  $routeProvider.when('/blogs', {
    templateUrl: 'pages/blogs.html',
    title: 'Blogs'
  });

  $routeProvider.when('/blog/:id', {
    templateUrl: 'pages/blog.html'
  });

  $routeProvider.when('/blog/:id/edit', {
    templateUrl: 'pages/forms/add-blog.html'
  });

  // Events.
  $routeProvider.when('/events', {
    templateUrl: 'pages/events.html',
    title: 'Upcoming events'
  });

  $routeProvider.when('/add-event', {
    templateUrl: 'pages/forms/add-event.html',
    title: 'Creating event'
  });

  $routeProvider.when('/event/:id', {
    templateUrl: 'pages/event.html'
  });

  // Video.
  $routeProvider.when('/videos', {
    templateUrl: 'pages/videos.html',
    reloadOnSearch: false,
    title: 'Looking for a video'
  });

  $routeProvider.when('/video/:id', {
    templateUrl: 'pages/video.html'
  });

  $routeProvider.when('/video/:id/edit', {
    templateUrl: 'pages/forms/add-video.html'
  });

  $routeProvider.when('/playlist/:id/:delta', {
    templateUrl: 'pages/playlist.html'
  });

  $routeProvider.when('/add-video', {
    templateUrl: 'pages/forms/add-video.html',
    title: 'Submitting a video'
  });

  $routeProvider.when('/add-playlist', {
    templateUrl: 'pages/forms/add-playlist.html',
    title: 'Compiling a playlist'
  });

  // User.
  $routeProvider.when('/profile', {
    templateUrl: 'pages/user.html',
    title: 'Watching your profile'
  });

  $routeProvider.when('/user/:id', {
    templateUrl: 'pages/user.html'
  });

  $routeProvider.when('/user/edit/:id', {
    templateUrl: 'pages/forms/edit-user.html'
  });

  // Documentation.
  $routeProvider.when('/documentations', {
    templateUrl: 'pages/documentations.html',
    title: 'All documentations'
  });

  $routeProvider.when('/documentations/term/:filter_id', {
    templateUrl: 'pages/documentations.html'
  });

  $routeProvider.when('/add-documentation', {
    templateUrl: 'pages/forms/add-documentation.html',
    title: 'Sharing information '
  });

  $routeProvider.when('/documentation/:id/edit', {
    templateUrl: 'pages/forms/add-documentation.html'
  });

  $routeProvider.when('/documentation/:id', {
    templateUrl: 'pages/documentation.html'
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

