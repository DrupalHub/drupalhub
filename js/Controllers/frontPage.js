DrupalHub.controller('frontPage', function($scope, DrupalHubRequest) {

  $scope.assets = {
    question: {},
    blog: {},
    videos: {},
    events: {}
  };
  $scope.waiting = true;

  DrupalHubRequest.localRequest('get', 'front_page').
    success(function(data) {
      var content = data.data;

      $scope.assets.question = content.question[0];
      $scope.assets.blog = content.blog[0];
      $scope.assets.videos = content.videos[0];
      $scope.assets.events = content.events[0];

      $scope.waiting = false;

      DrupalHubRequest.userAccess(['create question content', 'create blog content']).then(function(data) {
        $scope.addBlog = data.data.data['create_blog_content'];
        $scope.addQuestion = data.data.data['create_question_content'];
      });
    });
});
