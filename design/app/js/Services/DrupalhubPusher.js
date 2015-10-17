DrupalHub.factory('DrupalHubPusher', function ($pusher, Config) {
  var client = new Pusher(Config.pusher_key);
  var pusher = $pusher(client);
  pusher.subscribe(Config.pusher_channel);

  return pusher;
});
