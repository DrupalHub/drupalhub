angular.module('DrupalHubConfig', [])
  .constant('SERVER', 'http://localhost/drupalhub/www/api/');

// Implements for flag directive the address for endpoint.
angular.module('flagConfig', []).constant('flagConfig', {
  'server': 'http://localhost/drupalhub/www/api/'
});
