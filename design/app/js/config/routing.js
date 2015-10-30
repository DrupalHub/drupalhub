DrupalHub.config(function($routeProvider, $locationProvider) {

  // Configure the route.
  $routeProvider.when('/', {
    templateUrl: 'pages/index.html',
    title: 'Home page',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/register-signin', {
    templateUrl: 'pages/forms/login-signup.html',
    title: 'Login/Sign in',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/recover-password', {
    templateUrl: 'pages/forms/recover-password.html',
    title: 'Recover password',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/reset-password/:access', {
    templateUrl: 'pages/forms/reset-password.html',
    title: 'Reset password',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  // Comments edit.
  $routeProvider.when('/comment/:id/edit', {
    templateUrl: 'pages/forms/comment-edit.html',
    title: 'Editing comment',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  // Question.
  $routeProvider.when('/questions', {
    templateUrl: 'pages/questions.html',
    title: 'Questions',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/question/:id', {
    templateUrl: 'pages/question.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/question/:id/edit', {
    templateUrl: 'pages/forms/add-question.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/add-question', {
    templateUrl: 'pages/forms/add-question.html',
    title: 'Asking a question',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  // Blogs.
  $routeProvider.when('/add-blog', {
    templateUrl: 'pages/forms/add-blog.html',
    title: 'Blogging on something',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/blogs', {
    templateUrl: 'pages/blogs.html',
    title: 'Blogs',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/blog/:id', {
    templateUrl: 'pages/blog.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/blog/:id/edit', {
    templateUrl: 'pages/forms/add-blog.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  // Events.
  $routeProvider.when('/events', {
    templateUrl: 'pages/events.html',
    title: 'Upcoming events',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/add-event', {
    templateUrl: 'pages/forms/add-event.html',
    title: 'Creating event',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/event/:id', {
    templateUrl: 'pages/event.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  // Video.
  $routeProvider.when('/videos', {
    templateUrl: 'pages/videos.html',
    title: 'Looking for a video',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/video/:id', {
    templateUrl: 'pages/video.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/video/:id/edit', {
    templateUrl: 'pages/forms/add-video.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/playlist/:id/:delta', {
    templateUrl: 'pages/playlist.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/add-video', {
    templateUrl: 'pages/forms/add-video.html',
    title: 'Submitting a video',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/add-playlist', {
    templateUrl: 'pages/forms/add-playlist.html',
    title: 'Compiling a playlist',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  // User.
  $routeProvider.when('/profile', {
    templateUrl: 'pages/user.html',
    title: 'Watching your profile',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/user/:id', {
    templateUrl: 'pages/user.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/user/edit/:id', {
    templateUrl: 'pages/forms/edit-user.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  // Documentation.
  $routeProvider.when('/documentations', {
    templateUrl: 'pages/documentations.html',
    title: 'All documentations',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/documentations/term/:filter_id', {
    templateUrl: 'pages/documentations.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/add-documentation', {
    templateUrl: 'pages/forms/add-documentation.html',
    title: 'Sharing information ',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/documentation/:id/edit', {
    templateUrl: 'pages/forms/add-documentation.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/documentation/:id', {
    templateUrl: 'pages/documentation.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  // Search.
  $routeProvider.when('/search', {
    templateUrl: 'pages/forms/search.html',
    'title': 'Search',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  $routeProvider.when('/search-results/:value/:types', {
    templateUrl: 'pages/search-results.html',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  // 404 and other stanz.
  $routeProvider.otherwise({
    templateUrl: 'pages/404.html',
    controller: 'pageNotFound',
    reloadOnSearch: false,
    title: '404',
    resolve: {
      message: function (drupalMessagesService) {
        return drupalMessagesService.reset();
      }
    }
  });

  //$locationProvider.html5Mode({
  //  enabled: true,
  //  requireBase: false
  //});

});
