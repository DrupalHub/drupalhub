DrupalHub.directive('drupalhubMessages', function() {
  return {
    restrict: 'E',
    templateUrl: 'js/Directives/messages/element.html',
    link: function($scope) {

      $scope.types = {
        'danger': [],
        'success': [],
        'warning': [],
        'info': []
      };

      $scope.$on('DrupalHubMessagesDanger', function(event, data) {
        $scope.types.danger.push(data);
      });

      $scope.$on('DrupalHubMessagesSuccess', function(event, data) {
        $scope.types.success.push(data);
      });

      $scope.$on('DrupalHubMessagesWarning', function(event, data) {
        $scope.types.warning.push(data);
      });

      $scope.$on('DrupalHubMessagesInfo', function(event, data) {
        $scope.types.info.push(data);
      });

      $scope.$on('DrupalHubMessagesReset', function() {
        $scope.types.danger = [];
        $scope.types.success = [];
        $scope.types.warning = [];
        $scope.types.info = [];
      });
    }
  };
});

DrupalHub.factory('drupalMessagesService', function($rootScope, $filter) {
  var drupalHubMessagesSvc = {};

  /**
   * Keeping all the errors.
   *
   * @type {Array}
   */
  var errors = [];

  /**
   * Check if there any errors.
   *
   * @returns {boolean}
   */
  drupalHubMessagesSvc.valid = function() {
    return errors.length == 0;
  };

  /**
   * Check if all the required fields are pouplated.
   *
   * @param form
   */
  drupalHubMessagesSvc.checkRequired = function(form) {
    angular.forEach(form.$error.required, function(value, key) {
      drupalHubMessagesSvc.danger($filter('translate')('empty field', {'name': value.$name}));
    });
  };

  /**
   * Reset all the messages. Should be called when setting up new messages.
   */
  drupalHubMessagesSvc.reset = function() {
    $rootScope.$broadcast('DrupalHubMessagesReset');
    errors = [];
  };

  /**
   * Sending message. This will be invoke by the other methods.
   *
   * @param type
   *   The type of the message: danger, success, warning, info.
   * @param message
   *   The message content.
   */
  drupalHubMessagesSvc.sendMessage = function(type, message) {
    $rootScope.$broadcast('DrupalHubMessages' + type, message);
  };

  /**
   * Set up a danger message aka red message.
   *
   * @param message
   *   The message.
   */
  drupalHubMessagesSvc.danger = function(message) {
    this.sendMessage('Danger', message);
    errors.push(message);
  };

  /**
   * Set up a success message aka green message.
   *
   * @param message
   *   The message.
   */
  drupalHubMessagesSvc.success = function(message) {
    this.sendMessage('Success', message);
  };

  /**
   * Set up a warning message aka yellow message.
   *
   * @param message
   *   The message.
   */
  drupalHubMessagesSvc.Warning = function(message) {
    this.sendMessage('warning', message);
  };

  /**
   * Set up a info message aka blue message.
   *
   * @param message
   *   The message.
   */
  drupalHubMessagesSvc.info = function(message) {
    this.sendMessage('Info', message);
  };

  return drupalHubMessagesSvc;
});
