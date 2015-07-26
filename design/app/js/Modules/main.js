var DrupalHub = angular.module('DrupalHub', [
  'DrupalHubConfig',
  'ngRoute',
  'LocalStorageModule',
  'chieffancypants.loadingBar',
  'ngAnimate',
  'ngCkeditor',
  'ngSanitize',
  'flagDirective',
  'ui.bootstrap',
  'ui.bootstrap.datetimepicker',
  'ngToast',
  'gm',
  'pusher-angular',
  'flow',
  'angucomplete-alt',
  'uiGmapgoogle-maps',
  'ui.select'
]);

DrupalHub.config(function(uiGmapGoogleMapApiProvider) {
  uiGmapGoogleMapApiProvider.configure({
    v: '3.17',
    libraries: 'weather,geometry,visualization'
  });
});

DrupalHub.controller('bodyController', function($scope, $http, Config, localStorageService, DrupalHubRequest, ngToast, DrupalHubPusher) {

  DrupalHubPusher.bind('new question',
    function(data) {
      ngToast.create({
        className: 'info',
        content: "There is a new question in the site: <a href='#/question/" + data.nid + "'>" + data.title + "</a>",
        dismissButton: true,
        timeout: 5000
      });
    }
  );

  if (localStorageService.get('expire_in') == null || localStorageService.get('refresh_token') == null) {
    return;
  }

  if (new Date().getTime() > localStorageService.get('expire_in')) {
    // Get the new refresh token.
    DrupalHubRequest.localRequest('get', 'refresh-token/' + localStorageService.get('refresh_token')).
      success(function(data) {
        localStorageService.set('access_token', data.access_token);
        localStorageService.set('refresh_token', data.refresh_token);
        localStorageService.set('expire_in', new Date().getTime() + data.expires_in);
      });
  }
});

DrupalHub.factory('DrupalHubPusher', function ($pusher, Config) {
  var client = new Pusher(Config.pusher_key);
  var pusher = $pusher(client);
  pusher.subscribe(Config.pusher_channel);

  return pusher;
});
