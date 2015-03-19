DrupalHub.factory('DrupalHubRequest', function($http, SERVER, localStorageService) {
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
   * @returns {*}
   */
  DrupalHubSvc.localRequest = function(method, address, data) {
    return $http({
      method: method,
      url: SERVER + address,
      data: data,
      headers: {'access_token': DrupalHubSvc.accessToken}
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
   * @returns {*}
   */
  DrupalHubSvc.get = function(key) {
    return localStorageService.get(key);
  };

  return DrupalHubSvc;
});
