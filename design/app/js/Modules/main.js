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
  'gm',
  'toaster'
]).controller('bodyController', function($scope, $http, Config, localStorageService, DrupalHubRequest, toaster) {

  var socket = io(Config.socket);

  socket.on('newNode', function(data) {
    var json = JSON.parse(data);
    var message = 'WOW! there is a new content. Go <a class="notification-link" href="#/question/' + json.nid + '">' + json.title + "</a>";
    toaster.pop('success', "title", "text");
  });


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

