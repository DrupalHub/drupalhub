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
  'toaster',
  'btford.socket-io'
]).controller('bodyController', function($scope, $http, Config, localStorageService, DrupalHubRequest, toaster, DrupalHubSocket) {

  DrupalHubSocket.on('newQuestion', function(data) {
    var json = JSON.parse(data);
    toaster.pop({
      type: 'info',
      title: 'There is a new question in the site',
      body: "There is a new question in the site: " + json.title + "<br /><a href='ynet.co.il'></a>",
      showCloseButton: true,
      allowHtml: true,
      bodyOutputType: 'trustedHtml'
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
}).factory('DrupalHubSocket', function (socketFactory, Config) {
    var myIoSocket = io.connect(Config.socket);

    DrupalHubSocket = socketFactory({
      ioSocket: myIoSocket
    });

    return DrupalHubSocket;
  });

