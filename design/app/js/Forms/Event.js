DrupalHub.controller('EventFormCtrl', function($scope, DrupalHubRequest) {

  $scope.event = {
    label: '',
    location: '',
    date: '',
    text: ''
  };

  $scope.showEndDate = false;

  $scope.submit = function() {

    $scope.errors = [];

    if (!$scope.eventForm.label.$valid) {
      $scope.errors.push('The label is required field.');
    }

    if (!$scope.eventForm.location.$valid) {
      $scope.errors.push('The location is required field.');
    }

    if (!$scope.eventForm.date.$valid) {
      $scope.errors.push('The date is required field.');
    }

    if (!$scope.eventForm.text.$valid) {
      $scope.errors.push('The text is required field.');
    }

  };

  $scope.today = function() {
    $scope.dt = new Date();
  };
  $scope.today();

  $scope.clear = function () {
    $scope.dt = null;
  };

  // Disable weekend selection
  $scope.disabled = function(date, mode) {
    return ( mode === 'day' && ( date.getDay() === 0 || date.getDay() === 6 ) );
  };

  $scope.toggleMin = function() {
    $scope.minDate = $scope.minDate ? null : new Date();
  };
  $scope.toggleMin();

  $scope.open = function($event) {
    $event.preventDefault();
    $event.stopPropagation();

    $scope.opened = true;
  };

  $scope.dateOptions = {
    formatYear: 'yy',
    startingDay: 1,
    showWeeks:'false'
  };

  $scope.pickerPopup = {
    closeText: 'a'
  };

  $scope.format = 'dd/MM/yyyy';

});
