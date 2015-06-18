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
  'btford.socket-io',
  'uiGmapgoogle-maps'
]);

DrupalHub.config(function(uiGmapGoogleMapApiProvider) {
  uiGmapGoogleMapApiProvider.configure({
    //    key: 'your api key',
    v: '3.17',
    libraries: 'weather,geometry,visualization'
  });
})

DrupalHub.controller('bodyController', function($scope, $http, Config, localStorageService, DrupalHubRequest, ngToast, DrupalHubSocket) {

  DrupalHubSocket.on('newQuestion', function(data) {
    var json = JSON.parse(data);
    ngToast.create({
      className: 'info',
      content: "There is a new question in the site: <a href='#/question/" + json.nid + "'>" + json.title + "</a>",
      dismissButton: true,
      timeout: 5000
    });
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

DrupalHub.factory('DrupalHubSocket', function (socketFactory, Config) {
  var myIoSocket = io.connect(Config.socket);

  DrupalHubSocket = socketFactory({
    ioSocket: myIoSocket
  });

  return DrupalHubSocket;
});
