angular.module('DrupalHubConfig', [])

.constant('Config', {backend:'http://localhost/drupalhub/www/api/',debugUiRouter:true})

.value('debug', true)

;