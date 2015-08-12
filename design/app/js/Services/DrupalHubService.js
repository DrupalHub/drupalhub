DrupalHub.factory('DrupalHubRequest', function($http, Config, localStorageService) {
  var DrupalHubSvc = {};

  /**
   * Load the access token.
   */
  DrupalHubSvc.accessToken = localStorageService.get('access_token');

  /**
   * Load the user object.
   */
  DrupalHubSvc.userObject = localStorageService.get('userObject');

  /**
   * Invoke a request to the local backend.
   *
   * @param method
   *   The method we need to invoke: GET, POST
   * @param address
   *   The local address.
   * @param data
   *   The request payload.
   *
   * @returns {*}
   */
  DrupalHubSvc.localRequest = function(method, address, data) {
    return $http({
      method: method,
      url: Config.backend + address + '?XDEBUG_SESSION_START=12295',
      data: data,
      headers: {
        'access-token': DrupalHubSvc.accessToken,
        'access_token': DrupalHubSvc.accessToken
      }
    });
  };

  /**
   * Check user access.
   *
   * @param permission
   *   The name of the permission we need to check.
   *
   * @returns {boolean}
   */
  DrupalHubSvc.userAccess = function(permission) {
    return $http({
      method: 'get',
      url: Config.backend + 'me',
      headers: {
        'access-token': DrupalHubSvc.accessToken,
        'access_token': DrupalHubSvc.accessToken,
        permission: permission
      }
    });
  };

  /**
   * Set a value to the local storage.
   *
   * @param key
   *   The key.
   * @param value
   *   The value.
   */
  DrupalHubSvc.set = function(key, value) {
    localStorageService.set(key, value);
  };

  /**
   * Get back the value form the local storage.
   *
   * @param key
   *   The name of the key.
   *
   * @returns {*}
   */
  DrupalHubSvc.get = function(key) {
    return localStorageService.get(key);
  };

  /**
   * Get the local storage service.
   *
   * @returns localStorageService
   */
  DrupalHubSvc.getLocalStorage = function() {
    return localStorageService;
  };

  /**
   * Get the config service.
   *
   * @returns {*}
   */
  DrupalHubSvc.getConfig = function() {
    return Config;
  };

  return DrupalHubSvc;
});
