DrupalHub.controller('EventFormCtrl', function($scope, DrupalHubRequest) {

  var time = moment();

  $scope.event = {
    label: '',
    location: '',
    start_date: {
      date: '',
      time: ''
    },
    end_date: {
      date: '',
      time: ''
    },
    start: {
      date: '',
      time: ''
    },
    text: ''
  };

  $scope.showEndDate = false;

  $scope.submit = function() {

    $scope.errors = [];

    if (!$scope.eventForm.label.$valid) {
      $scope.errors.push('The label is required field.');
    }

    if ($scope.event.location == "") {
      $scope.errors.push('The location is required field.');
    }

    if (!$scope.event.start_date.date) {
      $scope.errors.push('The date is required field.');
    }

    if (!$scope.eventForm.text.$valid) {
      $scope.errors.push('The text is required field.');
    }

    if ($scope.errors.length == 0) {

      // Processing the date into a new date.
      $scope.event.start.date = moment($scope.event.start_date.date).format("D/M/YYYY");

      if ($scope.event.start_date.time == "") {
        $scope.event.start.time = moment().format("H:mm");
      }

      var event = angular.copy($scope.event);

      delete(event.start_date);

      console.log(event);
    }
  };

  // Date selector.
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

  $scope.format = 'dd/MM/yyyy';


  // Time picker.
  $scope.mytime = new Date();

  $scope.hstep = 1;
  $scope.mstep = 1;

  $scope.ismeridian = true;
  $scope.toggleMode = function() {
    $scope.ismeridian = ! $scope.ismeridian;
  };

  $scope.update = function() {
    var d = new Date();
    d.setHours( 14 );
    d.setMinutes( 0 );
    $scope.mytime = d;
  };

  $scope.changed = function () {
    $log.log('Time changed to: ' + $scope.mytime);
  };

  $scope.clear = function() {
    $scope.mytime = null;
  };

});
