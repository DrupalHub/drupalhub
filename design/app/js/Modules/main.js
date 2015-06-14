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
  'gm'
]).controller('bodyController', function($scope, $http, Config, localStorageService, DrupalHubRequest) {

  var socket = io(Config.socket);
  socket.on('newNode', function(data){
    console.log('A new node was created!', JSON.parse(data).title);
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
